#include <iostream>

bool getBit(int value, int i)
{
    return (value & (1 << i)) != 0;
}

int setBit(int value, int i)
{
    return value | (1 << i);
}

int add(int a, int b)
{
    int carry = 0;
    int result = 0;

    int num_bits = 8*sizeof(a);
    for (int i = 0; i < num_bits; ++i)
    {
        if ((!getBit(a, i)) && (!getBit(b, i))) // both 0
        {
            if (carry == 1)
            {
                result = setBit(result, i);
                carry = 0;
            }
            else
            {

            }
        }
        else if (getBit(a, i) && getBit(b, i)) // both 1
        {
            if (carry == 1)
            {
                result = setBit(result, i);
                carry = 1;
            }
            else
            {
                carry = 1;
            }
        }
        else // they are different
        {
            if (carry == 1)
            {
                carry = 1;
            }
            else
            {
                result = setBit(result, i);
            }
        }
    }

    return result;
}

int add_optimized(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    int sum = a ^ b;
    int carry = (a & b) << 1;

    return add_optimized(sum, carry);
}

int main()
{
    int a;
    int b;

    while (true)
    {
        std::cout << "a:" << std::endl;
        std::cin >> a;

        std::cout << "b" << std::endl;
        std::cin >> b;

        std::cout << "a: " << a << ", b: " << b << ", a + b: " << add_optimized(a, b) << std::endl;
    }

    return 0;
}
