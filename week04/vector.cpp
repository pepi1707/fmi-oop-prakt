#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Vector
{
    T *elements;
    size_t numElements;
    size_t capacity;

    void resize()
    {
        capacity *= 2;
        T *cur = new T[capacity];
        for(int i = 0; i < numElements; i++)
        {
            cur[i] = elements[i];
        }
        delete[] elements;
        elements = cur;
    }

public:
    Vector()
    {
        elements = new T[1];
        numElements = 0;
        capacity = 1;
    }

    ~Vector()
    {
        delete[] elements;
    }

    Vector(const Vector& toCopy)
    {
        numElements = toCopy.numElements;
        capacity = toCopy.capacity;
        elements = new T[capacity];
        for(int i = 0; i < numElements; i++)
            elements[i] = toCopy.elements[i];
    }

    void push(const T& toPush)
    {
        if(numElements == capacity)
        {
            resize();
        }
        elements[numElements] = toPush;
        numElements ++;
    }

    size_t size()
    {
        return numElements;
    }

    T& operator [] (size_t x)
    {
        assert(x < numElements && x >= 0);
        return elements[x];
    }
};


int main()
{
    Vector<int> v;
    v.push(2);
    v.push(3);
    cout << v[0] << endl;
	return 0;
}
