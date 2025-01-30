// std::map (Key-Value Ordered Dictionary)

// ✅ Pros:
// Sorted keys (ascending order by default)
// Efficient insert(), erase(), find() (O(log n))
// No duplicate keys allowed

// ❌ Cons:
// Slower than unordered_map for lookup (O(log n))
// More memory usage (tree structure)

// 🔄 Iteration:
std::map<int, std::string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};

// Range-based for loop
for (const auto& [key, value] : m) 
    std::cout << key << " -> " << value << std::endl;

// Iterator
for (auto it = m.begin(); it != m.end(); ++it)
    std::cout << it->first << " -> " << it->second << std::endl;

// 🔹 Good to Know:
// Uses Red-Black Tree internally.
// Use std::unordered_map if order is not required (O(1) lookup instead of O(log n)).