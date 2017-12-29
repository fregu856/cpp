#include <iostream>

bool getBit(int num, int i)
{
    return (num & (1 << i)) != 0;
}

int setBit(int num, int i)
{
    return (num | (1 << i));
}

int clearBit(int num, int i)
{
    return (num & (~(1 << i)));
}

int main()
{
    int test = 7;

    if (getBit(test, 3))
    {
        std::cout << "Bit is 1" << std::endl;
    }
    else
    {
        std::cout << "Bit is 0" << std::endl;
    }

    std::cout << setBit(test, 3) << std::endl;

    std::cout << clearBit(test, 2) << std::endl;

    return 0;
}
