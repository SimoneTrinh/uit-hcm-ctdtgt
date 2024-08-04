#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

struct Tree
{
    Node *pRoot;
};

void initTree(Tree &t)
{
    t.pRoot = NULL;
}

void addNode(Tree &tree, Node *p)
{
    if (tree.pRoot == NULL)
    {
        tree.pRoot = p;
        return;
    }
    Node *pGoTo = tree.pRoot;
    Node *pLoca = NULL;

    while (pGoTo != NULL)
    {
        pLoca = pGoTo;
        if (p->data < pGoTo->data)
        {
            pGoTo = pGoTo->pLeft;
        }
        else if (p->data > pGoTo->data)
        {
            pGoTo = pGoTo->pRight;
        }
    }
    if (p->data < pLoca->data)
    {
        pLoca->pLeft = p;
    }
    else if (p->data > pLoca->data)
    {
        pLoca->pRight = p;
    }
}

void inOrder(Tree tree)
{
    stack<Node *> s;
    Node *p = tree.pRoot;
    while (p != NULL || s.empty() == false)
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        cout << p->data << " ";
        p = p->pRight;
    }
}

// void LNR(Node *p)
// {
//     if (p != NULL)
//     {
//         LNR(p->pLeft);
//         cout << p->data << " ";
//         LNR(p->pRight);
//     }
// }

bool find(Tree tree, int value)
{
    Node *p = tree.pRoot;
    while (p != NULL)
    {
        if (p->data == value)
        {
            return true;
        }
        if (value < p->data)
        {
            p = p->pLeft;
        }
        else if (value > p->data)
        {
            p = p->pRight;
        }
    }
    return false;
}

void sumTree(Node *p, int &sum)
{
    if (p != NULL)
    {
        sum = sum + p->data;
        sumTree(p->pLeft, sum);
        sumTree(p->pRight, sum);
    }
}

void countNode(Node *p, int &count)
{
    if (p != NULL)
    {
        count = count + p->data;
        countNode(p->pLeft, count);
        countNode(p->pRight, count);
    }
}

int main()
{
    Tree tree;
    initTree(tree);
    Node *p1 = initNode(50);
    Node *p2 = initNode(26);
    Node *p3 = initNode(73);
    addNode(tree, p1);
    addNode(tree, p2);
    addNode(tree, p3);
    inOrder(tree);
    // LNR();
    cout << "Find 50: " << find(tree, 50);
    return 0;
}