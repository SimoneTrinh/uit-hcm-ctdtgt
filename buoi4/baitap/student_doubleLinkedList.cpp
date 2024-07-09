#include <stdio.h>
#include <iostream>

using namespace std;

/* Cau 1: Xay dung CTDL SinhVien */

struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    bool isValid;
    string xepLoai;
};

/* Cau 2: Xay dung CTDL Node va List de quan ly SV  */

struct Node
{
    SinhVien sv;
    Node *pPrev;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

/* Cau 3: Xay dung ham khoi tao DSLK va dia chi Node tu SinhVien  */

Node *initNode(SinhVien sinhVien)
{
    Node *p = new Node;
    p->sv = sinhVien;
    p->pNext = p->pPrev = NULL;
    return p;
}

void initList(List &list)
{
    list.pHead = list.pTail = NULL;
}

/* Cau 4: Viet ham them SV vao dau DS
Input:
    + list: List &
    + pNode: Node *
Output:
    + list: List &
    + bool:
*/

void addHead(List &list, Node *pNode)
{
    if (list.pTail == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead; // Update node next = pHead
        list.pHead->pPrev = pNode; // Update prev of Head
        list.pHead = pNode;        // Update list
    }
}

/* Cau 5: Viet ham them SV vao cuoi DS
Input:
    + list: List &
    + pNode: Node *
Output:
    + list: List &
    + bool:
*/

void addTail(List &list, Node *pNode)
{
    if (list.pTail == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode; // Update pTail = pNode
        pNode->pPrev = list.pTail; // Update prev of Tail
        list.pTail = pNode;        // Update list
    }
}

/* Cau 7: Viet ham in DSSV
Input:
    + list: List &
Output:
    + List: Sinh vien: MaSV | Ho ten | Diem TB | Xep loai;
*/

void printInfoSV(SinhVien sv)
{
    if (sv.isValid == false)
    {
        cout << "Khong tim thay sinh vien co ma SV: " << sv.maSV << endl;
    }
    else
    {
        cout << "Sinh vien: " << sv.maSV << " | " << sv.hoTen << " | " << sv.diemTB << " | " << sv.xepLoai << endl;
    }
}

void printHeadDSSV(List &list)
{
    if (list.pTail == NULL)
    {
        cout << "List khong co du lieu!" << endl;
    }
    else
    {
        for (Node *pNode = list.pHead; pNode != NULL; pNode = pNode->pNext)
        {
            printInfoSV(pNode->sv);
        }
    }
}

void printTailDSSV(List &list)
{
    if (list.pTail == NULL)
    {
        cout << "List khong co du lieu!" << endl;
    }
    else
    {
        for (Node *pNode = list.pTail; pNode != NULL; pNode = pNode->pPrev)
        {
            printInfoSV(pNode->sv);
        }
    }
}

/* Cau 8: Viet ham cap nhat xep loai hoc luc
Input:
    + List: List &
Output:
    + List.Node.xepLoai != Gioi || Kha || Trung Binh || Yeu
*/

void updateHocLucSV(Node *pNode)
{
    if (pNode->sv.diemTB >= 8.0)
    {
        pNode->sv.xepLoai = "Gioi";
    }
    else if (pNode->sv.diemTB >= 6.5 && pNode->sv.diemTB < 8)
    {
        pNode->sv.xepLoai = "Kha";
    }
    else if (pNode->sv.diemTB >= 4 && pNode->sv.diemTB < 6.5)
    {
        pNode->sv.xepLoai = "Trung binh";
    }
    else if (pNode->sv.diemTB >= 0 && pNode->sv.diemTB < 4)
    {
        pNode->sv.xepLoai = "Yeu";
    }
    else
    {
        pNode->sv.xepLoai = "Loi xep loai!";
    }
}

void updateHocLucDSSV(List &list)
{
    for (Node *pNode = list.pHead; pNode != NULL; pNode = pNode->pNext)
    {
        updateHocLucSV(pNode);
    }
}

/* Cau 9: Viet ham tim diem trung binh cao nhat
Input:
    + List: List &
Output:
    + float: sv.DiemTB
*/

float findMaxDiemTB(List &list)
{
    float maxDiemTB = list.pHead->sv.diemTB;
    for (Node *pNode = list.pHead; pNode != NULL; pNode = pNode->pNext)
    {
        if (maxDiemTB < pNode->sv.diemTB)
        {
            maxDiemTB = pNode->sv.diemTB;
        }
    }
    return maxDiemTB;
}

/* Cau 10: Viet ham tim kiem sinh vien theo ma SV
Input:
    + list: List &
    + maSV: int
Output:
    + sv: SinhVien
*/

SinhVien findSinhVienByID(List &list, int maSV)
{
    SinhVien sv = {maSV, "", 0, false, ""};
    for (Node *pNode = list.pHead; pNode != NULL; pNode = pNode->pNext)
    {
        if (pNode->sv.maSV == maSV)
        {
            sv = pNode->sv;
        }
    }
    return sv;
}

/* Cau 11: Viet ham tim sinh vien co TB cao nhat
Input:
    + list: List &
Output:
    + sv: SinhVien
*/
SinhVien findSinhVienMaxTB(List &list)
{
    SinhVien sv = list.pHead->sv;
    for (Node *pNode = list.pHead; pNode != NULL; pNode = pNode->pNext)
    {
        if (sv.diemTB < pNode->sv.diemTB)
        {
            sv = pNode->sv;
        }
    }
    return sv;
}

/* Cau 12: Viet ham tim sinh vien co TB thap nhat
Input:
    + list: List &
Output:
    + sv: SinhVien
*/
SinhVien findSinhVienMinTB(List &list)
{
    SinhVien sv = list.pHead->sv;
    for (Node *pNode = list.pHead; pNode != NULL; pNode = pNode->pNext)
    {
        if (sv.diemTB > pNode->sv.diemTB)
        {
            sv = pNode->sv;
        }
    }
    return sv;
}

int main()
{
    List dsSV;
    initList(dsSV);

    /*Cau 6: Khoi tao du lieu cho DS SV: */
    addHead(dsSV, initNode({123, "Nguyen Van A", 9.1, true, ""}));
    addHead(dsSV, initNode({124, "Nguyen Van B", 8.8, true, ""}));
    addHead(dsSV, initNode({125, "Nguyen Van C", 9.1, true, ""}));
    addHead(dsSV, initNode({126, "Nguyen Van D", 2.1, true, ""}));
    addHead(dsSV, initNode({127, "Nguyen Van F", 9.7, true, ""}));
    addHead(dsSV, initNode({128, "Nguyen Van G", 4.1, true, ""}));
    addHead(dsSV, initNode({129, "Nguyen Van H", 8.3, true, ""}));
    addHead(dsSV, initNode({130, "Nguyen Van K", 7.9, true, ""}));
    cout << "------- Test: Cau 7: Viet ham in DSSV" << endl;
    cout << "------- Print Head" << endl;
    cout << endl;
    printHeadDSSV(dsSV);
    cout << endl;
    cout << "------- Print Tail" << endl;
    cout << endl;
    printTailDSSV(dsSV);
    cout << endl;
    cout << "------- Test: Cau 8: Viet ham cap nhat xep loai hoc luc" << endl;
    cout << endl;
    updateHocLucDSSV(dsSV);
    printHeadDSSV(dsSV);
    cout << endl;
    cout << "------- Test: Cau 9: Viet ham tim diem trung binh cao nhat" << endl;
    cout << endl;
    cout << "Diem TB cao nhat: " << findMaxDiemTB(dsSV) << endl;
    cout << endl;
    cout << "------- Test: Cau 10: Tim SV theo ma SV" << endl;
    cout << endl;
    cout << "--- Test case 01: Tim thay sinh vien, ma SV: 127" << endl;
    printInfoSV(findSinhVienByID(dsSV, 127));
    cout << "--- Test case 02: Khong tim thay sinh vien" << endl;
    printInfoSV(findSinhVienByID(dsSV, 133));
    cout << endl;
    cout << "------- Test: Cau 11: Tim SV co diem TB cao nhat" << endl;
    cout << endl;
    printInfoSV(findSinhVienMaxTB(dsSV));
    cout << endl;
    cout << "------- Test: Cau 12: Tim SV co diem TB thap nhat" << endl;
    cout << endl;
    printInfoSV(findSinhVienMinTB(dsSV));
    return 0;
}