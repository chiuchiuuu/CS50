computational complexity

- **worst-case scenario**: $O()$
- base-case scenario: $\Omega()$
- we can measure an algorithm based on how it handles inputs



bubble sort

- pseudocode:

  ```
  set swap counter to a non-zero value
  repeat until the swap counter is 0
  	reset swap counter to 0
  	look at each adjacent pair
  		if two adjacent elements are not in order
  			swap them
  			add one to the swap counter
  ```

- computational complexity

  - $O(n)$, $\Omega(n)$



selection sort

- pseudocode

  ```
  repeat until no unsorted elements remian:
  	search the unsorted part of the data to find the smallest value
  	swap the smallest found value with the first element of the unsorted part
  ```

- computational complexity

  - $O(n^2)$, $\Omega(n^2)$



insertion sort

- pseudocode

  ```
  call the first element of the array "sorted"
  repeat until all elements are sorted:
  	look at the next unsorted element
  	insert into the "sorted portion by shifting the requisite number of elements
  ```

- $O(n^2)$, $\Omega(n)$



Merge Sort

- pseudocode

  ```
  if n < 2:
  	return
  else
  	sort left half of elements
  	sort right half of elements
  	merge sorted halves
  ```

- $O(nlog(n))$, $\Omega(nlog(n))$



linear search

- pseudocode

  ```
  repeat, starting at the first element:
  	if the first is what you're looking for
  		stop
  	else
  		move to the next element
  ```

- $O(n)$,  $O(1)$





Binary Search

- pseudocode
- $O(log(n))$, $\Omega(1)$







