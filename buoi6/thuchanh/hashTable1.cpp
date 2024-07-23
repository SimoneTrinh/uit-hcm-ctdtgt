#include <stdio.h>
#include <iostream>

using namespace std;

#define SIZE 5

struct Node
{
    int data;
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

Node *initNode(int value)
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

int hashFunc(int value)
{
    return value % SIZE;
}

void addBucket(Bucket &bk, Node *pNode) // Add tail
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
        printf("| Bucket[%d] |", i);
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
    addToHashTable(h, initNode(22));
    addToHashTable(h, initNode(33));
    addToHashTable(h, initNode(44));
    addToHashTable(h, initNode(55));
    addToHashTable(h, initNode(11));
    addToHashTable(h, initNode(33));
    addToHashTable(h, initNode(20));
    addToHashTable(h, initNode(25));
    addToHashTable(h, initNode(28));
    addToHashTable(h, initNode(66));
    addToHashTable(h, initNode(77));
    addToHashTable(h, initNode(78));
    addToHashTable(h, initNode(82));
    addToHashTable(h, initNode(83));
    printHashTable(h);
    return 0;
}
