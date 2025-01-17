#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random tree
void generateTree(int height) {
    int row = 0;
    while (row < height) {
        // Calculate the number of spaces and asterisks for the current row
        int spaces = height - row - 1;
        int stars = row * 2 + 1;

        // Print spaces
        int i = 0;
        while (i < spaces) {
            std::cout << ' ';
            i++;
        }

        // Print stars
        i = 0;
        while (i < stars) {
            std::cout << '*';
            i++;
        }

        std::cout << '\n';
        row++;
    }

    // Print the tree trunk
    int trunkHeight = 2; // You can adjust this as needed
    int trunkRow = 0;
    while (trunkRow < trunkHeight) {
        int i = 0;
        while (i < height - 1) {
            std::cout << ' ';
            i++;
        }
        std::cout << "|\n";
        trunkRow++;
    }
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate multiple random trees
    int treeCount = 5; // Number of trees
    int count = 0;
    while (count < treeCount) {
        int height = 5 + std::rand() % 6; // Random height between 5 and 10
        std::cout << "Tree " << count + 1 << " (Height: " << height << "):\n";
        generateTree(height);
        std::cout << '\n';
        count++;
    }

    return 0;
}
