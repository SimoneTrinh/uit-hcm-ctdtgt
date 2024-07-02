#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *pNext;
};

Node *initNode(int value)
{
    Node *pNode = new Node;
    pNode->value = value;
    pNode->pNext = NULL;
    return pNode;
}

struct List
{
    Node *pHead;
    Node *pTail;
};

void initList(List &list)
{
    list.pHead = list.pTail = NULL;
}

void addHead(List &list, Node *pNode)
{
    if (list.pTail == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

void printList(List list)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        cout << p->value << endl;
    }
}

int main()
{
    List lst;
    initList(lst);
    Node *p1 = initNode(1);
    Node *p2 = initNode(2);
    Node *p3 = initNode(3);
    addHead(lst, p1);
    addHead(lst, p2);
    addHead(lst, p3);
    printList(lst);
    return 0;
}