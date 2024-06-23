#include <stdio.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

struct List
{
    Node *pHead;
    Node *pTail;
};

void initList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

void addHead(List &list, Node *p)
{
    if (list.pTail == NULL)
    {
        list.pHead = p;
        list.pTail = p;
    }
    else
    {
        p->pNext = list.pHead;
        list.pHead = p;
    }
}

void addTail(List &list, Node *p)
{
    if (list.pHead == NULL)
    {
        list.pHead = p;
        list.pTail = p;
    }
    else
    {
        list.pTail->pNext = p;
        list.pTail = p;
    }
}

void printList(List list)
{
    Node *p = list.pHead;
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->pNext;
    }
    cout << endl;
}

void findValueInList(List list, int value)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->data == value)
        {
            cout << "Found value: " << value << " with address: " << list.pHead << endl;
        }
    }
}

int main()
{
    List list;
    initList(list);
    Node *p = initNode(10);
    addHead(list, p);
    addHead(list, initNode(79));
    addHead(list, initNode(39));
    addHead(list, initNode(68));
    addHead(list, initNode(35));
    addHead(list, initNode(59));
    printList(list);

    // findValueInList(list, 68);

    cout << "Hello world!";
    return 0;
}