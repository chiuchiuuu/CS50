# Lecture Notes

## Limitation of Arrays:

- fixed length, can be solved by `realloc`, but
  - have to copy one by one from original array
  - wasting time

## Lists

we need a struct to contain both data and pointer to next struct, that's what we called node

```c
typedef struct node
{
    int n;
    struct node *next;
}
node;
// recursive struct
```

### Linked Lists:

a new data structure: 

- collection of nodes that linked together
- first pointer
- end pointer (`NULL`)

we need operation: delete, insert, search and so on

- search: $O(n)$, even sorted
- insert: 
  - $O(1)$, if don't care sorted
  - $O(n)$, if keep sorted
- delete: $O(n)$

predecessor pointer



### Implementing search

```c
bool search(int n, node *list)
{
    node *ptr = list;
  	while (ptr != NULL)
    {
        if (ptr->n == n)
        {
            return true;
        }
        ptr = ptr->next;  // spirit of i++
    }
  	return false;
}
```



### Linked List Tradeoffs

- linked list give us dynamism, we can using `malloc` to grow our nodes, or `free` to shrink nodes
- but the operation on linked list are slower



## Stack

A data structure that one data is on top of others

useful when tucking some data away for subsequent use

operations: push, pop, ...

data access principle: LIFO (last in first out)

### Implementing:

```c
typedef struct
{
    int numbers[CAPACITY];
  	int size;
}
stack;
```

```c
typedef struct
{
    int *numbers;  // not fixed
  	int size;
}
stack;
```



## Queues

a data structure that FIFO

operation: enqueue, dequeue, ...

### implement

```c
typedef struct
{
    int front;
  	int numbers[CAPACITY];
  	int size;
}
```

```c
typedef struct
{
    int front;
  	int *numbers;
  	int size;
}
```



## Tree

### basic concept

- root node
- children, parent
- siblings
- leaves

### binary search tree

- every node has no more than 2 child
- every node is greater than left child and less than right child
- it's important to keep tree 'balanced'

### implementing

```c
typedef struct node
{
    int n;
  	struct node *left;
  	struct node *right;
}
node;
```

```c
bool search(int n, node *tree)
{
    if (tree == NULL)
    {
        return false;
    }
  	else if (n < tree->n)
    {
        return (search(n, tree->left));
    }
  	else if (n > tree->n)
    {
        return search(n, tree->right);
    }
  	else
    {
        return false;
    }
}
```



### Huffman Coding

compress text lostlessly

fewer bits for more popular letters and more bits for the less popular letters

compressing

implementing

```c
typedef struct node
{
    char symbol;
  	float frequency;
  	struct node *left;
  	struct node *right;
}
node;
```



## Hash Tables

constant time to search

linear porb



##  Separate Chaining

merging the idea of a hash table and a linked list