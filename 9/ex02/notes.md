https://github.com/nerraou/Ford-Johnson-algorithm


1. Pair & Sort

    * Form pairs where First > Second
    * Set aside unpaired element (sorted last)

    # Example
    Input: 7, 8, 27, 100, 11, 46, 2, 53, 0

    Pairs    : (8,7) (100,27) (46,11) (53,2)
    Unpaired : 0 (set to -1 if all are paired)

==============================================================================================
2. Merge Sort Pair

    * Recursively sort pairs by their First (large) pair  

    # Example
    Before: (8,7) (100,27) (46,11) (53,2)  
    After : (8,7) (46,11) (53,2) (100,27)

==============================================================================================
3. Split pairs

    * Clear original container  

    Original: Push First pair (already sorted)  
    8, 46, 53, 100  

    Insert: Push Second pair  
    7, 11, 2, 27 

==============================================================================================
4. Generate insertion sequence

    This sequence indicates which index from the Insert container should be selected
    Then insert it into the original container (Main chain) 
    The sequence is based on a modified Jacobsthal number 

    Insert size: 4
    Jacobsthal: 1, 3, 5, 11, 21, 43  
    Insertion (< 4): 1 0 3 2  

    Alternate case (< 5): 1 0 3 2 5 4 → 5 out of bound → 1 0 3 2 4

==============================================================================================
5. Binary Insertion Sort

    Use insertion sequence to select number from Insert container 
    Then apply binary search to find the insertion location in original container (Main chain)
    Perform insert operation (method provide by container)

    Insert sequence: 1  0 3  2
    Insert         : 7 11 2 27 

    => 8, 11, 46, 53, 100
    => 7, 8, 11, 46, 53, 100
    => 7, 8, 11, 27, 46, 53, 100
    => 2, 7, 8, 11, 27, 46, 53, 100 

    Final step: Insert unpaired number (also using binary search)
    => 0, 2, 7, 8, 11, 27, 46, 53, 100 

==============================================================================================

Use std::deque if:
------------------
    - You need frequent insertions at both front and back.
    - You need random access but also moderate middle insertions.

Use std::list if:
------------------
    - You need frequent middle insertions/deletions and can work with iterators.
    - You don’t need random access (no [] operator)

Use std::vector if:
------------------
    - You mostly need fast random access and back insertions.
    - Your data is small/medium-sized (cache efficiency matters).



==============================================================================================


Common method
------------------
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
-----------------------
operator[]	Direct element access (no bounds checking)
at()	Access with bounds checking
data()	Get pointer to underlying array
capacity()	Number of elements that can be held without resize
reserve()	Reserve storage
shrink_to_fit()	Reduce capacity to fit size (C++11)
resize()	Change size of the vector

deque-Specific Methods
-----------------------
operator[]	  Direct element access
at()	      Access with bounds checking
push_front() / pop_front()	Add/remove elements at front
resize()	   Change size

list-Specific Methods
-----------------------
push_front() / pop_front()	Add/remove from front
resize()	Resize list
remove()	Remove elements with specific value
remove_if()	Remove based on condition (C++11)
unique()	Remove consecutive duplicates
merge()	Merge sorted lists
sort()	Sort the list
reverse()	Reverse the list
splice()	Transfer elements from another list