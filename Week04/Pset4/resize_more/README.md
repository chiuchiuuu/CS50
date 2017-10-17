# Resize

## [tl;dr](http://docs.cs50.net/problems/resize/more/resize.html#tl-dr)

Implement a program that resizes BMPs, per the below.

```
$ ./resize .25 large.bmp small.bmp
```

```
$ ./resize 4 small.bmp large.bmp
```

## [Background](http://docs.cs50.net/problems/resize/more/resize.html#background)

Be sure you’re familiar with the structure of 24-bit uncompressed BMPs, as introduced in [Whodunit](http://docs.cs50.net/problems/whodunit/whodunit).

## [Distribution](http://docs.cs50.net/problems/resize/more/resize.html#distribution)

### [Downloading](http://docs.cs50.net/problems/resize/more/resize.html#downloading)

```
$ wget https://github.com/cs50/problems/archive/resize.zip
$ unzip resize.zip
$ rm resize.zip
$ mv problems-resize resize
$ cd resize
$ ls
bmp.h  copy.c  large.bmp  small.bmp  smiley.bmp
```

## [Specification](http://docs.cs50.net/problems/resize/more/resize.html#specification)

Implement a program called `resize` that resizes (i.e., enlarges or shrinks) 24-bit uncompressed BMPs by a factor of `f`.

- Implement your program in a file called `resize.c` in a directory called `resize`.

- Your program should accept exactly three command-line arguments, whereby

  - the first (`f`) must be a floating-point value in (0.0, 100.0],
  - the second must be the name of a BMP to be resized, and
  - the third must be the name of the resized version to be written.

  \+ If your program is not executed with such, it should remind the user of correct usage, as with `fprintf` (to `stderr`), and `main`should return `1`.

- Your program, if it uses `malloc`, must not leak any memory.

## [Usage](http://docs.cs50.net/problems/resize/more/resize.html#usage)

Your program should behave per the examples below. Assumed that the underlined text is what some user has typed.

```
$ ./resize
Usage: ./resize n infile outfile
$ echo $?
1
```

```
$ ./resize .5 large.bmp smaller.bmp
$ echo $?
0
```

```
$ ./resize 2 small.bmp larger.bmp
$ echo $?
0
```

## [Hints](http://docs.cs50.net/problems/resize/more/resize.html#hints)

With a program like this, we could have created `large.bmp` out of `small.bmp` by resizing the latter by a factor of 4 (i.e., by multiplying both its width and its height by 4), per the below.

```
./resize 4 small.bmp large.bmp
```

You’re welcome to get started by copying (yet again) `copy.c` and naming the copy `resize.c`. But spend some time thinking about what it means to resize a BMP, particularly if `f` is in (0.0, 1.0). (You may assume that `n` times the size of `infile` will not exceed 232 - 1. As for a value of `1.0` for `f`, the result should indeed be an `outfile` with dimensions identical to `infile`'s.) How you handle floating-point imprecision and rounding is entirely up to you, as is how you handle inevitable loss of detail. Decide which of the fields in `BITMAPFILEHEADER` and `BITMAPINFOHEADER` you might need to modify. Consider whether or not you’ll need to add or subtract padding to scanlines. And do be sure to support a value of `1` for `n`, the result of which should be an `outfile` with dimensions identical to `infile`'s.

If you happen to use `malloc`, be sure to use `free` so as not to leak memory. Try using `valgrind` to check for any leaks!