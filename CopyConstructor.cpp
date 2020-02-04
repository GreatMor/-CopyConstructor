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

    MyClass& operator =(const MyClass& other)
    {
        this->Size = other.Size;

        if (this->data!=nullptr)
        {
            delete this->data; //free earlier allocated memory for array
        }

        this->data = new int[other.Size]; // a new memory area is allocated.Its size is equal to the size from which we are copied

        for (int i = 0; i < other.Size; i++)
        {
            this->data[i] = other.Size;// copy data from the old array to the new
        }

        cout << "'operator =' called \t" << this << endl;

        return *this;
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
    MyClass B(2);
    MyClass C(14);
    C = B = A;
    return 0;
}

