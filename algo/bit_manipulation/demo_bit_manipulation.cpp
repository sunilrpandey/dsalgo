#include "bit_manip.h"

void DemoXORRule_abc()
{
    std::cout << "\nDemo : DemoXORRule_abc" << std::endl;
    int a = 5, b = 7;
    int c = a ^ b;
    std::cout << "Initial a = " << a << " b = " << b << std::endl;
    
    std::cout << "c(a^b) =  " << c << std::endl;
    std::cout << "b(a^c) =  " << (a ^ c) << std::endl;
    std::cout << "a(b^c) =  " << (b ^ c) << std::endl;

    
}
void DemoBitManipulations()
{
    assert(12 == BitManipulator::CalculateXORfrom1toN(12));
    assert(1 == BitManipulator::CalculateXORfrom1toN(13));
    assert(15 == BitManipulator::CalculateXORfrom1toN(14));
    assert(0 == BitManipulator::CalculateXORfrom1toN(15));
  
    assert(24 == BitManipulator::MultipliedBy2(12));
    assert(48 == BitManipulator::MultipliedBy4(12));

    assert(12 == BitManipulator::DevidedBy2(24));
    assert(12 == BitManipulator::DevidedBy4(48));

    assert(true == (BitManipulator::isPowerOfTwo(128))); 
    
    assert(1 == BitManipulator::GetNumOfSetBits(4));
    assert(10 == BitManipulator::Log2of(1024));

    assert('a' == BitManipulator::MakeLower('A'));
    assert(12 == BitManipulator::SetRthBit(8,2)); 
    assert(7 == BitManipulator::SetRthBit(7,2)); 

    assert(4 == BitManipulator::UnSetRthBit(12,3)); 
    assert(4 == BitManipulator::ToggleRthBit(12,3)); 
    assert(14 == BitManipulator::ToggleRthBit(12,1)); 

    assert(5 == BitManipulator::NumZerosInPower2Number(32)); 

    assert(true == BitManipulator::IfPowerOf4(64)); 
    assert(false == BitManipulator::IfPowerOf4(128)); 

    assert(true == BitManipulator::IfOppositeSign(100,-200));
    assert(false == BitManipulator::IfOppositeSign(100,200));
    assert(false == BitManipulator::IfOppositeSign(-100,-200));
    assert(true == BitManipulator::IfOppositeSign(-100,200));

    std::cout << "Hurray! Bit Manipulations Test cases passed" << std::endl;


}
int main()
{
    DemoBitManipulations();
    
    // if a^b = c then a^c = b and b ^c = a
    // DemoXORRule_abc();
    return 0;
}