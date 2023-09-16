#include <iostream>
using namespace std;

template <class T>
class customVector
{
private:
    int currentPos = 0;
    int currentSize = 100;
    T *customVec;
    T *increaseSize()
    {
        T *newCustomVec = new T[currentSize * 2];

        for (int i = 0; i <= currentSize; i++)
        {
            newCustomVec[i] = customVec[i];
        }

        currentSize *= 2;
        delete[] customVec;
        return newCustomVec;
    }

    T *decreaseSize()
    {
        if (currentPos <= (currentSize / 4) && currentSize > 100)
        {
            currentSize /= 2;
            T *newCustomVec = new T[currentSize];

            for (int i = 0; i < currentPos; i++)
            {
                newCustomVec[i] = customVec[i];
            }

            delete[] customVec;
            return newCustomVec;
        }
        else
        {
            return customVec;
        }
    }

public:
    customVector()
    {
        customVec = new T[currentSize];
    }
    ~customVector()
    {
        delete[] customVec;
    };

    void pushback(T val)
    {
        if (currentPos >= currentSize)
        {
            customVec = increaseSize();
        }

        customVec[currentPos] = val;
        currentPos++;
    }

    T pop()
    {
        if (currentPos > 0)
        {
            currentPos--;
            T val = customVec[currentPos];
            customVec = decreaseSize();
            return val;
        }
        else
        {
            throw out_of_range("Vector is empty");
        }
    }

    T at(int pos)
    {
        if (pos <= currentPos - 1)
        {
            return customVec[pos];
        }
        else
        {
            throw out_of_range("Vector is empty for specified location");
        }
    }

    int size()
    {
        return (currentPos);
    }

    string capacity()
    {
        return "Current dynamic capacity: " + to_string(currentSize);
    }

    bool isEmpty()
    {
        return currentPos == 0;
    }

    int find(T val)
    {
        for (int i = 0; i < currentPos; i++)
        {
            if (customVec[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    T deletes(int index)
    {
        if (index < 0 || index >= currentPos)
        {
            throw out_of_range("Invalid index");
        }

        T val = customVec[index];

        for (int i = index; i < currentPos - 1; i++)
        {
            customVec[i] = customVec[i + 1];
        }

        currentPos--;
        customVec = decreaseSize();
        return val;
    }

    void remove(T val)
    {
        int count = 0;
        for (int i = 0; i < currentPos; i++)
        {
            if (customVec[i] != val)
            {
                customVec[count] = customVec[i];
                count++;
            }
        }

        currentPos = count;
    }

    void insert(int index, T item)
    {
        if (index < 0 || index > currentPos)
        {
            throw out_of_range("Invalid index");
        }

        if (currentPos >= currentSize)
        {
            customVec = increaseSize();
        }

        for (int i = currentPos; i > index; i--)
        {
            customVec[i] = customVec[i - 1];
        }

        customVec[index] = item;

        currentPos++;
        return;
    }

    void prepend(T val)
    {
        if (currentPos >= currentSize)
        {
            customVec = increaseSize();
        }
        for (int i = currentPos; i > 0; i--)
        {
            customVec[i] = customVec[i - 1];
        }
        customVec[0] = val;
        currentPos++;
        return;
    }
};

// int main()
// {

//     customVector<int> vector;
//     vector.pushback(1);
//     cout << vector.capacity();

//     return 0;
// }