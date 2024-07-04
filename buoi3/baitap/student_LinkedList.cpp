#include <stdio.h>
#include <iostream>

using namespace std;

struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

struct Node
{
    SinhVien sinhVien;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node *initNode(SinhVien sv)
{
    Node *pNode = new Node;
    pNode->sinhVien = sv;
    pNode->pNext = NULL;
    return pNode;
}

void initList(List &list)
{
    list.pHead = list.pTail = NULL;
}

void addHead(List &list, Node *pNode)
{
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

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

int main()
{
    List list;
    initList(list);
    SinhVien arrSinhVien[] = {{123, "Nguyen Van A", 9.1, "Gioi"}};
    return 0;
}