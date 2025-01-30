// std::queue (FIFO Queue)

// ✅ Pros:
// Simple FIFO structure
// Efficient push() and pop() (O(1))

// ❌ Cons:
// No iteration support (must pop() to access elements)
// Only supports front() and back()

// 🔄 Iteration (Using Loop with pop())
std::queue<int> q;
q.push(1); q.push(2); q.push(3);

while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
}

// 🔹 Good to Know:
// Implemented using std::deque by default.
// Cannot directly iterate over elements.