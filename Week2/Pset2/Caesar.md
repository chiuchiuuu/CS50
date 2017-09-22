# Caesar

## [tl;dr](http://docs.cs50.net/problems/caesar/caesar.html#tl-dr)

Implement a program that encrypts messages using Caesar’s cipher, per the below.

```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```

## [Background](http://docs.cs50.net/problems/caesar/caesar.html#background)

Supposedly, Caesar (yes, that Caesar) used to "encrypt" (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to "decrypt" them by shifting letters in the opposite direction by the same number of places.

The secrecy of this "cryptosystem" relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called *plaintext*. Encrypted text is generally called *ciphertext*. And the secret used is called a *key*.

| **plaintext**    | H    | E    | L    | L    | O    |
| ---------------- | ---- | ---- | ---- | ---- | ---- |
| **+ key**        | 1    | 1    | 1    | 1    | 1    |
| **= ciphertext** | I    | F    | M    | M    | P    |

More generally, Caesar’s algorithm (i.e., cipher) encrypts messages by "rotating" each letter by *k* positions. More formally, if *p* is some plaintext (i.e., an unencrypted message), *pi* is the *ith* character in *p*, and *k* is a secret key (i.e., a non-negative integer), then each letter, *ci*, in the ciphertext, *c*, is computed as

ci=(pi+k)mod26ci=(pi+k)mod26

wherein mod26mod26 here means "remainder when dividing by 26." This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely.

## [Specification](http://docs.cs50.net/problems/caesar/caesar.html#specification)

Design and implement a program, `caesar`, that encrypts messages using Caesar’s cipher.

- Implement your program in a file called `caesar.c` in a directory called `caesar`.
- Your program must accept a single command-line argument, a non-negative integer. Let’s call it *k* for the sake of discussion.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` (which tends to signify an error) immediately.
- You can assume that, if a user does provide a command-line argument, it will be a non-negative integer (e.g., `1`). No need to check that it’s indeed numeric.
- Do not assume that *k* will be less than or equal to 26. Your program should work for all non-negative integral values of *k* less than 231- 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for *k* that’s too big or almost too big to fit in an `int`. (Recall that an `int` can overflow.) But, even if *k* is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if *k* is 27, `A` should not become `[`even though `[` is 27 positions away from `A` in ASCII, per [asciichart.com](http://www.asciichart.com/); `A` should become `B`, since `B` is 27 positions away from `A`, provided you wrap around from `Z` to `A`.
- Your program must output `plaintext:` (without a newline) and then prompt the user for a `string` of plaintext (using `get_string`).
- Your program must output `ciphertext:` (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext "rotated" by *k* positions; non-alphabetical characters should be outputted unchanged.
- Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
- After outputting ciphertext, you should print a newline. Your program should then exit by returning `0` from `main`.

## [Usage](http://docs.cs50.net/problems/caesar/caesar.html#usage)

Your program should behave per the examples below. Assumed that the underlined text is what some user has typed.

```
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
```

```
$ ./caesar 13
plaintext:  hello, world
ciphertext: uryyb, jbeyq
```

```
$ ./caesar 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar
$ ./caesar
Usage: ./caesar k
$ ./caesar 1 2 3 4 5
Usage: ./caesar k
```