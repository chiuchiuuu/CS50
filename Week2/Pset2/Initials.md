# Initials

## [tl;dr](http://docs.cs50.net/problems/initials/more/initials.html#tl-dr)

Implement a program that, given a person’s name, prints a person’s initials, per the below.

```
$ ./initials
Regulus Arcturus Black
RAB
```

## [Specification](http://docs.cs50.net/problems/initials/more/initials.html#specification)

Design and implement a program, `initials`, that, given a person’s name, prints a person’s initials.

- Implement your program in a file called `initials.c` in a directory called `initials`.
- Your program should prompt a user for their name using `get_string` to obtain their name as a `string`.
- You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus spaces. You don’t need to worry about names like `Joseph Gordon-Levitt`, `Conan O’Brien`, or `David J. Malan`!
- But the user’s input might be sloppy, in which case there might be one or more spaces at the start and/or end of the user’s input or even multiple spaces in a row.
- Your program should print the user’s initials (i.e., the first letter of each word in their name) with no spaces or periods, followed by a newline (`\n`).

## [Usage](http://docs.cs50.net/problems/initials/more/initials.html#usage)

Your program should behave per the examples below. Assumed that the underlined text is what some user has typed.

```
$ ./initials
Zamyla Chan
ZC
$ ./initials
   robert   thomas bowden
RTB
```