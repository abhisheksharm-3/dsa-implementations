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
class customQueue
{
private:
    int queueSize = 0;

public:
    customNode<T> *head;
    customNode<T> *tail;
    customQueue() : head(nullptr), tail(nullptr), queueSize(0) {}

    void enqueue(T val)
    {
        if (!head)
        {
            head = new customNode<T>(val);
            tail = head;
            queueSize++;
        }
        else
        {
            customNode<T> *newNode = new customNode<T>(val);
            tail->nextNode = newNode;
            newNode->prevNode = tail;
            tail = newNode;
            queueSize++;
        }
    }

    T dequeue()
    {
        try
        {
            if (!head)
            {
                throw std::runtime_error("Queue is Empty.");
            }
            customNode<T> *dequeuedNode = head;
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
            T value = dequeuedNode->value;
            delete dequeuedNode;
            queueSize--;
            return value;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }

    bool isEmpty()
    {
        return queueSize == 0;
    }

    int size()
    {
        return queueSize;
    }
};

int main()
{
    customQueue<int> queue;

    // Enqueue some elements
    for (int i = 1; i <= 5; i++)
    {
        queue.enqueue(i);
    }

    cout << "Queue size: " << queue.size() << endl;

    // Dequeue elements and print them
    while (!queue.isEmpty())
    {
        cout << "Dequeue: " << queue.dequeue() << endl;
    }

    cout << "Queue size: " << queue.size() << endl;

    // Try to dequeue from an empty queue
    try
    {
        int val = queue.dequeue();
    }
    catch (const std::exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    // Check if the queue is empty
    if (queue.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    // Enqueue more elements
    for (int i = 6; i <= 10; i++)
    {
        queue.enqueue(i);
    }

    cout << "Queue size: " << queue.size() << endl;

    // Dequeue elements and print them
    while (!queue.isEmpty())
    {
        cout << "Dequeue: " << queue.dequeue() << endl;
    }

    cout << "Queue size: " << queue.size() << endl;

    return 0;
}