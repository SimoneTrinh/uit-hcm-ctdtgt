#include <stdio.h>
#include <iostream>
using namespace std;

struct Student
{
    int ID;
    int point;
};

struct Node
{
    Student std;
    Node *pNext;
};

Node *initNode(Student std)
{
    Node *pNode = new Node;
    pNode->std = std;
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

void printList(List &list)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        cout << "Student ID: " << p->std.ID << " | Point: " << p->std.point << endl;
    }
}

int main()
{
    List lst;
    initList(lst);
    Node *p1 = new Node({1, 3});
    Node *p2 = new Node({2, 6});
    Node *p3 = new Node({3, 1});
    addHead(lst, p1);
    addHead(lst, p2);
    addHead(lst, p3);
    printList(lst);
}