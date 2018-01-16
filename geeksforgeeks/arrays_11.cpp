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
void quickSortSelect(std::vector<int> &vec, int k, int low, int high)
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
        quickSortSelect(vec, k, partition_index+1, high);
    }
    else
    {
        quickSortSelect(vec, k, low, partition_index-1);
    }
}

int getKthSmallest(std::vector<int> &vec, int k)
{
    quickSortSelect(vec, k, 0, vec.size()-1);

    return vec[k-1];
}

int main()
{
    std::vector<int> vec = {7, 10, 4 ,3 ,20, 15};
    int k = 3;

    std::cout << getKthSmallest(vec, k) << std::endl;

    return 0;
}
