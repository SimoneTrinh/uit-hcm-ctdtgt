#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int *seed = new int();

int getRandomNumber()
{
    int *result = new int(0);
    delete result;
    return *result;
}

int getRandomPositiveNumber()
{
    int result = getRandomNumber();
    if (result < 0)
    {
        result = -result;
    }
    return result;
}

long long multiBy10(int multipler)
{
    long long result = 1;
    if (multipler == 0)
    {
        result = result;
    }
    else if (multipler > 0)
    {
        for (int i = 0; i < multipler; i++)
        {
            result *= 10;
        }
    }
    return result;
}

int countDigitInNumber(int nInput)
{
    if (nInput < 10 && nInput >= 0)
    {
        return 1;
    }
    else if (nInput < 0)
    {
        nInput = -(nInput);
    }
    return 1 + countDigitInNumber(nInput / 10);
}

int extractXDigitFromNumber(int number, int digit)
{
    string numChar = to_string(number);
    int startPos = int(numChar.length() - digit) / 2;
    string middleDigit = numChar.substr(startPos, digit);
    return stoi(middleDigit);
}

void setBaseSeed()
{
    int baseSeed = getRandomPositiveNumber();
    int maxDigitSeed = countDigitInNumber(baseSeed);
    long long baseNumber = multiBy10(maxDigitSeed);
    int base4Seed = (float(baseSeed) / baseNumber) * (9999 - 1000 + 1) + 1000;
    *seed = base4Seed;
}

float getRandomSeedPersudo(int &seed)
{
    // https://www.youtube.com/watch?v=sszXx69W9R4
    int sqrtSeed = seed * seed;
    int maxDigitSeed = countDigitInNumber(sqrtSeed);
    long long baseNumber = multiBy10(maxDigitSeed);
    seed = extractXDigitFromNumber(sqrtSeed, 4);
    return float(sqrtSeed) / baseNumber;
}

float roundToTwoDecimal(float value)
{
    return floor(value * 100 + 0.5) / 100;
}

int getRandomBetween(int minNum, int maxNum)
{
    return getRandomSeedPersudo(*seed) * (maxNum - minNum + 1) + minNum;
}

float getRandomFloatBetween(int minNum, int maxNum)
{
    return roundToTwoDecimal(getRandomSeedPersudo(*seed) * (maxNum - minNum + 1) + minNum);
}

void initDynamicArr(float *array, int &length)
{
    for (int i = 0; i < length; i++)
    {
        *(array + i) = getRandomFloatBetween(268, 339);
    }
}

void printArray(float *array, int length)
{
    cout << "[";
    for (int i = 0; i < length; i++)
    {
        cout << " " << *(array + i);
    }
    cout << " ]" << endl;
}

void printOddValueOfArray(float *array, int &length)
{
    for (int i = 0; i < length; i++)
    {
        if ((int)*(array + i) % 2 == 1)
        {
            cout << *(array + i) << endl;
        }
    }
}

void printEvenValueOfArray(float *array, int &length)
{
    for (int i = 0; i < length; i++)
    {
        if ((int)*(array + i) % 2 == 0)
        {
            cout << *(array + i) << endl;
        }
    }
}

void findMinValueOfArray(float *array, int &length)
{
    float result = *(array);
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) < result)
        {
            result = *(array + i);
        }
    }
    cout << "Min value of given array is: " << result << endl;
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

void printNegativeValueInArray(float *array, int &length)
{
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) < 0)
        {
            cout << "Found negative value:  " << *(array + i) << endl;
        }
    }
}

void printQuantityOfValueInArrayBetween(float *array, int &length, float min, float max)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) > min && *(array + i) < max)
        {
            count++;
        }
    }
    cout << "Found " << count << " value matching the condition!." << endl;
}

void printValueInArrayBetween(float *array, int &length, float min, float max)
{
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) > min && *(array + i) < max)
        {
            cout << "Found value: " << *(array + i) << endl;
        }
    }
}

void sumAndMultiplerAllElementsInArray(float *array, int length)
{
    float sumResult = 0;
    long long multiplerResult = 1;
    for (int i = 0; i < length; i++)
    {
        sumResult += *(array + i);
        multiplerResult *= *(array + i);
    }
    cout << "Sum of all elements in array is: " << sumResult << endl;
    cout << "Multipler of all elements in array is: " << multiplerResult << endl;
}

void countTheApperanceOfAnElement(float *array, int length, float value)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) == value)
        {
            count++;
        }
    }
    cout << "Element with value " << value << " appear " << count << " time(s)!" << endl;
}

int main()
{
    // 1. Tao gia tri ngau nhien (so thuc 2 chu so sau dau cham) thuoc (268; 339). SL ngau nhien thuoc [10;20]
    setBaseSeed();
    int arrayLength = getRandomBetween(10, 20);
    float *randomArr = new float[arrayLength];
    initDynamicArr(randomArr, arrayLength);

    // 2. In mang vua tao
    printArray(randomArr, arrayLength);

    // 3 & 4. Tong va tich cac gia tri trong mang
    sumAndMultiplerAllElementsInArray(randomArr, arrayLength);

    // 5. Dem so lan xuat hien 1 phan tu X bat ky
    int selectedElement = getRandomBetween(0, arrayLength);
    countTheApperanceOfAnElement(randomArr, arrayLength, randomArr[selectedElement]);

    // 6. In cac phan tu chan/le cua mang
    printOddValueOfArray(randomArr, arrayLength);
    printEvenValueOfArray(randomArr, arrayLength);

    // 7. Tim phan tu nho nhat trong mang
    findMinValueOfArray(randomArr, arrayLength);

    // 8. Dao nguoc mang
    reverseArray(randomArr, arrayLength);

    // 9. In ra cac so am trong mang
    printNegativeValueInArray(randomArr, arrayLength);

    // 10. Tra ve so luong value trong mang thuoc [x , y]
    printQuantityOfValueInArrayBetween(randomArr, arrayLength, 300, 400);

    // 11. In cac gia tri trong mang thuoc [x, y]
    printValueInArrayBetween(randomArr, arrayLength, 300, 400);
}
