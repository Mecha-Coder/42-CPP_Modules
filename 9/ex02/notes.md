https://github.com/nerraou/Ford-Johnson-algorithm

Use std::deque if:
==================
- You need frequent insertions at both front and back.
- You need random access but also moderate middle insertions.

Use std::list if:
=================
- You need frequent middle insertions/deletions and can work with iterators.
- You don’t need random access (no [] operator)

Use std::vector if:
==================
- You mostly need fast random access and back insertions.
- Your data is small/medium-sized (cache efficiency matters).


Common method
=============
begin() / end()	   Get iterators to beginning and end
rbegin() / rend()  Reverse iterators to end and beginning
empty()	           Check if container is empty
size()	           Return number of elements
max_size()	       Return maximum possible number of elements
front() / back()   Access first and last elements
push_back() / pop_back()	Add/remove from the end
insert()	      Insert element(s)
erase()	          Erase element(s)
clear()	          Remove all elements
assign()	      Assign values
swap()	         Swap contents with another container

vector-Specific Methods
=======================
operator[]	Direct element access (no bounds checking)
at()	Access with bounds checking
data()	Get pointer to underlying array
capacity()	Number of elements that can be held without resize
reserve()	Reserve storage
shrink_to_fit()	Reduce capacity to fit size (C++11)
resize()	Change size of the vector

deque-Specific Methods
=========================
operator[]	  Direct element access
at()	      Access with bounds checking
push_front() / pop_front()	Add/remove elements at front
resize()	   Change size

list-Specific Methods
=====================
push_front() / pop_front()	Add/remove from front
resize()	Resize list
remove()	Remove elements with specific value
remove_if()	Remove based on condition (C++11)
unique()	Remove consecutive duplicates
merge()	Merge sorted lists
sort()	Sort the list
reverse()	Reverse the list
splice()	Transfer elements from another list