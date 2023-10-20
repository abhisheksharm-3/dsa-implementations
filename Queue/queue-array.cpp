#include <iostream>
using namespace std;

template <class T>
class customQueue
{
private:
    int currentSize;
    int currentPos;
    T *customArray;

    void increaseSize()
    {
        T *newCustomArray = new T[currentSize * 2];

        for (int i = 0; i < currentSize; i++)
        {
            newCustomArray[i] = customArray[i];
        }

        currentSize *= 2;
        delete[] customArray;
        customArray = newCustomArray;
    }

    void decreaseSize()
    {
        if (currentPos <= (currentSize / 4) && currentSize > 100)
        {
            currentSize /= 2;
            T *newCustomArray = new T[currentSize];

            for (int i = 0; i < currentPos; i++)
            {
                newCustomArray[i] = customArray[i];
            }

            delete[] customArray;
            customArray = newCustomArray;
        }
    }

public:
    customQueue() : currentSize(100), currentPos(0)
    {
        customArray = new T[currentSize];
    }

    void enqueue(T val)
    {
        if (currentPos == currentSize)
        {
            increaseSize();
        }
        customArray[currentPos] = val;
        currentPos++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is Empty.");
        }
        T value = customArray[0];

        for (int i = 0; i < currentPos - 1; i++)
        {
            customArray[i] = customArray[i + 1];
        }

        currentPos--;

        if (currentPos < currentSize / 4 && currentSize > 100)
        {
            decreaseSize();
        }

        return value;
    }

    bool isEmpty()
    {
        return currentPos == 0;
    }

    int size()
    {
        return currentPos;
    }
};
int main()
{
    customQueue<int> queue;

    for (int i = 1; i <= 20; i++)
    {
        queue.enqueue(i);
    }

    cout << "Queue size: " << queue.size() << endl;

    while (!queue.isEmpty())
    {
        cout << "Dequeue: " << queue.dequeue() << endl;
    }

    cout << "Queue size: " << queue.size() << endl;

    return 0;
}
