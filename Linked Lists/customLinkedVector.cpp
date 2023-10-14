#include <iostream>
#include <unordered_map>
using namespace std;

template <class T>
class customNode
{
public:
    T value;
    customNode<T> *nextNode;
    customNode<T> *prevNode;

    customNode(T val) : value(val), prevNode(nullptr), nextNode(nullptr) {}
};

template <class T>
class customVector
{
private:
    int listSize;
    customNode<T> *reverse_list(customNode<T> *head)
    {
        if (!head || !(head->nextNode))
        {
            // The list is empty or has only one element; no need to reverse
            return head;
        }

        customNode<T> *current = head;
        customNode<T> *nextNode = nullptr;
        customNode<T> *prevNode = nullptr;

        while (current)
        {
            nextNode = current->nextNode; // Save the next node
            current->nextNode = prevNode; // Reverse the next pointer
            current->prevNode = nextNode; // Reverse the prev pointer
            prevNode = current;           // Move to the next node
            current = nextNode;
        }

        // The new head of the reversed list is where 'prevNode' points
        return prevNode;
    }

public:
    customNode<T> *head;
    customNode<T> *tail;

    customVector() : head(nullptr), tail(nullptr), listSize(0) {}

    void pushfront(T value)
    {
        if (!head)
        {
            head = new customNode<T>(value);
            tail = head;
            listSize++;
        }
        else
        {
            customNode<T> *newNode = new customNode<T>(value);
            head->prevNode = newNode;
            newNode->nextNode = head;
            head = newNode;
            listSize++;
        }
    }

    void pushback(T value)
    {
        if (!tail)
        {
            head = new customNode<T>(value);
            tail = head;
            listSize++;
        }
        else
        {
            customNode<T> *newNode = new customNode<T>(value);
            tail->nextNode = newNode;
            newNode->prevNode = tail;
            tail = newNode;
            listSize++;
        }
    }
    T pop_front()
    {
        try
        {
            if (!head)
            {
                throw std::runtime_error("List is Empty you retard");
            }
            customNode<T> *poppedNode = head;
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->nextNode;
                head->prevNode = nullptr;
            }

            T poppedValue = poppedNode->value;
            delete poppedNode;
            listSize--;
            return poppedValue;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }
    T pop_back()
    {
        try
        {
            if (!head)
            {
                throw std::runtime_error("List is Empty you retard");
            }
            customNode<T> *poppedNode = tail;
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail = tail->prevNode;
                tail->nextNode = nullptr;
            }
            T poppedValue = poppedNode->value;
            delete poppedNode;
            listSize--;
            return poppedValue;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }
    bool empty()
    {
        return head == nullptr;
    }
    int size()
    {
        return listSize;
    }
    T front()
    {
        try
        {
            if (!head)
            {
                throw std::runtime_error("List is Empty you retard");
            }
            return head->value;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }
    T back()
    {
        try
        {
            if (!head)
            {
                throw std::runtime_error("List is Empty you retard");
            }
            return tail->value;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }
    T value_at(int index)
    {
        try
        {
            if (!head)
            {
                throw std::runtime_error("List is empty. Cannot retrieve value at index.");
            }

            if (index < 0)
            {
                throw std::runtime_error("Index cannot be negative.");
            }
            if (index >= listSize)
            {
                throw std::runtime_error("Index is out of range.");
            }

            customNode<T> *current = head;
            int i = 0;

            while (current && i < index)
            {
                current = current->nextNode;
                i++;
            }

            return current->value;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }
    void insert(int index, T value)
    {
        try
        {
            if (index < 0)
            {
                throw std::runtime_error("Index cannot be negative.");
            }

            if (index > listSize)
            {
                throw std::runtime_error("Index is out of range.");
            }

            customNode<T> *newNode = new customNode<T>(value);

            if (index == 0)
            {
                pushfront(value);
            }
            else if (index == listSize)
            {
                pushback(value);
            }
            else
            {
                customNode<T> *current = head;
                int i = 0;
                while (current && i < index)
                {
                    current = current->nextNode;
                    i++;
                }
                newNode->nextNode = current;
                newNode->prevNode = current->prevNode;
                current->prevNode->nextNode = newNode;
                current->prevNode = newNode;
                listSize++;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    T erase(int index)
    {
        try
        {
            if (index < 0)
            {
                throw std::runtime_error("Index cannot be negative.");
            }

            if (index >= listSize)
            {
                throw std::runtime_error("Index is out of range.");
            }

            customNode<T> *current = head;
            int i = 0;

            while (current && i < index)
            {
                current = current->nextNode;
                i++;
            }

            // If the element to be removed is the head
            if (current == head)
            {
                head = current->nextNode;
                if (head)
                {
                    head->prevNode = nullptr;
                }
            }
            else
            {
                current->prevNode->nextNode = current->nextNode;
            }

            // If the element to be removed is the tail
            if (current == tail)
            {
                tail = current->prevNode;
                if (tail)
                {
                    tail->nextNode = nullptr;
                }
            }
            else
            {
                current->nextNode->prevNode = current->prevNode;
            }

            T value = current->value;
            delete current;
            listSize--;

            return value;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }

    T value_n_from_end(int index)
    {
        if (index < 0 || index >= listSize)
        {
            std::cerr << "Invalid index." << '\n';
            return -1;
        }

        int updated_index = listSize - index - 1; // indexes start at zero always even in back case
        return value_at(updated_index);
    }
    void remove_value(T value)
    {
        if (!head)
        {
            std::cerr << "List is empty. Cannot remove value." << '\n';
            return;
        }

        customNode<T> *current = head;
        int index = 0;
        while (current)
        {
            if (current->value == value)
            {
                erase(index);
                return;
            }
            current = current->nextNode;
            index++;
        }

        // Value not found
        std::cerr << "Value not found in the list." << '\n';
    }
    void remove_all_value(T value)
    {
        if (!head)
        {
            std::cerr << "List is empty. Cannot remove value." << '\n';
            return;
        }

        customNode<T> *current = head;
        int index = 0;
        bool valueFound = false;

        while (current)
        {
            if (current->value == value)
            {
                customNode<T> *nextNode = current->nextNode; // Save the next node
                erase(index);                                // Remove the current node
                current = nextNode;                          // Update current to the next node
                valueFound = true;
            }
            else
            {
                current = current->nextNode;
                index++;
            }
        }

        if (!valueFound)
        {
            std::cerr << "Value not found in the list." << '\n';
        }
    }

    void reverse()
    {
        head = reverse_list(head);
    }
    void print() const
    {
        customNode<T> *current = head;

        while (current)
        {
            std::cout << current->value << " ";
            current = current->nextNode;
        }

        std::cout << std::endl;
    }
};
int main()
{
    customVector<int> list;

    // Test pushback and pushfront
    list.pushback(3);
    list.pushback(4);
    list.pushfront(2);
    list.pushfront(1);

    std::cout << "Test 1: Push elements to the front and back\n";
    list.print();

    // Test pop_front and pop_back
    list.pop_front();
    list.pop_back();

    std::cout << "Test 2: Pop elements from front and back\n";
    list.print();

    // Test front and back
    std::cout << "Test 3: Front element: " << list.front() << ", Back element: " << list.back() << '\n';

    // Test size
    std::cout << "Test 4: List size: " << list.size() << '\n';

    // Test erase
    list.erase(1);

    std::cout << "Test 5: Erase element at index 1\n";
    list.print();

    // Test insert
    list.insert(1, 7);

    std::cout << "Test 6: Insert element 7 at index 1\n";
    list.print();

    // Test remove_value
    list.remove_value(4);

    std::cout << "Test 7: Remove value 4\n";
    list.print();

    // Test remove_all_value
    list.pushback(3);
    list.pushback(3);
    list.remove_all_value(3);

    std::cout << "Test 8: Remove all occurrences of value 3\n";
    list.print();

    // Test reverse
    list.reverse();

    std::cout << "Test 9: Reverse the list\n";
    list.print();

    // Test value_at
    std::cout << "Test 10: Value at index 1: " << list.value_at(1) << '\n';

    // Test value_n_from_end
    std::cout << "Test 11: Value 2 from the end: " << list.value_n_from_end(2) << '\n';

    return 0;
}
