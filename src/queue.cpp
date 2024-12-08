#include"queue.h"


Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}

Queue::~Queue()
{
	while (!isEmpty())
	{
		DNode* temp = front;
		front = front->next;
		if (front)
		{
			front->prev = nullptr;
		}
		else
		{
			rear = nullptr; // ���� ������� �����, ���������� rear
		}
		string res = temp->data;
		delete temp;
		len--;
	}
}

void Queue::QPUSH(string elem)
{
	DNode* newNode = new DNode(elem);
	if (rear) 
	{
		rear->next = newNode;
		newNode->prev = rear;
	}
	rear = newNode;
	if (!front)
	{
		front = rear;
	}
	len++;

}

string Queue::QPOP()
{
	if (isEmpty())
	{
		return "Queue is empty\n";	
	}
	DNode* temp = front;
	front = front->next;
	if (front)
	{
		front->prev = nullptr;
	}
	else 
	{
		rear = nullptr; // ���� ������� �����, ���������� rear
	}
	string res = temp->data;
	delete temp;
	len--;
	return res;
}

string Queue::QGET(int index)
{
	if (len == 0)
	{
		return "Очередь пуста";
	}
	//index = mod(index, len);
	DNode* current = front;
	int currentIndex = 0;

	while (current != nullptr) 
	{
		if (currentIndex == index)
		{
			return current->data;
		}
		current = current->next;
		currentIndex++;
	}
	return "Index out of range.";
}

void Queue::PRINT()
{
	if (isEmpty())
	{
		cout << "Queue is empty\n";
		return;
	}
	DNode* current = rear;
	while (current!=nullptr)
	{
		cout << current->data << " ";
		current = current->prev;
	}
	cout << " - Первый добавленный удалённ будет первым\n";
}