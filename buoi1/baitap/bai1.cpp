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
    for (int i = 0; i < length; i++)
    {
        cout << *(array + i) << endl;
    }
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
}
