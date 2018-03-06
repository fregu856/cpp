// #include <iostream>
// #include <vector>
//
// int binarySearchUtil(std::vector<int> &vec, int value, int low, int high)
// {
//     if (low > high)
//     {
//         return -1;
//     }
//
//     int mid = low + (high-low)/2;
//
//     if (value == vec[mid])
//     {
//         return mid;
//     }
//     else if (value < vec[mid])
//     {
//         return binarySearchUtil(vec, value, low, mid-1);
//     }
//     else
//     {
//         return binarySearchUtil(vec, value, mid+1, high);
//     }
// }
//
// int binarySearch(std::vector<int> &vec, int value)
// {
//     return binarySearchUtil(vec, value, 0, vec.size()-1);
// }
//
// int main()
// {
//     std::vector<int> vec = {1, 3, 4, 5, 7, 9, 10};
//
//     std::cout << binarySearch(vec, 2) << std::endl;
//
//     return 0;
// }

































#include <iostream>
#include <vector>

template <typename T>
int binarySearchUtil(std::vector<T> &vec, T value, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high-low)/2;

    if (value == vec[mid])
    {
        return mid;
    }
    else if (value < vec[mid])
    {
        return binarySearchUtil(vec, value, low, mid-1);
    }
    else
    {
        return binarySearchUtil(vec, value, mid+1, high);
    }
}

template <typename T>
int binarySearch(std::vector<T> &vec, T value)
{
    return binarySearchUtil(vec, value, 0, vec.size()-1);
}

int main()
{
    std::vector<int> vec = {1, 3, 4, 5, 8, 9, 10};

    std::cout << binarySearch(vec, 4) << std::endl;

    return 0;
}
