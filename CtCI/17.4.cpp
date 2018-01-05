#include <iostream>

// bool getBit(int value, int i)
// {
//     return (value & (1 << i)) != 0;
// }
//
// int clearBit(int value, int i)
// {
//     return value & (~(1 << i));
// }
//
// int findLeftOne(int value)
// {
//     int num_bits = 8*sizeof(value);
//     for (int i = 0; i < num_bits; ++i)
//     {
//         if (getBit(value, num_bits-1-i))
//         {
//             return i;
//         }
//     }
//
//     return -1;
// }
//
// int max(int first, int second, int first_orig, int second_orig)
// {
//     int num_bits = 8*sizeof(first);
//
//     if (findLeftOne(first) == -1 && findLeftOne(second) == -1)
//     {
//         return 0;
//     }
//     else if (findLeftOne(first) == -1 && findLeftOne(second) != -1)
//     {
//         return second_orig;
//     }
//     else if (findLeftOne(first) != -1 && findLeftOne(second) == -1)
//     {
//         return first_orig;
//     }
//     else if (findLeftOne(first) < findLeftOne(second))
//     {
//         return first_orig;
//     }
//     else if (findLeftOne(first) > findLeftOne(second))
//     {
//         return second_orig;
//     }
//     else
//     {
//         first = clearBit(first, num_bits-1-findLeftOne(first));
//         second = clearBit(second, num_bits-1-findLeftOne(second));
//
//         return max(first, second, first_orig, second_orig);
//     }
// }
//
// int max(int first, int second)
// {
//     return max(first, second, first, second);
// }

int flip(int value)
{
    // (value is either 0 or 1)

    return value^1;
}

int sign(int value)
{
    // returns 0 if negative, 1 otherwise

    int num_bits = 8*sizeof(value);

    return flip((value >> num_bits-1) & 0x01);
}

int max(int first, int second)
{
    return first*sign(first-second) + second*flip(sign(first-second));
}

int main()
{
    int first = -18;
    int second = 20;

    std::cout << "first: " << first << ", second: " << second << ", max: " << max(first, second) << std::endl;

    return 0;
}
