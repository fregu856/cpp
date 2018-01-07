#include <iostream>
#include <string>

int numberOf2s_naive(int n)
{
    int num_2s = 0;
    for (int i = 0; i <= n; ++i)
    {
        std::string i_str = std::to_string(i);
        for (int char_i = 0; char_i < i_str.length(); ++char_i)
        {
            if (i_str[char_i] == '2')
            {
                num_2s++;
            }
        }
    }

    return num_2s;
}

int main()
{
    int n = 331;

    std::cout << numberOf2s_naive(n) << std::endl;

    return 0;
}
