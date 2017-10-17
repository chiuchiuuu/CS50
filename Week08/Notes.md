# Notes

## Python Basic

Basic syntax of python: function, variable, condition ...

`argv[0]` -> `sys.argv[0]`

 python interpreter: source code -> byte code

### hello.py

```python
def main():
  print("hello, world")
  
if __name__ == "__main__":
  main()
```

### format

```python
print("x is ", end="")
print("y is ", end="")
print("{} plus {} is {}".format(x, y, x + y))
```

### ascii

`chr()`

### argv

```python
import sys

if len(sys.argv) == 2:
  print("hello, " + sys.argv[1])
```

```python
argc = len(sys.argv)
```

### exit

```python
exit(0)
exit(1)
...
```

### file manipulation

```python
import csv

file = open("students.csv", "w")
writer = csv.writer(file)  # writer is a class
for studnet in students:
  writer.writerow((student.name, student.dorm))
file.close()
```

## Web-based programming

### MVC

MVC, Model View Controller is a design pattern to design web-based software.

- Controller: main part
- View: webpage layout
- Model: Database, etc



local host address: 127.0.0.0