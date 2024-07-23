#include <stdio.h>
#include <iostream>

using namespace std;

#define SIZE 5

struct Node
{
    int data;
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

Node *initNode(int value)
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

int hashFunc(int value)
{
    return value % SIZE;
}

void addToHashTable(HashTable &h, Node *pNode)
{
    int i = hashFunc(pNode->data); // locate
    if (h.bucket[i].pHead == NULL)
    {
        h.bucket[i].pHead = h.bucket[i].pTail = pNode;
    }
    else
    {
        h.bucket[i].pTail->pNext = pNode;
        h.bucket[i].pTail = pNode;
    }
}

void printHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("| Bucket[%d] |", i);
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