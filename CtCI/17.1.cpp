#include <iostream>

// bool getBit(int value, int i)
// {
//     return (value & (1 << i)) != 0;
// }
//
// int setBit(int &value, int i)
// {
//     return value | (1 << i);
// }
//
// int clearBit(int &value, int i)
// {
//     return value & (~(1 << i));
// }
//
// void swapNumbers(int &first, int &second)
// {
//     int num_bits = 8*sizeof(first);
//     for (int i = 0; i < num_bits; ++i)
//     {
//         if (getBit(first, i) && (!getBit(second, i)))
//         {
//             first = clearBit(first, i);
//             second = setBit(second, i);
//         }
//         else if ((!getBit(first, i)) && getBit(second, i))
//         {
//             first = setBit(first, i);
//             second = clearBit(second, i);
//         }
//     }
// }

void swapNumbers(int &a, int &b)
{
    a = a - b;
    b = a + b;
    a = b - a;
}

int main()
{
    int first = 6;
    int second = 10;

    std::cout << "first: " << first << ", second: " << second << std::endl;

    swapNumbers(first, second);

    std::cout << "first: " << first << ", second: " << second << std::endl;

    return 0;
}
