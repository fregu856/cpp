#include <iostream>
#include <vector>

void merge(std::vector<int> &vec, int low, int mid, int high)
{
    std::vector<int> temp_vec(vec);

    int left_low = low;
    int left_high = mid;
    int right_low = mid+1;
    int right_high = high;

    int left = left_low;
    int right = right_low;
    int current = low;
    while (left <= left_high && right <= right_high)
    {
        if (temp_vec[left] < temp_vec[right])
        {
            vec[current] = temp_vec[left];
            current++;
            left++;
        }
        else
        {
            vec[current] = temp_vec[right];
            current++;
            right++;
        }
    }

    while (left <= left_high)
    {
        vec[current] = temp_vec[left];
        current++;
        left++;
    }
}

void mergeSortUtil(std::vector<int> &vec, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high-low)/2;

    mergeSortUtil(vec, low, mid);
    mergeSortUtil(vec, mid+1, high);

    merge(vec, low, mid, high);
}

void mergeSort(std::vector<int> &vec)
{
    mergeSortUtil(vec, 0, vec.size()-1);
}

int main()
{
    std::vector<int> vec = {5, 0, 3, 2 ,7 ,1};

    std::cout << "Vector: ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    mergeSort(vec);

    std::cout << "Sorted vector: ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
