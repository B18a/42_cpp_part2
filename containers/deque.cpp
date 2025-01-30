// std::deque (Double-Ended Queue)

// ✅ Pros:
// Fast insertions/deletions at both ends (O(1))
// Efficient for stack/queue-like operations
// No reallocation like std::vector (blocks instead of a single contiguous array)

// ❌ Cons:
// Slower than vector for random access (O(1), but less cache-friendly)
// More complex memory layout (non-contiguous)

// 🔄 Iteration:
std::deque<int> dq = {1, 2, 3, 4};
// Range-based for loop
for (int x : dq) 
    std::cout << x << " ";
// Iterator
for (auto it = dq.begin(); it != dq.end(); ++it)
    std::cout << *it << " ";

// 🔹 Good to Know:
// Use std::deque when both front and back insertions/deletions are required.
// Use push_front() and push_back() efficiently.
