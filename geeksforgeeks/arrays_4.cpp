#include <iostream>
#include <vector>

void printVector(std::vector<int> &vec)
{
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void sort(std::vector<int> &vec)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == 0)
        {
            zeros++;
        }
        else if (vec[i] == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        if (zeros > 0)
        {
            vec[i] = 0;
            zeros--;
        }
        else if (ones > 0)
        {
            vec[i] = 1;
            ones--;
        }
        else
        {
            vec[i] = 2;
        }
    }
}

int main()
{
    std::vector<int> vec = {0, 2, 1, 2, 0};

    printVector(vec);

    sort(vec);

    printVector(vec);

    return 0;
}
