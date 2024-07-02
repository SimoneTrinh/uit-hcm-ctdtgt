#include <stdio.h>
#include <iostream>
using namespace std;

// 1. Xay dung cau truc Node va DSLK don
struct Node
{
    float value;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

// 2. Khoi tao Node
Node *initNode(float val)
{
    Node *pNode = new Node;
    pNode->value = val;
    pNode->pNext = NULL;
    return pNode;
}

// 2. Khoi tao DSLK
void initList(List &list)
{
    list.pHead = list.pTail = NULL;
}

// 3. Chen Node vao dau DS
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

// 4. Chen Node vao cuoi DS
void addTail(List &list, Node *pNode)
{
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
}

// 5. Nhap gia tri cho DS tu mang 1 chieu

void addArrayToList(List &list, int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Node *pNode = initNode(array[i]);
        addHead(list, pNode);
    }
}

// 6. In DSLK
void printList(List &list)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        cout << p->value << " ";
    }
    cout << endl;
}

int main()
{
    List list;
    initList(list);
    int arr[] = {5, 6, 2, 3, 4, 6, 7};
    addArrayToList(list, arr, 3);
    printList(list);
}