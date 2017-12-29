#include <iostream>

bool getBit(int num, int i)
{
    return (num & (1 << i)) != 0;
}

int numBitsToConvert(int to, int from)
{
    int num_bits_to_convert = 0;

    int diff = to ^ from;
    int num_bits = 8*sizeof(diff);
    for (int i = 0; i < num_bits; ++i)
    {
        if (getBit(diff, i))
        {
            num_bits_to_convert++;
        }
    }

    return num_bits_to_convert;
}

int numBitsToConvert_optimized(int to, int from)
{
    int num_bits_to_convert = 0;
    for (int c = to ^ from; c != 0; c = c & (c-1))
    {
        num_bits_to_convert++;
    }

    return num_bits_to_convert;
}

int main()
{
    int A = 31;
    int B = 14;

    std::cout << "Num bits required to convert A into B: " << numBitsToConvert(A, B) << std::endl;
    std::cout << "Num bits required to convert A into B: " << numBitsToConvert_optimized(A, B) << std::endl;

    return 0;
}
