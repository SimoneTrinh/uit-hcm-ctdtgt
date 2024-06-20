#include <stdio.h>
#include <iostream>

using namespace std;

struct ToaDo
{
    int x;
    int y;
};

void printTD(ToaDo t)
{
    cout << "Toa do: " << t.x << " ; " << t.y << "\n";
}

void printTD2(ToaDo *t)
{
    cout << "Toa do: " << t->x << " ; " << t->y << "\n";
}

void printArrToaDo(ToaDo *t, int *n)
{
    // cout << "Toa do: " << t->x << " ; " << t->y << "\n";
    for (int i = 0; i < *n; i++)
    {
        printTD2(t + i);
    }
}

void initTD(ToaDo *t, int *n)
{
    *(t + 0) = {1, 2};
    *(t + 1) = {6, 7};
    *(t + 2) = {2, 9};
    *n = 3;
}
int main()
{
    ToaDo a = {1, 5};

    // printTD(a);
    // printTD2(&a);

    ToaDo *p1 = &a;
    ToaDo *p2 = new ToaDo({7, 9});

    // printTD2(p2);
    // printTD(*p2);
    // cout << "Address a : " << &a << "\n";
    // cout << p2->x << "\n";
    // cout << (*p2).x << "\n";

    ToaDo *p3 = new ToaDo[100];
    int *n3 = new int(0);
    cout << *n3 << "\n";

    initTD(p3, n3);
    cout << *n3 << "\n";

    printArrToaDo(p3, n3);

    return 0;
}
