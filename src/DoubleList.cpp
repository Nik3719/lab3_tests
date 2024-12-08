#include"DoubleList.h"

static string DoubleListID = "0";

DoubleList::~DoubleList()
{
    DNode* current = head;
    while (current != nullptr)
    {
        DNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void DoubleList::LDPUSHT(string elem)
{
    len++;
    DNode* newNode = new DNode(elem);
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
    DNode* newNode = new DNode(elem);
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
    if (head == nullptr) return;
    DNode* current = head;
    while (current!=tail)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << " ";
    cout << "\n";
}

void DoubleList::LDDELH()
{
    if (head == nullptr)
    {
        cout << "list empty\n";
        return;
    }
    len--;
    if (head == tail) 
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    DNode* temporary = head;
    head = head->next;
    head->prev = nullptr;
    delete temporary;
}

void DoubleList::LDDELT()
{
    if (head == nullptr)
    {
        cout << "list empty\n";
        return; 
    }
    len--;
    DNode* temporary = tail; 

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

void DoubleList::LDDELV(string elem)
{
    if (head == nullptr)
    {
        cout << "list empty\n";
        return;
    }
 
    DNode* current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == elem)
        {
            if (current == head && current == tail)
            {
                delete current;
                head = nullptr;
                tail = nullptr;
            }
            else if (current == head)
            {
                head = head->next;
                head->prev = nullptr;
                delete current;
            }
            else if (current == tail)
            {
                tail = tail->prev;
                tail->next = nullptr;
                delete current;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            len--;
            break;
        }
        current = current->next;
        index++;
    }

    if (current == nullptr)
    {
        cout << "������ ���\n";
    }
}

int DoubleList::LDISINDEX(string elem)
{
    DNode* current = head;
    int counter = 0;
    while (current!=nullptr)
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
    DNode* current = head;
    int counter = 0;
    while (current != nullptr)
    {
        if (counter==index)
        {
            return current->data;
        }
        counter++;
        current = current->next;
    }
}

string& DoubleList::operator[](int index)
{
    index = mod(index, len);
    DNode* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return current->data; // ���������� ������ �� ������
        }
        current = current->next;
        count++;
    }

  
}