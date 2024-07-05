#include <stdio.h>
#include <iostream>

using namespace std;

// 1. Xay dung CDTL Sinh vien
struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

// 2. Xay dung cau truc Node
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

// 3. Khoi tao dia chi Node
Node *initNode(SinhVien sv)
{
    Node *pNode = new Node;
    pNode->sinhVien = sv;
    pNode->pNext = NULL;
    return pNode;
}

// 3. Khoi tao DSLK
void initList(List &list)
{
    list.pHead = list.pTail = NULL;
}

// 4. Them SV vao dau DS
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

// 5. Them SV vao cuoi DS
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

// 6. Khoi tao du lieu cho DSSV
void addArrayToList(List &list, SinhVien array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Node *pNode = initNode(array[i]);
        addHead(list, pNode);
    }
}

// 7. In DSSV
void printDSLK(List &list)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        cout << "Ma SV: " << p->sinhVien.maSV << " | Ho ten: " << p->sinhVien.hoTen << " | Diem TB: " << p->sinhVien.diemTB << " | Xep loai: " << p->sinhVien.xepLoai << endl;
    }
}

// 8. Tim diem TB cao nhat
float findMaxDiemTB(List &list)
{
    float max = list.pHead->sinhVien.diemTB;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->sinhVien.diemTB > max)
        {
            max = p->sinhVien.diemTB;
        }
    }
    return max;
}

// 9. Find Node theo ma sv
Node *findSinhVienNode(List &list, int ID)
{
    Node *pFoundNode = NULL;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->sinhVien.maSV == ID)
        {
            return pFoundNode = p;
        }
    }
    return pFoundNode;
}

// 10. Tim node co diem TB cao nhat
Node *findNodeMaxDiemTB(List &list)
{
    Node *pMax = list.pHead;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->sinhVien.diemTB > pMax->sinhVien.diemTB)
        {
            pMax = p;
        }
    }
    return pMax;
}

// 11. Tim node co diem TB thap nhat
Node *findNodeMaxDiemTB(List &list)
{
    Node *pMin = list.pHead;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->sinhVien.diemTB < pMin->sinhVien.diemTB)
        {
            pMin = p;
        }
    }
    return pMin;
}

int main()
{
    List list;
    initList(list);
    SinhVien arrSinhVien[] = {{123, "Nguyen Van A", 9.1, "Gioi"}, {124, "Nguyen Van B", 8.8, "Gioi"}, {125, "Nguyen Van C", 9.1, "Gioi"}, {126, "Nguyen Van D", 2.1, "Yeu"}, {127, "Nguyen Van F", 9.7, "Gioi"}, {128, "Nguyen Van G", 4.1, "Trung Binh"}, {129, "Nguyen Van H", 8.3, "Kha"}, {130, "Nguyen Van K", 7.9, "Kha"}};
    addArrayToList(list, arrSinhVien, 8);
    printDSLK(list);
    float maxAvgPoint = findMaxDiemTB(list);
    return 0;
}