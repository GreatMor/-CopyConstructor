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

class Point
{
private:
    int x = 0;
    int y = 0;  

public:

    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int value_1, int value_2)
    {
        x = value_1;
        y = value_2;
    }

    void SetX(int _x)
    {
        x = _x;
    }

    void SetY(int _y)
    {
        y = _y;
    }

    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }

    bool operator ==(const Point& other)
    {
        return this->x == other.x && this->y == other.y;
    }

    bool operator !=(const Point& other)
    {
        return !(this->x == other.x && this->y == other.y);
    }

    Point operator +(const Point& other)
    {
        Point themp;
        themp.x = this->x + other.x;
        themp.y = this->y + other.y;
        return themp;
    }


};

int main()  
{
    
    MyClass A(1);
    MyClass B(2);
    MyClass C(14);
    C = B = A;

    Point a(11, 23);
    Point b(1, 23);

    Point z = a + b;
    bool test = a == b;

    //cout << z << endl;

    return 0;
}

