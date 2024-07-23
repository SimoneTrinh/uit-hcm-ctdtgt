#include <stdio.h>
#include <iostream>

using namespace std;

#define SIZE 5

struct Node
{
    float data;
    Node *pNext;
};

struct HashTable
{
    struct Bucket
    {
        Node *pHead;
        Node *pTail;
    };

    Bucket bucket[SIZE];
};

Node *initNode(float value)
{
    Node *pNode = new Node;
    pNode->data = value;
    pNode->pNext = NULL;
    return pNode;
}

void initHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        h.bucket[i].pHead = h.bucket[i].pTail = NULL;
    }
}

int hashFunc(float value)
{
    return int(abs(value)) % SIZE;
}

void addToHashTable(HashTable &h, Node *pNode)
{
    int index = hashFunc(pNode->data);
    if (h.bucket[index].pHead == NULL)
    {
        h.bucket[index].pHead = h.bucket[index].pTail = pNode;
    }
    else
    {
        h.bucket[index].pTail->pNext = pNode;
        h.bucket[index].pTail = pNode;
    }
}

void printHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("| Bucket %d |", i);
        for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            cout << " -> " << p->data;
        }
        cout << endl;
    }
}

int main()
{
    HashTable h;
    initHashTable(h);

    addToHashTable(h, initNode(22.33));
    addToHashTable(h, initNode(22.24));
    addToHashTable(h, initNode(44.12));
    addToHashTable(h, initNode(55.99));
    addToHashTable(h, initNode(11.02));
    addToHashTable(h, initNode(33.35));
    addToHashTable(h, initNode(20.08));
    addToHashTable(h, initNode(25.37));
    addToHashTable(h, initNode(28.39));
    addToHashTable(h, initNode(66.12));
    addToHashTable(h, initNode(77.54));
    addToHashTable(h, initNode(78.67));
    addToHashTable(h, initNode(82.88));
    addToHashTable(h, initNode(83.81));
    printHashTable(h);
    return 0;
}