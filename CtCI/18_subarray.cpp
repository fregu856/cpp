#include <iostream>
#include <vector>

std::vector<int> findLargestSubarray(std::vector<int> &vec)
{
    if (vec.size() == 1)
    {
        return vec;
    }

    int sum = vec[0];
    int max_sum = vec[0];
    std::vector<int> subarray = {vec[0]};
    std::vector<int> max_subarray = {vec[0]};
    for (int i = 1; i < vec.size(); ++i)
    {
        if (sum > 0)
        {
            sum = sum + vec[i];
            subarray.push_back(vec[i]);
        }
        else
        {
            sum = vec[i];
            subarray = {vec[i]};
        }

        if (sum > max_sum)
        {
            max_sum = sum;
            max_subarray = subarray;
        }
    }

    return max_subarray;
}

int main()
{
    std::vector<int> vec = {4, -12, 5, 2, -1, 4};

    std::vector<int> largest_array = findLargestSubarray(vec);

    for (auto i = largest_array.begin(); i != largest_array.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
