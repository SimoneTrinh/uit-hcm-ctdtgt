#include <stdio.h>
#include <iostream>

using namespace std;

int getRandomNumber()
{
    int *a = new int;
    delete a;
    return *a;
}

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
    int arr[] = {32, 13, 66, 11, 22};
    int *randomArr = new int[10];
    // int *a = new int();
    // delete a; // value of a is random number
    // cout << (*a) % 10;
    // int z = 10;
    // int *t = new int(10);
    // count << *z;
    // count <<
    // int *a = new int(1);

    // cout << getRandomNumber() << endl;
    // cout << *a;

    int a = 3;
    int b = 4;
    cout << *(&a) << endl;
    hoanvi(&a, &b);
    cout << a << endl;
    cout << b << endl;
}
