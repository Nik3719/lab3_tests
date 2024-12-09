#include "DoubleList.h"

DoubleList::~DoubleList()
{
    DNode *current = head;
    while (current != nullptr)
    {
        DNode *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void DoubleList::LDPUSHT(string elem)
{
    len++;
    DNode *newNode = new DNode(elem);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode; // ������������� ��������� ���� ��� �������� ������
        newNode->prev = tail; // ������������� ���������� ���� ��� ������ ����
        tail = newNode;       // ��������� �����
    }
}

void DoubleList::LDPUSHH(string elem)
{
    len++;
    DNode *newNode = new DNode(elem);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head; // ������������� ��������� ���� ��� ������ ����
        head->prev = newNode; // ������������� ���������� ���� ��� ������� ������
        head = newNode;       // ��������� ������
    }
}

DoubleList::DoubleList(int capacity) : head(nullptr), tail(nullptr)
{
}

void DoubleList::PRINT()
{
    if (head == nullptr)
    {
        throw std::runtime_error("List is empty");
    }
    DNode *current = head;
    while (current != tail)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << " ";
    cout << "\n";
}

string DoubleList::LDDELH()
{
    if (head == nullptr)
    {
        return "list empty\n";
    }
    len--;
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return "0";
    }
    DNode *temporary = head;
    head = head->next;
    head->prev = nullptr;
    delete temporary;
    return "0";
}

void DoubleList::LDDELT()
{
    if (head == nullptr)
    {
        cout << "list empty\n";
        return;
    }
    len--;
    DNode *temporary = tail;

    if (head == tail)
    {
        delete temporary;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
        delete temporary;
    };
}

string DoubleList::LDDELV(string elem)
{
    if (head == nullptr)
    {
        return "List is empty\n"; // Сообщение о пустом списке
    }

    DNode *current = head;
    while (current != nullptr)
    {
        if (current->data == elem)
        {
            // Если элемент найден
            if (current == head && current == tail) // Один элемент в списке
            {
                delete current;
                head = nullptr;
                tail = nullptr;
            }
            else if (current == head) // Удаляем голову
            {
                head = head->next;
                head->prev = nullptr;
                delete current;
            }
            else if (current == tail) // Удаляем хвост
            {
                tail = tail->prev;
                tail->next = nullptr;
                delete current;
            }
            else // Удаляем элемент между головой и хвостом
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }

            len--;      // Уменьшаем длину списка
            return "0"; // Сообщение об успешном удалении
        }
        current = current->next;
    }

    return "Element not found.\n"; // Если элемент не найден
}

int DoubleList::LDISINDEX(string elem)
{
    DNode *current = head;
    int counter = 0;
    while (current != nullptr)
    {
        if (current->data == elem)
        {
            return counter;
        }
        counter++;
        current = current->next;
    }
    return -1;
}

string DoubleList::LDGET(int index)
{
    if (index >= this->len)
    {
        throw out_of_range("Индекс вне диапазона!");
    }
    DNode *current = head;
    int counter = 0;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        counter++;
        current = current->next;
    }
}

string &DoubleList::operator[](int index)
{
    if (index >= this->len)
    {
        throw out_of_range("Индекс вне диапазона!");
    }
    index = mod(index, len);
    DNode *current = head;
    int count = 0;

    while (current != nullptr)
    {
        if (count == index)
        {
            return current->data; // ���������� ������ �� ������
        }
        current = current->next;
        count++;
    }
}