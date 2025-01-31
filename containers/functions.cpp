Common Functions Across All Containers
begin() / end():

Returns an iterator to the first/last element.
Available in all containers (except std::map, where begin() returns an iterator to the first element in the key-value pair).
empty():

Checks if the container is empty.
Available in all containers.
size():

Returns the number of elements in the container.
Available in all containers.
clear():

Removes all elements.
Available in all containers.
front():

Accesses the first element.
Available in deque, list, queue, stack, vector, and array.
back():

Accesses the last element.
Available in deque, list, stack, vector, and array.


Summary Table
Function	    Array	Vector	Deque	List	Map	    Queue	Stack   Purpose
push_back()	    No	    Yes	    Yes	    No	    No	    No	    Yes     Adds an element to the end of the container.
pop_back()	    No	    Yes	    Yes	    No	    No	    No	    Yes     Removes the last element from the container.
push_front()    No	    No	    Yes	    Yes	    No	    No	    No      Adds an element to the front of the container.
pop_front()	    No	    No	    Yes	    Yes	    No	    No	    No      Removes the first element from the container.
insert()	    No	    No	    No	    Yes	    Yes	    No	    No      Inserts one or more elements at a specific position in the container.
erase()	        No	    No	    No	    Yes	    Yes	    No	    No      Removes one or more elements from a specific position in the container.
begin() / end()	Yes	    Yes	    Yes	    Yes	    Yes	    No	    No      Returns iterators to the first element (begin()) and past the last element (end()).
front()	        Yes	    Yes	    Yes	    Yes	    No	    Yes	    Yes     Returns a reference to the first element.
back()	        Yes	    Yes	    Yes	    Yes	    No	    Yes	    Yes     Returns a reference to the last element.
operator[]	    No	    Yes	    No	    No	    Yes	    No	    No      Provides direct access to elements by index.
find()	        No	    No	    No	    No	    Yes	    No	    No      Searches for an element in the container (in map, it searches by key).
count()	        No	    No	    No	    No	    Yes	    No	    No      Returns the number of elements matching a given key (in map, it is typically 0 or 1).
push()	        No	    No	    No	    No	    No	    Yes	    Yes     Adds an element to the top of the container (only for stack/queue).
pop()	        No	    No	    No	    No	    No	    Yes	    Yes     Removes the top element (for stack/queue).
top()	        No	    No	    No	    No	    No	    No	    Yes     Returns a reference to the top element (only for stack).
lower_bound()	No	    No	    No	    No	    Yes	    No	    No      Finds the first element not less than the given key.
upper_bound()	No	    No	    No	    No	    Yes	    No	    No      Finds the first element greater than the given key.
at()	        No	    Yes	    No	    No	    Yes	    No	    No      Provides bounds-checked access to an element (throws if out of bounds).
data()	        Yes	    No	    No	    No	    No	    No	    No      Returns a pointer to the underlying array (raw memory access).
fill()	        Yes	    No	    No	    No	    No	    No	    No      Fills the container with the same value.


General Guidelines
std::array: Best when you need a fixed-size array that is known at compile time. Provides random access but lacks flexibility compared to other containers.
std::vector: Best for dynamic arrays where you need efficient random access and the ability to resize the container.
std::deque: Similar to std::vector, but optimized for insertions/removals at both ends.
std::list: Best for frequent insertions/removals at both ends or middle (due to doubly linked list structure).
std::map: Best for sorted key-value pairs, with efficient searching by key.
std::queue: Best for FIFO (first in, first out) data structure.
std::stack: Best for LIFO (last in, first out) data structure.

Specific Functions for Each Container
1. std::array (Fixed-size Array)
at():
Provides bounds-checked access to elements (throws an exception if out of bounds).
[] operator:
Provides unchecked access (faster but unsafe).
front():
Accesses the first element.
back():
Accesses the last element.
Unique to Array:
Fixed size: The size is determined at compile time and cannot be changed.
data(): Returns a pointer to the underlying array (to access the raw array).
fill(): Fills the array with a specified value.

2. std::vector
push_back():
Adds an element to the end.
pop_back():
Removes the last element.
resize():
Changes the size of the vector.
at():
Provides bounds-checked access to elements.
[] operator:
Provides unchecked access.
Unique to Vector:
reserve(): Pre-allocates memory to avoid repeated reallocations.
shrink_to_fit(): Reduces the capacity of the vector to fit its size.

3. std::deque (Double-ended Queue)
push_front():
Adds an element at the front.
pop_front():
Removes the first element.
push_back():
Adds an element to the end (like vector).
pop_back():
Removes the last element (like vector).
Unique to Deque:

Allows efficient operations on both ends with O(1) time complexity for push_front/pop_front and push_back/pop_back.
4. std::list (Doubly Linked List)
push_front():
Adds an element at the front.
pop_front():
Removes the first element.
push_back():
Adds an element to the end.
pop_back():
Removes the last element.
Unique to List:
Bidirectional traversal: Unlike vector or deque, list provides more flexible traversal since it’s doubly linked (you can go forward or backward easily).
insert(): Can insert at arbitrary positions (requires iterators).
erase(): Can remove elements at specific positions.

5. std::map (Associative Container - Sorted Key-Value Pairs)
insert():
Inserts a key-value pair.
erase():
Removes a key-value pair.
find():
Finds a key-value pair by key.
count():
Counts occurrences of a key (usually 0 or 1 for maps).
operator[]:
Accesses or inserts an element by key.
begin() / end():
Iterates through the map, where each element is a pair (key, value).
Unique to Map:
lower_bound() / upper_bound(): Finds the first key not less than or greater than a given key, respectively.
at(): Access a key-value pair with bounds checking.

6. std::queue
push():
Adds an element to the back of the queue.
pop():
Removes the front element.
front():
Accesses the front element.
back():
Accesses the last element.
Unique to Queue:
FIFO (First In, First Out) structure: Operations follow FIFO order (push at back, pop from front).
empty() and size() are available but not meant for element access.

7. std::stack
push():
Adds an element to the top of the stack.
pop():
Removes the top element.
top():
Accesses the top element.
Unique to Stack:
LIFO (Last In, First Out) structure: Operations follow LIFO order (push at top, pop from top).
Like a queue, empty() and size() are available but it's meant for accessing and manipulating only the top element.
