# Notes

## JavaScript

### Syntax

- function

```javascript
function foo(bar, baz)
{
    ...
}
```

- loops

```javascript
while (true)
{
    ...
}
    
do
{
    ...
}
while (true);
  
for (var i = 0; i < 50; i++)
{
    ...
}

for (var key in object)
{
    ...
}
```

- variable, boolean expression

```javascript
var i = 0;
x < y
```

- condition

```javascript
if ()
{
	
}
else if ()
{
    
}
else
{
    
}
```

- array

```javascript
var numbers = [1, 2, 3];
```

- object

```javascript
var quote = {
    symbol: 'NEFLX', 
    price: 123.30,
};
// JSON should use double quote
```

### Feature

JavaScript can dynamically change the HTML DOM

JavaScript can interact with event model

- click
- mousedown
- mouseup
- mouseover
- drag
- keypress
- load
- unload
- change
- submit
- focus
- touchmove
- ...

#### anonymous functions

don't need name

call once

##### Example

- DOM

```html
<!-- dom1.html -->
<!DOCTYPE html>

<html>
    <head>
        <title>dom1</title>
    </head>
    <body>
        <form id="demo">
            <input id="name" placeholder="Name" type="text"/>
            <input type="submit"/>
        </form>
        <script>

            document.getElementById('demo').onsubmit = function() {
                alert('hello, ' + document.getElementById('name').value + '!');
                return false;
            };

        </script>
    </body>
</html>
```

```html
<!-- dom2.html -->
<!-- introduce jQuery -->

<!DOCTYPE html>

<html>
    <head>
        <script src="https://code.jquery.com/jquery-latest.min.js"></script>
        <script>

            $(document).ready(function() {   // when webpage is all loaded
                $('#demo').submit(function(event) {  // $ jQuery syntax
                    alert('hello, ' + $('#name').val() + '!');
                    event.preventDefault();
                });
            });

        </script>
        <title>dom2</title>
    </head>
    <body>
        <form id="demo">
            <input id="name" placeholder="Name" type="text"/>
            <input type="submit"/>
        </form>
  </body>
</html>
```
- Form

```html
<!-- form1.html -->
<!-- using javascript -->
<!DOCTYPE html>

<html>
    <head>
        <title>form1</title>
    </head>
    <body>
        <form action="/register" id="registration" method="get">
            <input name="email" placeholder="Email" type="text"/>
            <input name="password" placeholder="Password" type="password"/>
            <input name="confirmation" placeholder="Password (again)" type="password"/>
            <input name="agreement" type="checkbox"/> I agree
            <input type="submit" value="Register"/>
        </form>
        <script>

            var form = document.getElementById('registration');
            form.onsubmit = function() {

                if (form.email.value == '')
                {
                    alert('missing email');
                    return false;
                }
                else if (form.password.value == '')
                {
                    alert('missing password');
                    return false;
                }
                else if (form.password.value != form.confirmation.value)
                {
                    alert('passwords don\'t match');
                    return false;
                }
                else if (!form.agreement.checked)
                {
                    alert('checkbox unchecked');
                    return false;
                }
                return true;

            };

        </script>
   </body>
</html>
```

```html
<!-- form2.html -->
<!-- using jQuery -->
    <head>
        <script src="https://code.jquery.com/jquery-latest.min.js"></script>
        <script>

            $(document).ready(function() {

                $('#registration').submit(function() {

                    if ($('#registration input[name=email]').val() == '')
                    {
                        alert('missing email');
                        return false;
                    }
                    else if ($('#registration input[name=password]').val() == '')
                    {
                        alert('missing password');
                        return false;
                    }
                    else if ($('#registration input[name=password]').val() != $('#registration input[name=confirmation]').val()) 
                    {
                        alert('passwords don\'t match');
                        return false;
                    }
                    else if (!$('#registration input[name=agreement]').is(':checked')) 
                    {
                        alert('checkbox unchecked');
                        return false;
                    }
                    return true;

                });

            });

        </script>
	</head>
```

```html
<!-- form3.html -->
<!-- using Bootstrap -->
<!DOCTYPE html>

<html>
    <head>

        <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet"/>
        <script src="https://code.jquery.com/jquery-latest.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

        <!-- http://1000hz.github.io/bootstrap-validator/ -->
        <script src="https://cdnjs.cloudflare.com/ajax/libs/1000hz-bootstrap-validator/0.11.5/validator.min.js"></script>

        <title>form3</title>

    </head>
    <body>
        <div class="container">
            <form action="/register" data-toggle="validator" id="registration" method="get">
                <div class="form-group">
                    <label for="email" class="control-label">Email</label>
                    <input class="form-control" id="email" required type="text"/>
                    <div class="help-block with-errors"></div>
                </div>
                <div class="form-group">
                    <label for="password" class="control-label">Password</label>
                    <input class="form-control" data-minlength="8" id="password" required type="password"/>
                    <div class="help-block with-errors"></div>
                </div>
                <div class="form-group">
                    <label for="confirmation" class="control-label">Password (again)</label>
                    <input class="form-control" data-match="#password" data-match-error="passwords don't match" id="confirmation" required type="password"/>
                    <div class="help-block with-errors"></div>
                </div>
                <div class="form-group">
                    <div class="checkbox">
                        <label>
                            <input data-error="checkbox unchecked" id="agreement" required type="checkbox"/> I agree
                        </label>
                        <div class="help-block with-errors"></div>
                    </div>
                </div>
                <div class="form-group">
                    <button class="btn btn-default" type="submit">Register</button>
                </div>
            </form>
        </div>
    </body>
</html>
```

#### change style

- blink

```html
<script>

  // toggles visibility of greeting
  function blink()
  {
    var div = document.getElementById('greeting');
    if (div.style.visibility == 'hidden')
    {
      div.style.visibility = 'visible';
    }
    else
    {
      div.style.visibility = 'hidden';
    }
  }

  // blink every 500ms
  window.setInterval(blink, 500);

</script>
```

#### store data locally in browser

```html
<!DOCTYPE html>

<html>
    <head>
        <title>storage</title>
    </head>
    <body>
        <script>

            if (!localStorage.getItem('counter')) {
                localStorage.setItem('counter', 0);
            }
            document.write(localStorage.getItem('counter'));
            localStorage.setItem('counter', parseInt(localStorage.getItem('counter')) + 1);

        </script>
    </body>
</html>
```

#### geolocation

```html
<!DOCTYPE html>

<html>
    <head>
        <title>geolocation</title>
    </head>
    <body>
        <script>
        
            navigator.geolocation.getCurrentPosition(function(position) {
                document.write(position.coords.latitude + ', ' + position.coords.longitude);
            });

        </script>
    </body>
</html>
```



#### AJAX

AJAX, asynchronous JavaScript in XML, allow you to query from a browser, a server to get more data without reload the whole page

##### Example

```html

<!DOCTYPE html>

<html>
    <head>
        <script src="https://code.jquery.com/jquery-latest.min.js"></script>
        <script>

            function quote()
            {
                var url = '/quote?symbol=' + $('#symbol').val();
                $.getJSON(url, function(data) {  
                    // $.getJSON means jQuery.getJSON
                    // data is retrived as JSON
                    // html is a method to change value of a variable
                    $('#quote').html('A share of ' + data.name + ' costs $' + data.price + '.');
                    // reset the field
                    $('#symbol').val('');
                });
            }

        </script>
        <title>ajax2</title>
    </head>
    <body>
        <form onsubmit="quote(); return false;">
            <input autocomplete="off" autofocus id="symbol" placeholder="Symbol" type="text"/>
            <input type="submit" value="Get Quote"/>
        </form>
        <p id="quote"></p>
    </body>
</html>
```

JavaScript can reduce work of server and make part of things done on client side, i.e. in browser locally. But it can cause problem in aspects of security check, validation check. For example, JavaScript can be turned off in browser. 

#### callbacks

a function is configured to be called at a certain point in time  when event happen

```html
<!DOCTYPE html>

<html>
    <head>
      	// fill div into whole page
        <style>

            html, body, #map
            {
                height: 100%;
                margin: 0;
            }

        </style>
        <title>map</title>
    </head>
    <body>
        <div id="map"></div>
        <script>

            function initMap() {
                var map = new google.maps.Map(document.getElementById('map'), {
                    center: {lat: 39.833, lng: -98.583},
                    zoom: 4
                });
                var marker = new google.maps.Marker({
                    map: map,
                    position: {lat: 42.3762, lng: -71.1158}
                });
                var marker = new google.maps.Marker({
                    map: map,
                    position: {lat: 41.3104, lng: -72.9289}
                });
            }

        </script>
        <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBKMo-DfSUsW3LvS1C0xxKGOSX2A1HxNx4&callback=initMap"></script>
    </body>
</html>
```

