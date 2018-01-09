#include <iostream>
#include <vector>

int computeSum(int low, int high, std::vector<int> &sums)
{
    if (high == sums.size()-1)
    {
        return sums[low];
    }
    else
    {
        return (sums[low] - sums[high+1]);
    }
}

int sizeOfSmallestSubarray(std::vector<int> &vec, int value)
{
    std::vector<int> sums(vec.size());
    sums[sums.size()-1] = vec[vec.size()-1];
    for (int i = sums.size()-2; i >= 0; --i)
    {
        sums[i] = vec[i] + sums[i+1];
    }

    if (sums[0] <= value)
    {
        return -1;
    }

    int smallest_subarray_size = vec.size();
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i; j < vec.size(); ++j)
        {
            int subarray_size = j-i+1;
            if (subarray_size < smallest_subarray_size)
            {
                int sum = computeSum(i, j, sums);
                if (sum > value)
                {
                    smallest_subarray_size = subarray_size;
                }
            }
        }
    }

    return smallest_subarray_size;
}

int main()
{
    std::vector<int> vec = {2, 0, 4, 3, 5, 1};

    std::cout << sizeOfSmallestSubarray(vec, 7) << std::endl;

    return 0;
}
