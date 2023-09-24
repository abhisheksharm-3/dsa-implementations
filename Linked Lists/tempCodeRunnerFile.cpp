#include <iostream>
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
public:
    customNode<T> *head;
    customNode<T> *tail;

    customVector() : head(nullptr), tail(nullptr) {}

    void pushfront(T value)
    {
        if (!head)
        {
            head = new customNode<T>(value);
            tail = head;
        } else {
            customNode<T> * newNode = new customNode<T>(value);
            head->prevNode = newNode;
            newNode->nextNode = head;
            head = newNode;
        }
    }

    void pushback(T value)
    {
        if (!tail)
        {
            head = new customNode<T>(value);
            tail = head;
        } else {
            customNode<T> * newNode = new customNode<T>(value);
            tail->nextNode = newNode;
            newNode->prevNode = tail;
            tail = newNode;
        }
    }
};

int main()
{
    customVector<int> vector;
    vector.pushback(42); // Add an element to the vector

    // Check if the head node is properly assigned
    if (vector.head)
    {
        cout << "Head Node Value: " << vector.head->value << endl;
    }

    return 0;
}
