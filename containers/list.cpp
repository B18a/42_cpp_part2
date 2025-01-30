// std::list (Doubly Linked List)

// ✅ Pros:
// Fast insertions/deletions anywhere (O(1))
// No reallocation or shifting of elements

// ❌ Cons:
// Slow random access (O(n)) – no direct indexing
// Extra memory overhead due to pointers (each node stores two pointers)

// 🔄 Iteration:
std::list<int> lst = {1, 2, 3, 4};
// // Range-based for loop
for (int x : lst) 
    std::cout << x << " ";
// Iterator
for (auto it = lst.begin(); it != lst.end(); ++it)
    std::cout << *it << " ";

// 🔹 Good to Know:
// Use std::list only when frequent insertions/deletions are required and random access isn't needed.
// No [] operator due to non-contiguous storage.
