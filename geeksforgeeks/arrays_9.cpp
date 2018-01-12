#include <iostream>
#include <vector>

int max(std::vector<int> &vec, int low, int high)
{
    int max = vec[low];
    for (int i = low; i <= high; ++i)
    {
        if (vec[i] > max)
        {
            max = vec[i];
        }
    }

    return max;
}

void printMax(std::vector<int> &vec, int k)
{
    for (int i = 0; i+k-1 < vec.size(); ++i)
    {
        int subarray_max = max(vec, i, i+k-1);
        std::cout << subarray_max << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 1, 4 ,5, 2, 3 ,6};
    int k = 3;

    printMax(vec, k);

    return 0;
}
