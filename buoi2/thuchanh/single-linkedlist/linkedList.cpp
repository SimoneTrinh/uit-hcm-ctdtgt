#include <iostream>
using namespace std;

struct Data
{
    int value;
};

struct Node
{
    Data data;
    Node *pNext;
};

Node *initNode(Data data)
{
    Node *pNode = new Node;
    pNode->data = data;
    pNode->pNext = nullptr;
    return pNode;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void initList(List &list)
{
    list.pHead = list.pTail = nullptr;
};

void addHead(List &list, Node *pNode)
{
    if (list.pTail == 0) // 1st index || out of memory
    {
        list.pHead = pNode;
        list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead; // because adding from start. Next of node = current head of list
        list.pHead = pNode;
    }
}

void printList(List list)
{
    for (Node *p = list.pHead; p->pNext != NULL; p = p->pNext)
    {
        cout << p->data.value << endl;
    }
}

int main()
{
    List lst;
    initList(lst);
    Node *p1 = initNode({1});
    Node *p2 = initNode({2});
    Node *p3 = initNode({3});
    addHead(lst, p1);
    addHead(lst, p2);
    addHead(lst, p3);
    printList(lst);
    // cout << &lst.pHead->data << endl;
    // cout << &lst.pTail->data << endl;
}