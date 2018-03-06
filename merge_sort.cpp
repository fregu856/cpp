// #include <iostream>
// #include <vector>
//
// void merge(std::vector<int> &vec, int low, int mid, int high)
// {
//     int left_low = low;
//     int left_high = mid;
//     int right_low = mid+1;
//     int right_high = high;
//
//     std::vector<int> temp(vec);
//
//     int current = low;
//
//     int left = left_low;
//     int right = right_low;
//
//     while (left <= left_high && right <= right_high)
//     {
//         if (temp[left] < temp[right])
//         {
//             vec[current] = temp[left];
//             current++;
//             left++;
//         }
//         else
//         {
//             vec[current] = temp[right];
//             current++;
//             right++;
//         }
//     }
//
//     while (left <= left_high)
//     {
//         vec[current] = temp[left];
//         current++;
//         left++;
//     }
// }
//
// void mergeSortUtil(std::vector<int> &vec, int low, int high)
// {
//     if (low >= high)
//     {
//         return;
//     }
//
//     int mid = low + (high-low)/2;
//
//     mergeSortUtil(vec, low, mid);
//     mergeSortUtil(vec, mid+1, high);
//
//     merge(vec, low, mid, high);
// }
//
// void mergeSort(std::vector<int> &vec)
// {
//     mergeSortUtil(vec, 0, vec.size()-1);
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
//     mergeSort(vec);
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

template <typename T>
void merge(std::vector<T> &vec, int low, int mid, int high)
{
    int left_low = low;
    int left_high = mid;
    int right_low = mid+1;
    int right_high = high;

    int left = left_low;
    int right = right_low;
    int current = low;

    std::vector<T> temp(vec);

    while (left <= left_high && right <= right_high)
    {
        if (temp[left] < temp[right])
        {
            vec[current] = temp[left];
            left++;
            current++;
        }
        else
        {
            vec[current] = temp[right];
            right++;
            current++;
        }
    }

    while (left <= left_high)
    {
        vec[current] = temp[left];
        left++;
        current++;
    }
}

template <typename T>
void mergeSortUtil(std::vector<T> &vec, int low, int high)
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

template <typename T>
void mergeSort(std::vector<T> &vec)
{
    mergeSortUtil(vec, 0, vec.size()-1);
}

int main()
{
    std::vector<float> vec = {7.7, 2.2, 9.9, 1.1, 3.3, 8.8, 6.6, 4.4, 5.5, 10.10};

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    mergeSort(vec);

    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
