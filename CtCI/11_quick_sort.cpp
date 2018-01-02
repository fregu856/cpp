#include <iostream>
#include <vector>

int partition(std::vector<int> &vec, int low, int high)
{
    int pivot = vec[low];

    int left = low+1;
    int right = high;

    while (left <= right)
    {
        while (vec[left] < pivot)
        {
            left++;
        }

        while (vec[right] > pivot)
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
    vec[right] = pivot;

    return right;
}

void quickSortUtil(std::vector<int> &vec, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int index = partition(vec, low, high);

    quickSortUtil(vec, low, index-1);
    quickSortUtil(vec, index+1, high);
}

void quickSort(std::vector<int> &vec)
{
    quickSortUtil(vec, 0, vec.size()-1);
}

int main()
{
    std::vector<int> vec = {5, 0, 3, 2, 7, 1};

    std::cout << "Original: ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    quickSort(vec);

    std::cout << "Sorted: ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
