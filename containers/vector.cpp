// std::vector (Dynamic Array)

// ✅ Pros:
// Fast random access (O(1))
// Contiguous memory (cache-friendly)
// Efficient when elements are frequently accessed by index
// Resizable dynamically

// ❌ Cons:
// Expensive insertions/deletions in the middle (O(n))
// Insertions at the end may require reallocation (though amortized O(1))

// 🔄 Iteration:
std::vector<int> vec = {1, 2, 3, 4};
// Range-based for loop
for (int x : vec) 
    std::cout << x << " ";
// Iterator
for (auto it = vec.begin(); it != vec.end(); ++it)
    std::cout << *it << " ";

// 🔹 Good to Know:
// Use reserve(n) if the size is known in advance to avoid unnecessary reallocations.
// push_back() is optimized.
