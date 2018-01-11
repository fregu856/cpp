#include <iostream>
#include <vector>

int sizeOfSmallestSubarray(std::vector<int> &vec, int value)
{
    int smallest_subarray_size = vec.size()+1;
    int sum = 0;

    int low = 0;
    int high = 0;
    while (high < vec.size())
    {
        while (sum <= value && high < vec.size())
        {
            sum += vec[high];
            high++;
        }

        while (sum > value)
        {
            int subarray_size = high-low;
            if (subarray_size < smallest_subarray_size)
            {
                smallest_subarray_size = subarray_size;
            }

            sum = sum - vec[low];
            low++;
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
