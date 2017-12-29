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

int insert(int N, int M, int j, int i)
{
    M = (M << i);

    int out = N;
    for (int index = i; index <= j; ++index)
    {
        if (getBit(M, index))
        {
            out = setBit(out, index);
        }
        else
        {
            out = clearBit(out, index);
        }
    }

    return out;
}

int main()
{
    int N = 0b10000000000;
    int M = 0b10011;

    int i = 2;
    int j = 6;

    int output = insert(N, M, j, i);
    std::cout << output << std::endl;

    return 0;
}
