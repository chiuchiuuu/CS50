# Week 3

## Search

Linear search

```
for each element in array
    if element you're looking for
        return true
return false
```

- $O(n)$, $\Omega (1)$

Binary search

```pseudocode
look at middle of array
if element you're looking for
    return true
else if element is to left
    search left half of array
else if element is to right
    search right half of array
else
    return false
```

-  $O(\log n)$, $\Omega (1)$

## Sort

selection sort

```
for i from 0 to n-1
    find smallest element between i'th and n-1'th
    swap smallest with i'th element
```

- Now we’re building a sorted list by going through the unsorted part of the list, finding the smallest element, and placing it at the end of our sorted list.
- $O(n^2)$, $\Omega (n^2)$

bubble sort

```
repeat until no swaps
    for i from 0 to n-2
        if i'th and i+1'th elements out of order
            swap them
```

- Recall that the element at the end of the list is the `n - 1`th since we start counting at `0`. So looking at pairs of elements, the last pair would stop at `n - 2`.
- $O(n^2)$, $\Omega (n)$

insertion sort

```
for i from 1 to n-1
    call 0'th through i-1'th elements the "sorted side"
    remove i'th element
    insert it into the sorted side in order
```

- Here we are building a sorted list by taking each element in the list, and inserting it into the correct spot of the sorted list so far.
- $O(n^2)$, $\Omega (n^2)$

mergesort

```
on input of n elements
    if n < 2
        return
    else
        sort left half of elements
        sort right half of elements
        merge sorted halves
```

- If we have fewer than 2 elements, then our list has to be sorted so we should stop.
- Now we rely on the same function to sort the halves for us, and once it sorts the halves we’ll merge them together.
- $O(n\log n)$

[visualization](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)

## Running time

When comparing running time, we generally just want the term with the **biggest order of magnitude**

Big O $(O)$ is the running time of the worst-case scenario

- $O(n^2)$
- $O(n\log n)$
- $O(n)$
- $O(\log n)$
- $O(1)$

Big Omega $(\Omega)$ is the lower bound, or the best case.

Another notation, theta, $\Theta$, if the running time of an algorithm is the same in the worst-case (Ω) and the best-case (O).