#include <iostream>
#include <string>

// long long int factorial(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//
//     return n*factorial(n-1);
// }
//
// int numTrailingZeros(int n)
// {
//     long long int n_fact = factorial(n);
//     std::string n_fact_str = std::to_string(n_fact);
//
//     int num_zeros = 0;
//     for (int i = n_fact_str.length()-1; i >= 0; --i)
//     {
//         if (n_fact_str[i] == '0')
//         {
//             num_zeros++;
//         }
//         else
//         {
//             break;
//         }
//     }
//
//     return num_zeros;
// }

int factorsOf5(int n)
{
    int count = 0;
    while (n % 5 == 0)
    {
        count++;
        n = n/5;
    }

    return count;
}

int numTrailingZeros(int n)
{
    if (n < 5)
    {
        return 0;
    }

    int num_zeros;
    for (int i = 5; i <= n; ++i)
    {
        num_zeros += factorsOf5(i);
    }

    return num_zeros;
}

int main()
{
    while (true)
    {
        int n;
        std::cin >> n;
        int num_zeros = numTrailingZeros(n);

        std::cout << "Number of trailing zeros in " << n << "!: " << num_zeros << std::endl;
    }

    return 0;
}
