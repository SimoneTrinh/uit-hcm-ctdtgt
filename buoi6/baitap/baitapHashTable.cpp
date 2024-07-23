#include <stdio.h>
#include <iostream>

using namespace std;

const int SIZE = 9;

// Hashtable structure

struct Node
{
    int data;
    Node *pNext;
};

struct HashTable
{
    struct Bucket
    {
        Node *pHead;
        Node *pTail;
    };

    Bucket bucket[SIZE];
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

void initHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        h.bucket[i].pHead = NULL;
        h.bucket[i].pTail = NULL;
    }
}

int hashFunction(int value)
{
    return abs(value) % SIZE;
}

void addToHashTable(HashTable &h, Node *pNode)
{
    int bucketIndex = hashFunction(pNode->data);
    if (h.bucket[bucketIndex].pHead == NULL)
    {
        h.bucket[bucketIndex].pHead = h.bucket[bucketIndex].pTail = pNode;
    }
    else
    {
        h.bucket[bucketIndex].pTail->pNext = pNode;
        h.bucket[bucketIndex].pTail = pNode;
    }
}

/* 4. Viet ham in bang bam
 */

void printHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("| Bucket %d |", i);
        for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            cout << " -> " << p->data;
        }
        cout << endl;
    }
}

// Random persudo

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
    return abs(result);
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

void setBaseSeed()
{
    int baseSeed = getRandomPositiveNumber();
    int maxDigitSeed = countDigitInNumber(baseSeed);
    long long baseNumber = multiBy10(maxDigitSeed);
    int base4Seed = (float(baseSeed) / baseNumber) * (9999 - 1000 + 1) + 1000;
    *seed = base4Seed;
}

int extractXDigitFromNumber(int number, int digit)
{
    string numChar = to_string(number);
    int startPos = int(numChar.length() - digit) / 2;
    string middleDigit = numChar.substr(startPos, digit);
    return stoi(middleDigit);
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

int getRandomBetween(int minNum, int maxNum)
{
    return getRandomSeedPersudo(*seed) * (maxNum - minNum + 1) + minNum;
}

/* 1. Viet ham tao du lieu Hashtable, gia tri ngau nhien [856; 988], so luong [45; 95] */

void initRandomHashTableData(HashTable &h)
{
    for (int i = 0; i < getRandomBetween(45, 95); i++)
    {
        addToHashTable(h, initNode(getRandomBetween(856, 988)));
    }
}

/* 2. Viet ham tao du lieu Hashtable tu Array */
void initDynamicArr(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        *(array + i) = getRandomBetween(856, 988);
    }
}

void initHashTableByArr(HashTable &h, int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        addToHashTable(h, initNode(*(array + i)));
    }
}

bool findValueInHashTable(HashTable &h, int searchValue)
{
    int location = hashFunction(searchValue);
    for (Node *p = h.bucket[location].pHead; p != NULL; p = p->pNext)
    {
        if (p->data == searchValue)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    setBaseSeed();
    // HashTable h;
    // initHashTable(h);
    // initRandomHashTableData(h);

    // HashTable h2;
    // initHashTable(h2);
    // addToHashTable(h2, initNode(22));
    // addToHashTable(h2, initNode(33));
    // addToHashTable(h2, initNode(44));
    // addToHashTable(h2, initNode(55));
    // addToHashTable(h2, initNode(11));
    // addToHashTable(h2, initNode(33));
    // addToHashTable(h2, initNode(20));
    // addToHashTable(h2, initNode(25));
    // addToHashTable(h2, initNode(28));
    // addToHashTable(h2, initNode(66));
    // addToHashTable(h2, initNode(77));
    // addToHashTable(h2, initNode(78));
    // addToHashTable(h2, initNode(82));
    // addToHashTable(h2, initNode(83));
    // printHashTable(h2);

    int arrayLength = getRandomBetween(10, 20);
    int *randomArr = new int[arrayLength];
    initDynamicArr(randomArr, arrayLength);

    HashTable h3;
    initHashTable(h3);
    initHashTableByArr(h3, randomArr, arrayLength);
    printHashTable(h3);
    cout << endl;
    cout << findValueInHashTable(h3, 900) << endl;
    return 0;
}