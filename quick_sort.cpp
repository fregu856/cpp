// #include <iostream>
// #include <vector>
//
// int partition(std::vector<int> &vec, int low, int high)
// {
//     int pivot = vec[low];
//
//     int left = low + 1;
//     int right = high;
//
//     while (left <= right)
//     {
//         while (vec[left] < pivot)
//         {
//             left++;
//         }
//
//         while (vec[right] > pivot)
//         {
//             right--;
//         }
//
//         if (left <= right)
//         {
//             int temp = vec[left];
//             vec[left] = vec[right];
//             vec[right] = temp;
//
//             left++;
//             right--;
//         }
//     }
//
//     vec[low] = vec[right];
//     vec[right] = pivot;
//
//     return right;
// }
//
// void quickSortUtil(std::vector<int> &vec, int low, int high)
// {
//     if (low >= high)
//     {
//         return;
//     }
//
//     int index = partition(vec, low, high);
//
//     quickSortUtil(vec, low, index-1);
//     quickSortUtil(vec, index+1, high);
// }
//
// void quickSort(std::vector<int> &vec)
// {
//     quickSortUtil(vec, 0, vec.size()-1);
// }
//
// int main()
// {
//     std::vector<int> vec = {4, 1, 2, 3, 5, 9, 7, 8, 6};
//
//     for (auto i = vec.begin(); i != vec.end(); ++i)
//     {
//         std::cout << *i << " ";
//     }
//     std::cout << std::endl;
//
//     quickSort(vec);
//
//     for (int i = 0; i < vec.size(); ++i)
//     {
//         std::cout << vec[i] << " ";
//     }
//     std::cout << std::endl;
//
//     return 0;
// }





#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int partition(std::vector<T> &vec, int low, int high)
{
    T pivot_element = vec[low];

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
            T temp = vec[left];
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

template <typename T>
void quickSortUtil(std::vector<T> &vec, int low, int high)
{
    if (low >= high)
    {
      return;
    }

    int partition_index = partition(vec, low, high);

    quickSortUtil(vec, low, partition_index-1);
    quickSortUtil(vec, partition_index+1, high);
}

template <typename T>
void quickSort(std::vector<T> &vec)
{
    quickSortUtil(vec, 0, vec.size()-1);
}

int main()
{
    std::vector<float> vec = {7.7, 2.2, 9.9, 1.1, 3.3, 8.8, 6.6, 4.4, 5.5};

    for_each(vec.begin(), vec.end(), [](float n){std::cout << n << " ";});
    std::cout << std::endl;

    quickSort(vec);

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
