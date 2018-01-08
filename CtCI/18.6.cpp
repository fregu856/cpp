#include <iostream>
#include <vector>

int partition(std::vector<int> &vec, int low, int high)
{
    int pivot_element = vec[low];

    int left = low+1;
    int right = high;

    while (left <= right)
    {
        while (vec[left] < pivot_element)
        {
            left++;
        }

        while (vec[right] > pivot_element)
        {
            right--;
        }

        if (left <= right)
        {
            int temp = vec[left];
            vec[left] = vec[right];
            vec[right] = temp;

            left++;
            right--;
        }
    }

    vec[low] = vec[right];
    vec[right] = pivot_element;

    return right;
}

void quickSortSelectUtil(std::vector<int> &vec, int k, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int partition_index = partition(vec, low, high);

    if (partition_index == k-1)
    {
        return;
    }
    else if (partition_index < k-1)
    {
        quickSortSelectUtil(vec, k, partition_index+1, high);
    }
    else
    {
        quickSortSelectUtil(vec, k, low, partition_index-1);
    }
}

void quickSortSelect(std::vector<int> &vec, int k)
{
    quickSortSelectUtil(vec, k, 0, vec.size()-1);
}

std::vector<int> findSmallest(std::vector<int> &vec, int k)
{
    if (k == vec.size())
    {
        return vec;
    }

    quickSortSelect(vec, k);

    std::vector<int> k_smallest;
    for (int i = 0; i <= k-1; ++i)
    {
        k_smallest.push_back(vec[i]);
    }

    return k_smallest;
}

int main()
{
    std::vector<int> vec = {8, 5, 0, 2, 1, 3, 7, 4, 6};
    int k = 5;

    std::vector<int> k_smallest = findSmallest(vec, k);

    for (auto i = k_smallest.begin(); i != k_smallest.end(); ++i)
    {
      std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
