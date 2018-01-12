#include <iostream>
#include <vector>

int findEquilibrium(std::vector<int> &vec)
{
    if (vec.size() == 1)
    {
        return 0;
    }

    std::vector<int> sums(vec.size());
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        sum += vec[i];
        sums[i] = sum;
    }

    for (int i = 1; i < vec.size()-1; ++i)
    {
        int sum_prev = sums[i-1];
        int sum_after = sums[sums.size()-1] - sums[i];
        if (sum_prev == sum_after)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> vec = {1, 0, 0, 0, 3, 5, 0, 0, 2, 0, 2, -2, 5, -5, 2};
    //std::vector<int> vec = {1};

    std::cout << findEquilibrium(vec) << std::endl;

    return 0;
}
