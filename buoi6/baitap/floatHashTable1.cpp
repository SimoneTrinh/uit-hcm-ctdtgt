#include <stdio.h>
#include <iostream>

using namespace std;

const int SIZE = 5;

struct Node
{
    float data;
    Node *pNext;
};

struct Bucket
{
    Node *pHead;
    Node *pTail;
};

struct HashTable
{
    Bucket bucket[SIZE];
};

Node *initNode(float value)
{
    Node *pNode = new Node;
    pNode->data = value;
    pNode->pNext = NULL;
    return pNode;
}

void initBucket(Bucket &bk)
{
    bk.pHead = bk.pTail = NULL;
}

void initHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        initBucket(h.bucket[i]);
    }
}

int hashFunc(float value)
{
    return (int)(abs(value)) % SIZE;
}

void addBucket(Bucket &bk, Node *pNode)
{
    if (bk.pHead == NULL)
    {
        bk.pHead = bk.pTail = pNode;
    }
    else
    {
        bk.pTail->pNext = pNode;
        bk.pTail = pNode;
    }
}

void addToHashTable(HashTable &h, Node *pNode)
{
    int i = hashFunc(pNode->data); // Locate key
    addBucket(h.bucket[i], pNode); // Link node to key
}

void printHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        Bucket bk = h.bucket[i];
        printf("| Bucket %d |", i);
        for (Node *p = bk.pHead; p != NULL; p = p->pNext)
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