#include <iostream>
#include <vector>
#include "Queue.h"
#include "RecursionFunctions.h"

void testQueueFunctions(const std::vector<int>& values) {
    Queue<int> q;

    // Load the queue with user-provided values
    std::cout << "Pushing elements onto the queue.\n";
    for (int value : values) {
        q.push(value);
    }

    // Display queue size
    std::cout << "Queue size after pushing elements: " << q.size() << "\n";

    // Display elements using front() and pop()
    std::cout << "Queue contents (FIFO): ";
    Queue<int> tempQ = q; // temporary copy to retain the original queue
    while (!tempQ.empty()) {
        std::cout << tempQ.front() << " ";
        tempQ.pop();
    }
    std::cout << "\n";

    // Move the front element to the rear and display again
    std::cout << "Moving the front element to the rear.\n";
    q.move_to_rear();

    // Display contents after move_to_rear
    std::cout << "Queue contents after move_to_rear: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

void testRecursiveSearch(const std::vector<int>& values) {
    int target;
    std::cout << "Enter the target number to search for: ";
    std::cin >> target;

    std::cout << "Vector contents: ";
    for (int num : values) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    int lastIndex = recursiveLinearSearch(values, target);
    if (lastIndex != -1) {
        std::cout << "Last occurrence of " << target << " is at index: " << lastIndex << "\n";
    }
    else {
        std::cout << target << " not found in the vector.\n";
    }
}

void testInsertionSort(std::vector<int> values) {
    std::cout << "Vector before sorting: ";
    for (int num : values) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    insertionSortRecursive(values, values.size());

    std::cout << "Vector after recursive insertion sort: ";
    for (int num : values) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    int choice;
    std::vector<int> values;

    std::cout << "Enter 10 integers (type -1 to end input early):\n";
    for (int i = 0; i < 10; ++i) {
        int input;
        std::cin >> input;
        if (input == -1) break;
        values.push_back(input);
    }

    do {
        std::cout << "\nSelect a functionality to test:\n";
        std::cout << "1. Queue Operations\n";
        std::cout << "2. Recursive Search\n";
        std::cout << "3. Recursive Insertion Sort\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nTesting Queue Functions:\n";
            testQueueFunctions(values);
            break;
        case 2:
            std::cout << "\nTesting Recursive Search:\n";
            testRecursiveSearch(values);
            break;
        case 3:
            std::cout << "\nTesting Recursive Insertion Sort:\n";
            testInsertionSort(values);
            break;
        case 4:
            std::cout << "Exiting program.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        // Prompt user to return to menu after each test
        std::cout << "\nPress 'y' to return to the main menu or 'n' to exit: ";
        char backToMenu;
        std::cin >> backToMenu;

        if (backToMenu == 'n' || backToMenu == 'N') {
            std::cout << "Exiting program.\n";
            break;
        }

    } while (true);

    return 0;
}
