#include <iostream>
using namespace std;

class MyClass
{
    int* data;
    int Size;

public:
    MyClass(int size)
    {
        this->Size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
        cout << "constructor called \t " << this << endl;
    };

    MyClass(const MyClass& other)//Copy Constructor
    {
        this->Size = other.Size;

        this->data = new int[other.Size]; // create new array

        for (int i = 0; i < other.Size; i++)
        {
            this->data[i] = other.Size;// copy data from the old array to the new
        }
        cout << "copy constructor called \t" << this << endl;
    }
    ~MyClass()
    {
        delete[] data;
        cout << "destructor called \t " << this << endl;
    }
};

int main()
{
    
    MyClass A(1);
    MyClass B(A);

    return 0;
}

