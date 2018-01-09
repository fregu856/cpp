#include <iostream>
#include <vector>

bool contiguous(std::vector<int> &vec, int low, int high)
{
    int lower_bound, upper_bound;

    if (vec[low] < vec[high])
    {
        lower_bound = vec[low];
        upper_bound = vec[low] + high-low;
    }
    else
    {
        lower_bound = vec[low] - (high-low);
        upper_bound = vec[low];
    }

    int index = high;
    while (index > low)
    {
        if (!(vec[index] <= upper_bound && vec[index] >= lower_bound))
        {
            return false;
        }

        index--;
    }

    return true;
}

int sizeOfLargestSubarray(std::vector<int> &vec)
{
    if (vec.size() == 1)
    {
        return 1;
    }

    int max_subarray_size = 1;

    for (int i = 0; i < vec.size()-1; ++i)
    {
        for (int j = i+1; j < vec.size(); ++j)
        {
            int subarray_size = j-i+1;
            if (subarray_size > max_subarray_size)
            {
                if (contiguous(vec, i, j))
                {
                    max_subarray_size = subarray_size;
                }
            }
        }
    }

    return max_subarray_size;
}

int main()
{
    std::vector<int> vec = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};

    std::cout << sizeOfLargestSubarray(vec) << std::endl;

    return 0;
}
