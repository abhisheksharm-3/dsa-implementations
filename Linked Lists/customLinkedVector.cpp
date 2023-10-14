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
};

int main()
{
    customVector<int> vector;
    vector.pushback(42);
    vector.pushfront(10); // Add an element to the vector

    // Check if the head node is properly assigned
    if (vector.head)
    {
        cout << "Head Node Value: " << vector.head->value << endl;
    }
    cout << vector.pop_back();
    cout << vector.size();

    return 0;
}
