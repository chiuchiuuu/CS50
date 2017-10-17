## Hexadecimal

- **hexadecimal system** is much more concise way to express the data on a computers's system
- prefix : 0x
- place values: power of 16
- convert binary to hexadecimal: group four binary digits together from right to left



pointer

- pointer provide an alternative way to pass data between functions
  - pass the actual variable itself by address

> Memory
>
> - Every file on computer lives on disk drive, HDD or SSD
> - Disk drives are just storage space; we can't directly work there. Manipulation and use of data can only take place in RAM, so we have to move data there
> - Memory is basically a huge array of 8-bit wide bytes 
> - Every location in memory has an address (usually represented by hexadecimal number)

**Pointer is nothing more than an address**

- A pointer is a data item whose 

  - value is a memory address
  - type describes the data located at that memory address

- pointer allow data structures and/or variables to be shared among functions

- The simplest pointer available to us in C is the **NULL** pointer

  - **NULL** points to nothing
  - when create a pointer without setting value immediately, we should **always** set the value to NULL
  - can compare using "=="

- `&`: address extraction operator

  - extract the address of an already existing variable

- An array's name is a pointer to its first element

- The main purpose of a pointer is to allow us to modify or inspect the location to which it points

  - we do this by **dereferencing** the pointer 
  - `*`: dereference operator
  - dereference a pointer whose value is NULL will get `Segmentation fault`

- notice that * is both type name and the variable name

  so declare `int *pa, *pb, *pc` instead of `int* px, py, pz;` 



> Difference between 32-bits system and 64-bits system
>
> 32-bits and 64-bits is the size of memory address



## Dynamic Memory Allocation

- usually memory is allocated in compile time, however, we can use pointers to get access to a block of **dynamically allocated memory** at runtime.

- Dynamically allocated memory comes from a pool of memory known as the **heap**.

- we get this dynamically-allocated memory by making a call to the C standard library function `malloc()`

  - parameter: the number of **bytes** requested.
  - return: pointer to that memory(if obtain) or NULL(if fail)

  ```c
  #include <stdlib.h>
  // statically obtain an integer
  int x;

  // dynamically obtain an integer
  int *px = malloc(sizeof(int));

  // array of floats on the heap
  float *heap_array = malloc(x * sizeof（float));
  ```

- danger

  - Dynamically-allocated memory is not automatically returned to the system for later use when the function in which it's created finishes execution.

  - **Memory leak**: failing to return memory back to the system when you're finished with it.

  - to deal with this: use `free()`

    ```c
    char *word = malloc(50 * sizeof(char));

    free(word);
    ```

- Three golden rules:

  - Every block of memory that you `malloc()` must subsequently be `free()`
  - Only memory that you `malloc()` should be `free()`
  - Do not `free()` a block of memory more than once



## Structure

- Why structure?

  - Structure provide a way to unify several variables of different types into a single, new variable type which can be assigned its own type name.
  - we use structures to group together elements of a variety of data types that have a logical connection.
  - Think of a structure like a "**super-variable**", a variable that contains other variables.

- definition

  ```c
  struct car
  {
    //fields(a.k.a members)
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
  };

  //variable declaration
  struct car mycar;

  // field accessing
  mycar.year = 2011;
  mycar.plate = "CS50";
  ...
  ```

  - usually define structure in separate .h files or atop program outside of any functions
  - access fields with `.` operator

- We can **dynamically allocate structures** at run time if our program requires it.

  ```c
  // variable declaration
  struct car *mycar = malloc(sizeof(struct car));

  // field accessing
  (*mycar).year = 2011;
  (*mycar).plate = "CS50";
  ...
  ```

  the arrow operator `->` makes this process easier.

  - first, dereference the pointer on the left side
  - second, access the field on the right side

  ```c
  //field accessing
  mycar->year = 2011;
  mycar->plate = "CS50";
  ...
  ```

  ​

## Defining Custom Types

- The C keyword `typedef` provides a way to create a shorthand or rewritten name for data types.

  ```c
  typedef <old name> <new name>;
  ```

- `typedef` with `structure`

  ```c
  struct car
  {
    ...
  };

  typedef struct car car_t;
  ```

  ```c
  typedef struct car
  {
    ...
  }
  car_t;
  ```



## Recursion

- The definition of a recursive function is one that, as part of its execution, invokes itself.

- Every recursive function has two cases that could apply, given any input

  - The _base case_, which when triggered will terminate the recursive process
  - The _recursive case_, which is where the recursion will actually occur

- In general, but not always, recursive functions replace loops in non-recursive functions

- Multiple base cases: Fibonacci

- Multiple recursive cases: The Collatz conjecture

  > The Collatz conjecture is applies to positive integers and speculates that it is always possible to get "back to 1" if you follow these setps:
  >
  > 1. if n is 1, stop
  > 2. otherwise, if n is even, repeat this process on n/2
  > 3. otherwise, if n is odd, repeat this process on 3n+1
  >
  > write a recursive function `collatz(n)` that calculates how many steps it takes  to get to 1 if you start from n and recurse as indicated above



## Call Stack

**Stack frames** or **function frames**: chunks of memory that system sets aside when calling a function.

- These frames are arranged in a **stack**. The frame for the most-recently called function is always on the top of the stack
- When a new function is called, a new frame is **pushed** onto the top of the stack and becomes the active frame
- when a function finishes its work, its frame is **popped** off of the stack, and the frame immediately below it becomes the new, active, function on the top of the stack. This function picks up immediately where it left off



## File Pointers

The abstraction of files that C provides is implemented in a data structure known as a `FILE`

- almost universally when working with files, we will be using pointers to them, `FILE *`

The file manipulation functions all live in `stdio.h`, all of them accept `FILE *` as one of their parameters, except for the function `fopen()`, which is used to get a file pointer in the first place.

#### Some of the most common file I/O functions:

- `fopen()`

  - opens a file and returns a file pointer to it
  - always **check the return value** to make sure you don't get back NULL

  ```c
  File *ptr = fopen(<filename>, <operation>);
  // "r": read
  // "w": write (overwrite if file exists)
  // "a": append (go to the end of file if exists)
  ```

- `fclose()`

  - closes the file pointed to by the given file pointer

  ```c
  fclose(<file pointer>);
  ```

- `fgetc()` (c stands for character)

  - Reads and returns the next character from the file pointed to
  - The operation of the file pointer passed in as a parameter must be "r" for read, or you will suffer an error

  ```c
  char ch = fgetc(<file pointer>);
  ```

- `fputc()`

  - Writes or appends the specified character to pointed-to file.
  - The operation of the file pointer passed in as a parameter must be "w" for write or "a” for append, or you will suffer an error.

  ```c
  fputc(<character>, <file pointer>);
  ```

- `fread()`

  - Reads `<qty>` units of size `<size>` from the file pointed to and stores them in memory in a buffer (usually an array) pointed to by `<buffer>`
  - The operation of the file pointer passed in as a parameter must be "r" for read, or you will suffer an error

  ```c
  fread(<buffer>, <size>, <qty>, <file pointer>);
  ```

  ```c
  // Example 1
  int arr[10];
  fread(arr, sizeof(int), 10, ptr);

  // Example 2
  double *arr2 = malloc(sizeof(double) * 80);
  fread(arr2, sizeof(double), 80, ptr);

  // Example 3 (equal to fgetc())
  char c;
  fread(&c, sizeof(char), 1, ptr);
  ```

- `fwrite()`

  - writes `<qtr>` units of size `<size>` to the file pointed to by reading them from a buffer (usually  an array) pointed to by `<buffer>`
  - The operation of the file pointer passed in as a parameter must be "w" for write or "a" for append, or you will suffer an error.

  ```c
  fwrite(<buffer>, <size>, <qty>, <file pointer>);
  ```

>  Read and print a file
>
>  ```c
>  // linux `cat` command
>  char ch;
>  while(*ch = fgetc(ptr)) != EOF)
>  {
>   printf("%c", ch);
>  }
>  // EOF is a special value that's defined in standard io.h, which is the end of file character. 
>  ```

> Copy one file to another
>
> ```c
> char ch;
> while ((ch = fgetc(ptr)) != EOF)
> {
>   fputc(ch, ptr2);
> }
> ```

Lots of other useful functions abound in `stdio.h` for you to work with .

|  Function   | Description                              |
| :---------: | :--------------------------------------- |
|  `fgets()`  | Reads a full string from a file.         |
|  `fputs()`  | Writes a ful string to a file.           |
| `fprintf()` | Writes a formatted string to a file.     |
|  `fseek()`  | Allows you rewind or fast-forward within a file. |
|  `ftell()`  | Tells you at what (byte) position you are at within a file. |
|  `feof()`   | Tells you whether you've read to the end of a file. |
| `ferror()`  | Indicates whether an error has occurred in working with a file. |

 