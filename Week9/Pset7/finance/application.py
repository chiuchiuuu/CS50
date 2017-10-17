from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():

    rows = db.execute("SELECT symbol, sum(share), price FROM purchase " +
            "GROUP BY symbol HAVING user_id=:user_id and sum(share) != 0",
            user_id=session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id=:user_id", user_id=session["user_id"])[0]["cash"]
    total = cash

    if rows:
        for row in rows:
            row["total"] = row["sum(share)"] * row["price"]
            total = total + row["total"]

    return render_template("index.html", rows=rows, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""

    if request.method == "POST":

        # ensure symbol and share were provided
        if not request.form.get("symbol"):
            return apology("must provide symbol")
        elif not lookup(request.form.get("symbol")):
            return apology("Invalid symbol")
        elif not request.form.get("share"):
            return apology("must provide share")

        symbol = lookup(request.form.get("symbol"))
        try:
            share = float(request.form.get("share"))
        except ValueError:
            return apology("invalid share")

        # retrive data from database table user
        rows = db.execute("SELECT * FROM users WHERE id=:user_id", user_id=session["user_id"])
        if not rows:
            return apology("retrive data failed")
        cash = rows[0]["cash"]
        # ensure enough cash
        if symbol["price"] * share > cash:
            return apology("can't afford")
        else:
            cash -= (symbol["price"] * share)
            db.execute("INSERT INTO purchase (user_id, symbol, share, price) VALUES (:user_id, :symbol, :share, :price)",
                        user_id=rows[0]["id"], symbol=symbol["symbol"], share=share, price=symbol["price"])
            db.execute("UPDATE users SET cash = :cash WHERE id = :user_id", cash=cash, user_id=session["user_id"])
            flash("bought!")
            return redirect(url_for("index"))
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions."""

    rows = db.execute("SELECT symbol, share, price, transacted FROM purchase WHERE user_id=:user_id", user_id=session["user_id"])

    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":

        # ensure symbol was provided
        if not request.form.get("symbol"):
            return apology("missing symbol")

        symbol = lookup(request.form.get("symbol"))

        if not symbol:
            return apology("Invalid Symbol")

        return render_template("quoted.html", symbol=symbol)

    # request.method == "GET"
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""

    if request.method == "POST":

        # ensure username & password was submitted
        if not request.form.get("username"):
            return apology("must provide username")
        elif not request.form.get("password"):
            return apology("must provide password")
        elif not request.form.get("confirm_pwd"):
            return apology("must confirm password")

        # ensure username have not been registered
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        if len(rows) != 0:
            return apology("username exists!")

        # ensure password and confirm_pwd are the same
        if request.form.get("password") != request.form.get("confirm_pwd"):
            return apology("confirmed password not consistent!")

        # register user
        db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                    username=request.form.get("username"), hash=pwd_context.hash(request.form.get("password")))

        session["user_id"] = request.form.get("id")

        # redirect user to home page
        flash("Registered!")
        return redirect(url_for("index"))


    # else if user reached route via GET
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():

    if request.method == "POST":

        # ensure symbol and share were provided
        if not request.form.get("symbol"):
            return apology("must provide symbol")
        elif not lookup(request.form.get("symbol")):
            return apology("Invalid symbol")
        elif not request.form.get("share"):
            return apology("must provide share")

        symbol = lookup(request.form.get("symbol"))
        try:
            share = float(request.form.get("share"))
        except ValueError:
            return apology("invalid share")

        # retrive data from database table user
        rows = db.execute("SELECT username, cash, symbol, sum(share), price FROM users JOIN purchase ON users.id=user_id" +
            " GROUP BY symbol HAVING users.id=:user_id and symbol=:symbol",
            user_id=session["user_id"], symbol=symbol["symbol"])
        cash = rows[0]["cash"]
        if not rows:
            return apology("retrive data failed")

        # ensure enough share
        if share > rows[0]["sum(share)"]:
           return apology("too many shares")
        else:
            cash += (symbol["price"] * share)
            db.execute("INSERT INTO purchase (user_id, symbol, share, price) VALUES (:user_id, :symbol, :share, :price)",
                        user_id=session["user_id"], symbol=symbol["symbol"], share=-share, price=symbol["price"])
            db.execute("UPDATE users SET cash = :cash WHERE id = :user_id", cash=cash, user_id=session["user_id"])
            flash("sold!")
            return redirect(url_for("index"))
    else:
        return render_template("sell.html")

@app.route("/profile")
@login_required
def profile():
    rows = db.execute("SELECT * from users WHERE id=:id", id = session["user_id"])
    return render_template("profile.html", rows=rows)

@app.route("/change_password", methods=["GET", "POST"])
@login_required
def change_password():
    """ change user password """

    if request.method == "POST":

        # ensure all password was submitted
        if not request.form.get("old_pw"):
            return apology("must provide old password")
        elif not request.form.get("new_pw"):
            return apology("must provide new password")
        elif not request.form.get("confirmed"):
            return apology("must confirm new password")

        rows = db.execute("SELECT * FROM users WHERE id=:id", id=session["user_id"])

        # ensure old password match
        if not pwd_context.verify(request.form.get("old_pw"), rows[0]["hash"]):
            return apology("old password is wrong!")

        # ensure password and confirm_pwd are the same
        if request.form.get("new_pw") != request.form.get("confirmed"):
            return apology("confirmed password not consistent!")

        # update user password
        db.execute("UPDATE users SET hash=:hash WHERE id=:id",
                    hash=pwd_context.hash(request.form.get("new_pw")), id=session["user_id"])

        flash("Success!")
        return redirect(url_for("profile"))


    # else if user reached route via GET
    else:
        return render_template("change_password.html")