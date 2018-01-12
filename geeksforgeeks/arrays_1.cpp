#include <iostream>
#include <vector>

int findMaximumSum(std::vector<int> &vec)
{
    int sum = 0;
    int max_sum = vec[0];

    for (int i = 0; i < vec.size(); ++i)
    {
        if (sum > 0)
        {
            sum += vec[i];
        }
        else
        {
            sum = vec[i];
        }

        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }

    return max_sum;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, -1, 2, -10, 1};
    //std::vector<int> vec = {-4, -1, -2, -3};

    std::cout << findMaximumSum(vec) << std::endl;

    return 0;
}
