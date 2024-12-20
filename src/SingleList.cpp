#include"SingleList.h"

SingleList::SingleList(int capacity)
{
    head = nullptr;
}

SingleList::~SingleList()
{
    Node* current = head;
    Node* nextNode;
    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void SingleList::LSPUSHH(string elem)
{
    len++;
    Node* newNode = new Node(elem);
    newNode->next = head;
    head = newNode;
}
void SingleList::LSPUSHT(string value)
{
    len++;
    Node* newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* current = head;
    int index = 1;
    while (current->next != nullptr)
    {
        current = current->next;
        index++;
    }
    current->next = newNode;
}

void SingleList::PRINT()
{
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}


string SingleList::LSDELH()
{
    if (head == nullptr)
    {
        
        return "list is empty\n";
    }
    len--;
    Node* temp = head; 
    head = head->next; 
    delete temp;
    return "0";
}

string SingleList::LSDELV(string elem)
{
    if (head == nullptr)
    {
        return "list is empty\n";
    }
    len--;
    Node* current = head;
    if (current->data == elem)
    {
        Node* temp = current;
        head = current->next;
        delete temp;
        return "0";
    }
    Node* previous = nullptr;
    int index = 0;

    while (current != nullptr)
    {

        if (current->data == elem)
        {
            Node* temp = current;
            previous->next = current->next; 
            delete temp;
            return "0";
        }
        previous = current;
        current = current->next;
        index++;
        
    }
    return "There is no such elem\n";
}

string SingleList::LSGET(int index)
{
    if (index < 0 || index >= this->len) 
    {
        return "Такого индекса нет!";
    }

    Node* current = head;
    int currentIndex = 0;

    while (current != nullptr) 
    {
        if (currentIndex == index) 
        {
            return (current->data);
        }
        current = current->next;
        currentIndex++;
    }
}

int SingleList::LISINDEX(string elem)
{
    Node* current = head;
    int index = 0;

    while (current != nullptr) 
    {
        if (current->data == elem)
        {
            return index; 
        }
        current = current->next;
        index++;
    }
    return -1;
}

string& SingleList::operator[](int index) 
{ 
    index = mod(index, this->len);

    Node* current = this->head;
    int currentIndex = 0;

    while (current != nullptr) 
    {
        if (currentIndex == index) 
        {
            return current->data; // ���������� ������ �� �������� ����
        }
        current = current->next;
        currentIndex++;
    }
}