# Notes

Flask is a framework for python to build web-based app.

## SQL

SQL, Structured Query Language.

SQLite, small scale database

SQL database has the ability of **CRUB**, create, read, update, delete data.

SQL table

- Field
- Type
- Primary Key: the field whose values uniquely identify all of the rows in database
- Autoincrement
- Not NULL
- Default Value

### SQL Command

CRESTE

```sql
CREATE TABLE 'registrants' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 'name' TEXT NOT NULL, 'dorm' TEXT NOT NULL)
```

INSERT

```sql
INSERT INTO "registrants" ("name","dorm") VALUES('David', 'Matthews')
```

SELECT

```sql
SELECT * FROM registrants
```

UPDATE

```sql
UPDATE registrants SET dorm = 'Grays' WHERE name = 'Zamyla'
```

DELETE

```sql
DELETE FROM registrants WHERE name = 'Rob'
```

...

### SQL built-ins

function:

```sql
date
time
datetime
...
```

special type of index:

```sql
PRIMARY KEY
UNIQUE (email...)
INDEX
NOT NULL
FOREIGN KEY
...
```

### Joining Tables

```sql
SELECT * FROM users JOIN zipcodes ON user.zipcode = zipcodes.id
```

### index

```sql
CREATE UNIQUE INDEX 'email' ON "users"("email")
```

### SQL lite

```sql lite
sqlite3 file.db
```

```sql lite
sqlite> .help
sqlite> .tables
sqlite> .schema
```

## ORM

`Flask-SQLAlchemy`

ORM, Object Relational Mapper

- using object to represent a row (without writing raw SQL queries)
- higher level

```python
from flask_sqlalchemy import SQLAlchemy

# Flask-SQLAlchemy
app.config["SQLALCHEMY_TRACK-MODIFICATIONS"] = False
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///froshims3.db
app.config["SQLALCHEMY_ECHO"] = True
db = SQLAlchemy(app)

class Registrant(db.Model):
  __tablename__ = 'registrants'
  id = db.Column(db.Integer, primary_key=True)
  name = db.Column(db.Text)
  dorm = db.Column(db.Text)
  
  def __init__(self, name, dorm):
    self.name = name
    self.dorm = dorm
```

## SQL Injection Attacks

```sql
SELECT * FROM users WHERE username = 'me@examplemailprovider.com' AND password = '' OR '1' = '1'
```

fix:

```sql
SELECT * FROM users
WHERE username = 'me@examplemailprovider.com' AND password = '\' OR \'1\' = \'1'
```

