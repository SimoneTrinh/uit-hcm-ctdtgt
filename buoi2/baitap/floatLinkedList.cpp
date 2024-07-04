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

void printNode(Node *pNode)
{
    cout << "Node: " << pNode << " | Value: " << pNode->value << endl;
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

// 7. In DSLK kem dia chi tung node
void printListWithAddress(List &list)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        cout << p->value << "|" << p << endl;
    }
}

// 8. Viet ham kiem tra DSLK rong hay khong
int isEmptyList(List &list)
{
    if (list.pHead != NULL)
    {
        return 1;
    }
    return 0;
}

// 9. Viet ham tra ve node thu n trong DSLK
Node *getNodeIndex(List &list, int findIndex)
{
    int index = 0;
    Node *pResult = new Node;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (index == findIndex)
        {
            pResult = p;
            break;
        }
        else
        {
            index++;
        }
    }
    return pResult;
}

// 10. Tim kiem 1 node co gia tri X trong DSLK
Node *findNodeValue(List &list, int findValue)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->value == findValue)
        {
            return p;
            break;
        }
    }
    return NULL;
}

// 11. Tim kiem cac dia chi node co gia tri X trong DSLK
List findNodes(List &pList, int findValue)
{
    List lst;
    initList(lst);
    for (Node *p = pList.pHead; p != NULL; p = p->pNext)
    {
        if (p->value == findValue)
        {
            addHead(lst, p);
        }
    }
    return lst;
}

// 12. Viet ham dem node co gia tri am/duong
int countPositiveNodeValue(List &list)
{
    int count = 0;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->value > 0)
        {
            count++;
        }
    }
    return count;
}

int countNegativeNodeValue(List &list)
{
    int count = 0;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->value < 0)
        {
            count++;
        }
    }
    return count;
}

// 13. Viet ham tim node co gia tri am lon nhat
int findMaxNegativeNodeValue(List &list)
{
    int max;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->value < 0)
        {
            max = p->value;
            break;
        }
    }
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->value < 0)
        {
            if (p->value > max)
            {
                max = p->value;
            }
        }
    }
    return max;
}

// 13. Viet ham tim node co gia tri le nho nhat
int findMaxOddNodeValue(List &list)
{
    int max;
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (int(p->value) % 2 != 0)
        {
            max = p->value;
            break;
        }
    }
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (int(p->value) % 2 != 0)
        {
            if (p->value > max)
            {
                max = p->value;
            }
        }
    }
    return max;
}

// 14. Update node co gia tri X trong DSLK
void *updateNodeValue(List &list, int findValue, int updateValue)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        if (p->value == findValue)
        {
            p->value = updateValue;
        }
    }
    return 0;
}

// 15. Copy DSLK

List copyList(List &originalList)
{
    List list;
    initList(list);
    for (Node *p = originalList.pHead; p != NULL; p = p->pNext)
    {
        addHead(list, p);
    }
    return list;
}

int main()
{
    List list;
    initList(list);

    int arr[] = {5, 6, 2, 3, 3, 6, 7};
    addArrayToList(list, arr, 5);

    printList(list);

    printListWithAddress(list);

    Node *foundNode = getNodeIndex(list, 2);
    printNode(foundNode);

    Node *foundNodeValue = findNodeValue(list, 6);
    printNode(foundNodeValue);

    List foundList;
    initList(foundList);
    foundList = findNodes(list, 3);
    printList(foundList);

    List cpList;
    initList(cpList);
    cpList = copyList(list);
    printList(cpList);
}