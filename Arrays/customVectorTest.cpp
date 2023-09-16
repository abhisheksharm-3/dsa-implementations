#include <iostream>
#include "customVector.cpp"

int main()
{
    customVector<int> vector;

    // Test pushing elements
    vector.pushback(1);
    vector.pushback(2);
    vector.pushback(3);
    vector.pushback(4);
    vector.pushback(5);

    // Test size and capacity
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;

    // Test accessing elements
    std::cout << "Element at index 2: " << vector.at(2) << std::endl;

    // Test popping elements
    int popped = vector.pop();
    std::cout << "Popped element: " << popped << std::endl;

    // Test size and capacity after popping
    std::cout << "Size after pop: " << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;

    // Test finding elements
    int findResult = vector.find(3);
    if (findResult != -1)
        std::cout << "Found 3 at index: " << findResult << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    // Test deleting elements
    int deleted = vector.deletes(1);
    std::cout << "Deleted element at index 1: " << deleted << std::endl;

    // Test removing elements
    vector.remove(4);

    // Test inserting elements
    vector.insert(1, 6);

    // Test prepending elements
    vector.prepend(0);

    // Print the elements in the vector
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
