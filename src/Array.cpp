#include "Array.h"

string Array::MINSERT(string elem, int index)
{
    if (capacity == 0)
    {
        this->MPUSH(elem);
        return "0";
    }

    if (index > currentLen || index < 0)
    {
        return "Такого индекса нет!";
    }
    if (currentLen == capacity)
    {
        capacity*=2;
        string *newArr = new string[capacity];
        
        for (int i = 0; i < index; i++)
        {
            newArr[i] = this->MGET(i);
        }
        newArr[index] = elem;
        for (int i = index + 1; i < currentLen + 1; i++)
        {
            newArr[i] = this->MGET(i);
        }
        delete[] arr;
        this->arr = newArr;
        currentLen++;
        return "0";
    }
    else
    {
        for (int i = currentLen; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }
        this->arr[index] = elem;
        currentLen++;
        return "0";
    }
}

string Array::MGET(int index)
{

    if (index >= currentLen)
    {
        return "Такого индекса нет!\n";
    }
    return arr[index];
}

void Array::MPUSH(string elem)
{
    if (capacity == 0)
    {
        capacity = 2;
        currentLen = 1;
        arr = new string[capacity];
        arr[currentLen - 1] = elem;
    }
    else if (currentLen == capacity)
    {
        string *newArr = new string[currentLen];
        for (int i = 0; i < currentLen; i++)
        {
            newArr[i] = arr[i];
        }

        this->capacity = (this->currentLen) * 2;
        delete[] arr;
        arr = new string[capacity];
        for (int i = 0; i < currentLen; i++)
        {
            arr[i] = newArr[i];
        }
        this->currentLen = this->currentLen + 1;
        delete[] newArr;
        arr[currentLen - 1] = elem;
    }
    else
    {
        this->arr[currentLen++] = elem;
    }
}

Array::~Array()
{
    delete[] arr;
    arr = nullptr;
}

Array::Array(const Array &other) 
{
    // Копируем данные из другого объекта
    this->capacity = other.capacity;
    this->currentLen = other.currentLen;

    // Выделяем память для нового массива
    this->arr = new string[this->capacity];

    // Копируем элементы массива
    for (int i = 0; i < this->currentLen; ++i)
    {
        this->arr[i] = other.arr[i];
    }
}


Array &Array::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] arr;

        currentLen = other.currentLen;
        capacity = other.capacity;
        arr = new string[capacity];
        for (int i = 0; i < currentLen; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

int Array::MLEN()
{
    return this->currentLen;
}

string Array::MDEL(int index)
{
    if (index >= currentLen || index < 0)
    {
        return "Такого индекса нет!";
    }
    string res = arr[index];
    for (int i = index; i < currentLen - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    currentLen--;
    return res;
}
void Array::PRINT()
{
    for (size_t i = 0; i < currentLen; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

string Array::MSET(string elem, int index)
{
    if (index >= currentLen || index < 0)
    {
        return  "Такого индекса нет!";
    }
    arr[index] = elem;
    return "0";
}
