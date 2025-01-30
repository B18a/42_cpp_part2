// std::stack (LIFO Stack)

// ✅ Pros:
// Simple LIFO structure
// Efficient push() and pop() (O(1))

// ❌ Cons:
// No iteration support
// Only top() access (no random access)

// 🔄 Iteration (Using Loop with pop())
std::stack<int> st;
st.push(1); st.push(2); st.push(3);

while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
}

// 🔹 Good to Know:
// Implemented using std::deque by default.
// Ideal for recursive problems, expression evaluation, and backtracking.