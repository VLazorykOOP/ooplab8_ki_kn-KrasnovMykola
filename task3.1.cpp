#include <iostream>

using namespace std;

template <typename T>
class Array
{
public:
    Array() : data(nullptr), size(0) {}
    Array(int size) : size(size)
    {
        data = new T[size];
    }
    Array(int size, T* data) : size(size)
    {
        this->data = new T[size];
        for (unsigned int i = 0; i < size; i++)
        {
            this->data[i] = data[i];
        }
    }
    Array(const Array& other)
    {
        this->size = other.size;
        this->data = new T[this->size];
        for (unsigned int i = 0; i < this->size; i++)
        {
            this->data[i] = other.data[i];
        }
    }
	~Array() 
    {
        if (data)
            delete[]data;
    }

    unsigned int get_size() const
    {
        return size;
    }

    T& operator[](int index) const
    {
        return data[index];
    }
    Array& operator=(const Array& other)
    {
        this->size = other.size;
        if (this->data)
            delete[]this->data;
        this->data = new T[this->size];
        for (unsigned int i = 0; i < this->size; i++)
        {
            this->data[i] = other.data[i];
        }
        return *this;
    }
    Array operator+(const Array& other) const
    {
        if (this->size != other.size)
            throw "Array sizes are not equal";
        Array result(this->size);
        for (unsigned int i = 0; i < this->size; i++)
        {
            result[i] = (*this)[i] + other[i];
        }
        return result;
    }
    Array& operator+=(const Array& other)
    {
        if (this->size != other.size)
            throw "Array sizes are not equal";
        for (unsigned int i = 0; i < this->size; i++)
        {
            (*this)[i] += other[i];
        }
        return *this;
    }
    Array operator-(const Array& other) const
    {
        if (this->size != other.size)
            throw "Array sizes are not equal";
        Array result(this->size);
        for (unsigned int i = 0; i < this->size; i++)
        {
            result[i] = (*this)[i] - other[i];
        }
        return result;
    }
    Array& operator-=(const Array& other)
    {
        if (this->size != other.size)
            throw "Array sizes are not equal";
        for (unsigned int i = 0; i < this->size; i++)
        {
            (*this)[i] -= other[i];
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Array& a)
    {
        for (unsigned int i = 0; i < a.get_size(); i++)
        {
            out << a[i];
            if (i != a.get_size() - 1)
                out << " ";
        }
        return out;
    }

private:
    T* data;
    unsigned int size;
};

int main()
{
    int aInt[] = { 1, 2, 3 };
    Array<int> aIntArray(3, aInt);
    int bInt[] = { 4, 5, 6 };
    Array<int> bIntArray(3, bInt);
    cout << "A: " << aIntArray << endl;
    cout << "B: " << bIntArray << endl;
    cout << "A + B: " << aIntArray + bIntArray << endl;
    cout << "A - B: " << aIntArray - bIntArray << endl;
    aIntArray += bIntArray;
    cout << "A += B: " << aIntArray << endl;
    aIntArray -= bIntArray;
    cout << "A -= B: " << aIntArray << endl << endl;

    double aDouble[] = { 1.1, 2.22, 3.333 };
    Array<double> aDoubleArray(3, aDouble);
    double bDouble[] = { 4.4444, 5.55555, 6.666666 };
    Array<double> bDoubleArray(3, bDouble);
    cout << "A: " << aDoubleArray<< endl;
    cout << "B: " << bDoubleArray << endl;
    cout << "A + B: " << aDoubleArray + bDoubleArray << endl;
    cout << "A - B: " << aDoubleArray - bDoubleArray << endl;
    aDoubleArray += bDoubleArray;
    cout << "A += B: " << aDoubleArray << endl;
    aDoubleArray -= bDoubleArray;
    cout << "A -= B: " << aDoubleArray << endl << endl;

    int aInt1[] = { 1, 2, 3, 4 };
    Array<int> aIntArray1(4, aInt1);
    int bInt1[] = { 5, 6 };
    Array<int> bIntArray1(2, bInt1);
    cout << "A: " << aIntArray1 << endl;
    cout << "B: " << bIntArray1 << endl;
    try
    {
        cout << "A + B: " << aIntArray1 + bIntArray1 << endl;
    }
    catch (const char* ex)
    {
        cout << ex << endl;
    }
    return 0;
}