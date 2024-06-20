#include <stdio.h>
#include <iostream>

using namespace std;

int *input()
{
    int *p = new int(350);
    return p;
}

int main()
{
    int a = 1;
    double b = 1.8;
    char c = 'A';
    // cout << "a address: " << &a << "\n";
    // cout << "b address: " << &b << "\n";
    // cout << "c address: " << &c << "\n";
    // cout << "a value: " << *(&a) << "\n";
    // printf("c address: %x\n", &c);
    // cout << "c address: " << static_cast<void *>(&c) << "\n";

    // double *p = &b;
    // cout << "b address: " << &b << "\n";
    // cout << "p address: " << &p << "\n";

    // // cout << "b = " << *p;

    // int n = 20;
    // int *p1;
    // int *p2 = NULL;
    // int *p3 = &n;
    // cout << "p1 address: " << &p1 << "\n";
    // cout << "p2 address: " << &p2 << "\n";
    // cout << "p3 address: " << &p3 << "\n";
    // cout << "p3 value: " << *p3 << "\n";
    // cout << "n value: " << *(&n) << "\n";
    // cout << "n address: " << &n << "\n";
    // cout << "size of p1: " << sizeof p1 << "\n";
    // cout << "size of char: " << sizeof(char) << "\n";

    // demo cap phat dong
    // int *p = new int(369);
    // // *p = 369;
    // cout << "p address: " << &p << "\n";
    // cout << "p value: " << *p << "\n";

    // delete p;
    // p = NULL;
    // cout << "p address: " << &p << "\n";
    // cout << "p value: " << *p << "\n";

    // int *q = input();
    // cout << "q address: " << &q << "\n";
    // cout << "q value: " << *q << "\n";

    // int x[100] = {1, 3, 4, 6, 8, 8};
    // cout << "x address: " << &x << "\n";
    // cout << "x address: " << x + 3 << "\n";

    int *a = new int[10];

    return 0;
}
