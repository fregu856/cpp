#include <iostream>
#include <vector>

int findMaximumIncreasingSubarray(std::vector<int> &vec)
{
    int sum = vec[0];
    int max_sum = vec[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i] > vec[i-1])
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
    //std::vector<int> vec = {1, 101, 2, 3, 100, 4 ,5};
    std::vector<int> vec = {10, 7, 3, 2};

    std::cout << findMaximumIncreasingSubarray(vec) << std::endl;

    return 0;
}
