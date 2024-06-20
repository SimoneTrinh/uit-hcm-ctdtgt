#include <stdio.h>
#include <iostream>

using namespace std;

int hoanvi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int main()
{
    int a = 3;
    int b = 4;
    cout << *(&a) << endl;
    hoanvi(&a, &b);
    cout << a << endl;
    cout << b << endl;
    cout << "Hello world!";
    return 0;
}