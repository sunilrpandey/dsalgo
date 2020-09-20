#pragma once 

#include <iostream>
#include <assert.h>
#include <bitset>

struct BitManipulator
{
    static int CalculateXORfrom1toN(int num);
    static int MultipliedBy2(int num);
    static int MultipliedBy4(int num);
    static int DevidedBy2(int num);
    static bool isPowerOfTwo(int num);
    static int DevidedBy4(int num);
    static int GetNumOfSetBits(int num);
    static int Log2of(int num);
    static char MakeLower(char ch);
    static int SetRthBit(int num, int r);
    static int UnSetRthBit(int num, int r);
    static int ToggleRthBit(int num, int r);

    static int NumZerosInPower2Number(int num);

    static bool IfPowerOf4(int num); 
    static bool IfOppositeSign(int num1, int num2);
};