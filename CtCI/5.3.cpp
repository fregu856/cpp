#include <iostream>

bool getBit(int num, int i)
{
    return (num & (1 << i)) != 0;
}

int setBit(int num, int i)
{
    return num | (1 << i);
}

int clearBit(int num, int i)
{
    return num & (~(1 << i));
}

int nextBigger(int value)
{
    int output = value;

    int num_bits =  8*sizeof(value);
    for (int i = 0; i < num_bits-1; ++i)
    {
        if (getBit(value, i))
        {
            if (!getBit(value, i+1))
            {
                output = clearBit(output, i);
                output = setBit(output, i+1);
                return output;
            }
        }
    }

    return value;
}

int nextSmaller(int value)
{
    int output = value;

    int num_bits = 8*sizeof(value);
    for (int i = 1; i < num_bits; ++i)
    {
        if (getBit(value, i))
        {
            if (!getBit(value, i-1))
            {
                output = clearBit(output, i);
                output = setBit(output, i-1);
                return output;
            }
        }
    }

    return value;
}

int main()
{
    int value2 = 0b01011;
    int value = 0b01011;

    std::cout << "Value: " << value2 << ", next bigger: " << nextBigger(value) << ", next smaller: " << nextSmaller(value) << std::endl;

    return 0;
}
