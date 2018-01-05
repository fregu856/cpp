#include <iostream>
#include <vector>

int largestSumUtil(std::vector<int> &vec, int &largest_sum, int index)
{
    if (index == vec.size()-1)
    {
        int largest_sum_starting_at_index = vec[index];
        if (largest_sum_starting_at_index > largest_sum)
        {
            largest_sum = largest_sum_starting_at_index;
        }
        return largest_sum_starting_at_index;
    }

    int largest_sum_next = largestSumUtil(vec, largest_sum, index+1);
    int largest_sum_starting_at_index;
    if (largest_sum_next > 0)
    {
        largest_sum_starting_at_index = vec[index] + largest_sum_next;
    }
    else
    {
        largest_sum_starting_at_index = vec[index];
    }

    if (largest_sum_starting_at_index > largest_sum)
    {
        largest_sum = largest_sum_starting_at_index;
    }

    return largest_sum_starting_at_index;
}

int largestSum(std::vector<int> &vec)
{
    int largest_sum = vec[0];
    int largest_sum_starting_at_index = largestSumUtil(vec, largest_sum, 0);

    return largest_sum;
}

int main()
{
    std::vector<int> vec = {2, -8, 3, -2, 4, -10};
    int largest_sum = largestSum(vec);

    std::cout << "Largest sum: " << largest_sum << std::endl;

    return 0;
}
