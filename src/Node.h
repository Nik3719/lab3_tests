#pragma once
#include<string>
using namespace std;

struct Node
{
    string data;        // Данные узла
    Node* next;     // Указатель на следующий узел

    Node(string value) : data(value), next(nullptr) {} // Конструктор
};