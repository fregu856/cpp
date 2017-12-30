#include <iostream>
#include <vector>
#include <cmath>

bool fetchBit(std::vector<int> A, int i, int j)
{
    return (A[i] & (1 << j)) != 0;
}

int findMissingInt(std::vector<int> A, int n)
{
    std::vector<bool> present(n+1, false);
    int num_bits = 8*sizeof(A[0]);

    for (int i = 0; i < A.size(); ++i)
    {
        int sum = 0;
        for (int j = 0; j < num_bits; ++j)
        {
            if (fetchBit(A, i, j))
            {
                sum += pow(2, j);
            }
        }
        std::cout << sum << std::endl;
        present[sum] = true;
    }

    int missing_int;
    for (int i = 0; i < present.size(); ++i)
    {
        if (!present[i])
        {
            missing_int = i;
        }
    }

    return missing_int;
}

int main()
{
    std::vector<int> A = {2, 1, 5, 3, 0};

    // if (fetchBit(A, 1, 2))
    // {
    //     std::cout << "1" << std::endl;
    // }
    // else
    // {
    //     std::cout << "0" << std::endl;
    // }

    int missing_int = findMissingInt(A, 5);
    std::cout << "Missing integer: " << missing_int << std::endl;

    return 0;
}
