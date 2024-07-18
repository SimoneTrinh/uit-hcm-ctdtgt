// #include <stdio.h>
#include <iostream>

using namespace std;

// 1. Khai bao cau truc Node & Stack
struct Node
{
    float value;
    Node *pNext;
};

struct Stack
{
    Node *pTop;
};

// 2. Viet ham khoi tao Node & Stack
Node *initNode(float data)
{
    Node *pNode = new Node;
    pNode->value = data;
    pNode->pNext = NULL;
    return pNode;
}

void initStack(Stack &stack)
{
    stack.pTop = NULL;
}

// 3. Viet ham kiem tra stack rong
bool isStackNull(Stack &stack)
{
    if (stack.pTop == NULL)
    {
        return true;
    }
    else
        return false;
}

// 4. Viet ham day 1 phan tu vao stack
void push(Stack &stack, Node *pNode)
{
    if (isStackNull(stack) == true)
    {
        stack.pTop = pNode;
    }
    else
    {
        pNode->pNext = stack.pTop;
        stack.pTop = pNode;
    }
}

// 5. Viet ham lay 1 phan tu ra khoi stack
void pop(Stack &stack)
{
    if (isStackNull(stack) == true)
    {
        return;
    }
    else
    {
        Node *pNode = stack.pTop;
        stack.pTop = stack.pTop->pNext;
        delete pNode;
    }
}

// 6. Lay gia tri phan tu top cua stack
int getTopStack(Stack &stack)
{
    if (isStackNull(stack) == true)
    {
        return 0;
    }
    else
    {
        return stack.pTop->value;
    }
}

// 7. Viet ham in stack
void printStack(Stack &stack)
{
    cout << "Stack s = Top < ";
    for (Node *p = stack.pTop; p != NULL; p = p->pNext)
    {
        cout << p->value << " ";
    }
    cout << ">" << endl;
}

int main()
{
    Stack stack;
    initStack(stack);
    Node *p1 = initNode(10);
    Node *p2 = initNode(79);
    Node *p3 = initNode(39);
    Node *p4 = initNode(29);
    Node *p5 = initNode(19);
    push(stack, p1);
    push(stack, p2);
    push(stack, p3);
    push(stack, p4);
    push(stack, p5);
    cout << "Top value of stack: " << getTopStack(stack) << endl;
    printStack(stack);
    pop(stack);
    cout << "Top value of stack after pop: " << getTopStack(stack) << endl;
    printStack(stack);
}