#include "bit_manip.h"
// Learning n%r same is n&n-1 if n is power of 2 (at least checked it for 4 and 8) 
// If we observe, we can convert an alphabet to its lowercase by setting 5th bit only

int BitManipulator::CalculateXORfrom1toN(int num)
{
    if(num % 4 == 0) {
        return num;
    } else if (num % 4 == 1) {
        return 1;
    } else if ( num % 4 == 2) {
        return num + 1;
    } else {
        return 0;
    }
}

int BitManipulator::MultipliedBy2(int num) {
    return num << 1;
}
int BitManipulator::MultipliedBy4(int num) {
    return num << 2;
}

int BitManipulator::DevidedBy2(int num) {
    return num >> 1;
}
bool BitManipulator::isPowerOfTwo(int num) {

    return (!(num & (num - 1)));
}
int BitManipulator::DevidedBy4(int num) {
    return num >> 2;
}

int BitManipulator::GetNumOfSetBits(int num){

    int count = 0;
    while (num) {
        count++;
        num = num & (num -1); 
    }
    return count;
}

int BitManipulator::Log2of(int num) {
    
    int result = 0;
    while(num >>= 1) {
        result++;
    }
    return result;
}

char BitManipulator::MakeLower(char ch) {
    int mask = 1 << 5;
    ch = ch | mask;
    return ch;
}

int BitManipulator::SetRthBit(int num, int r) {

    int mask = 1 << r;
    num |= mask;
    return num;
}
int BitManipulator::UnSetRthBit(int num, int r) {

    int mask = 1 << r;
    num &= ~mask;
    return num;
}

int BitManipulator::ToggleRthBit(int num, int r) {

    int mask = 1 << r;
    num ^= mask;
    return num;
}

int BitManipulator::NumZerosInPower2Number(int num)
{
    int count = 0;
    while(num > 1){
        num >>= 1;
        count++;
    }
    return count;
}
bool BitManipulator::IfPowerOf4(int num) 
{
    // One can also check number of zeros after after set bit
    int lg2 = Log2of(num);
    auto is_even = [](int n){
        return !(n % 2);
    };
    return isPowerOfTwo(num) &&  is_even(lg2);
}

bool BitManipulator::IfOppositeSign(int num1, int num2)
{
    return (num1 ^ num2)  < 0;

}
