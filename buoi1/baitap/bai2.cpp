#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void printArray(float *array, int number)
{
    cout << "| ";
    for (int i = 0; i < number; i++)
    {
        cout << *(array + i) << " | ";
    }
    cout << endl;
}

void initArray(float *array, int &length)
{
    *(array + 0) = 0.8;
    *(array + 1) = 5.6;
    *(array + 2) = 9.1;
    *(array + 3) = 7.3;
    *(array + 4) = 10;
    *(array + 5) = 5.9;
    *(array + 6) = 7.2;
    *(array + 7) = 9.3;
    *(array + 8) = 8.0;
    *(array + 9) = 8.7;
    length = 10;
}

void checkAllElementArrayPositive(float *array, int &length)
{
    int flag = 1;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) < 0)
        {
            flag = 0;
        }
        if (flag == 0)
        {
            cout << "Element having value: " << *(array + i) << "is negative number" << endl;
            break;
        }
    }
}

void checkArrayOpposite(float *array, int &length)
{
    // Để kiểm tra mảng đối xứng, cần xét các cặp phần tử đối xứng với nhau, nếu 2 phần tử này có giá trị khác nhau có thể kết luận luôn mảng không đối xứng.
    float *start = array;
    float *end = array + length - 1;
    int flag = 1;
    while (start < end)
    {
        if (*start != *end)
        {
            flag = 0;
            break;
        }
        else if (*start == *end)
        {
            flag = 1;
        }
        // Move toi 1 o nho tiep theo
        start++;
        end--;
    }
    if (flag == 1)
    {
        cout << "Array is opposite!" << endl;
    }
    else if (flag == 0)
    {
        cout << "Array is not opposite!" << endl;
    }
}

void initOppositeArray(float *array, int &length)
{
    *(array + 0) = 1;
    *(array + 1) = 3;
    *(array + 2) = 4;
    *(array + 3) = 9;
    *(array + 4) = 22.2;
    *(array + 5) = 22.2;
    *(array + 6) = 9;
    *(array + 7) = 4;
    *(array + 8) = 3;
    *(array + 9) = 1;
    length = 10;
}

int checkIsIntergerNumber(float number)
{
    int flag = 1;
    if (number - int(number) != 0)
    {
        flag = 0;
    }
    return flag;
}

int checkIsPrincipalNumber(int number)
{
    int flag = 1;
    for (int i = 2; i < number / 2; i++)
    {
        if (number % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void checkArrHavePrincipalValue(float *array, int &length)
{
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (checkIsIntergerNumber(*(array + i)) == 1)
        {
            if (checkIsPrincipalNumber(*(array + i)) == 1)
            {
                cout << "Found principal number: " << *(array + i) << endl;
            }
        }
    }
}

int checkIsSquareNumber(int number)
{
    int flag = 0;
    if (checkIsIntergerNumber(sqrt(number)) == 1)
    {
        flag = 1;
    }
    return flag;
}

void checkArrHaveSquareValue(float *array, int &length)
{
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (checkIsIntergerNumber(*(array + i)) == 1)
        {
            if (checkIsSquareNumber(*(array + i)) == 1)
            {
                cout << "Found square number: " << *(array + i) << endl;
            }
        }
    }
}

void findValueInArray(float *array, int &length, float value)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) == value)
        {
            cout << "Found value " << value << " in array" << " at index " << i << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Value " << value << " is not in the given array" << endl;
    }
}

void findNegativeValueInArray(float *array, int &length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) < 0)
        {
            cout << "Found negative value " << *(array + i) << " in given array!";
        }
    }
    if (count == 0)
    {
        cout << "No negative value in the given array!" << endl;
    }
}

void findPositiveValueInArrayAndSum(float *array, int &length)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) > 0)
        {
            cout << "Found positive value " << *(array + i) << " in given array!" << endl;
            sum += *(array + i);
        }
    }
    if (count == 0)
    {
        cout << "No positive value in the given array!" << endl;
    }
    else if (count > 0)
    {
        cout << "Sum of all positive value in array is: " << sum << endl;
    }
}

void reverseArray(float *array, int &length)
{
    cout << "Array before reverse:  " << endl;
    printArray(array, length);

    float *start = array;
    float *end = array + length - 1;
    while (start < end)
    {
        // Hoan vi 2 dia chi
        float temp = *start;
        *start = *end;
        *end = temp;

        // Move toi 1 o nho tiep theo
        start++;
        end--;
    }

    cout << "Array after reverse:  " << endl;
    printArray(array, length);
}

int main()
{
    // 1. Khoi tao mang theo yc:
    float *array = new float[100];
    int length = 0;
    initArray(array, length);

    // 2. In mang ra man hinh
    printArray(array, length);

    // 3. Kiem tra mang co toan duong
    checkAllElementArrayPositive(array, length);

    // 6. Kiem tra mang doi xung
    float *oppositeArray = new float[100];
    int oppositeArrLength = 0;
    initOppositeArray(oppositeArray, oppositeArrLength);
    checkArrayOpposite(array, length);
    checkArrayOpposite(oppositeArray, oppositeArrLength);

    // 7. Tim so nguyen to, so chinh phuong
    checkArrHavePrincipalValue(array, length);
    checkArrHaveSquareValue(array, length);

    // 8. Tim 1 gia tri trong mang
    findValueInArray(array, length, 1);

    // 9. Tim cac SNT trong mang - giong cau 7
    // 10. Tim cac SCP trong mang - giong cau 7
    // 11. Tim cac so am trong mang
    findNegativeValueInArray(array, length);
    // 12. Tim cac so duong trong mang va tinh tong
    findPositiveValueInArrayAndSum(array, length);
    // 13. Dao nguoc array
    reverseArray(array, length);
}