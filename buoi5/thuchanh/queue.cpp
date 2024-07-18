#include <stdio.h>
#include <iostream>

using namespace std;

// 1. Khoi tao Queue
struct Node
{
    int data;
    Node *pNext;
};

struct Queue
{
    Node *pFront;
    Node *pRear;
};

Node *initNode(int value)
{
    Node *pNode = new Node;
    pNode->data = value;
    pNode->pNext = NULL;
    return pNode;
}

void initQueue(Queue &queue)
{
    queue.pFront = queue.pRear = NULL;
}

// 2. Kiem tra queue rong
bool isQueueNull(Queue queue)
{
    if (queue.pFront == NULL)
    {
        return true;
    }
    else
        return false;
}

// 3. Add 1 phan tu vao Queue
void enQueue(Queue &queue, Node *pNode) // add Tail
{
    if (isQueueNull(queue) == true)
    {
        queue.pFront = queue.pRear = pNode;
    }
    else
    {
        queue.pRear->pNext = pNode;
        queue.pRear = pNode;
    }
}

// Lay ra 1 phan tu khoi Queue
void deQueue(Queue &queue) // delete Head
{
    if (isQueueNull(queue) == true)
    {
        return;
    }
    else
    {
        Node *pTemp = queue.pFront;
        queue.pFront = queue.pFront->pNext;
        delete pTemp;
    }
}

void printQueue(Queue queue)
{
    cout << "Front < ";
    for (Node *pNode = queue.pFront; pNode != NULL; pNode = pNode->pNext)
    {
        cout << pNode->data << " ";
    }
    cout << " > Rear" << endl;
}

void printFront(Queue Queue)
{
    cout << "Front: " << Queue.pFront->data << endl;
}

void printRear(Queue Queue)
{
    cout << "Rear: " << Queue.pRear->data << endl;
}

int main()
{
    Queue queue;
    initQueue(queue);
    Node *p1 = initNode(10);
    Node *p2 = initNode(15);
    Node *p3 = initNode(25);
    Node *p4 = initNode(11);
    Node *p5 = initNode(66);
    enQueue(queue, p1);
    enQueue(queue, p2);
    enQueue(queue, p3);
    enQueue(queue, p4);
    enQueue(queue, p5);
    printQueue(queue);
    printFront(queue);
    printRear(queue);
    deQueue(queue);
    printQueue(queue);
    printFront(queue);
    printRear(queue);
}