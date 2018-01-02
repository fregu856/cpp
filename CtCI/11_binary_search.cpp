#include <iostream>
#include <vector>

int binarySearchUtil(std::vector<int> &vec, int value, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high-low)/2;
    if (vec[mid] == value)
    {
        return mid;
    }
    else if (value > vec[mid])
    {
        return binarySearchUtil(vec, value, mid+1, high);
    }
    else // (value < vec[mid])
    {
        return binarySearchUtil(vec, value, low, mid-1);
    }
}

int binarySearch(std::vector<int> &vec, int value)
{
    return binarySearchUtil(vec, value, 0, vec.size()-1);
}

int main()
{
    std::vector<int> vec = {1, 3, 4, 7, 8, 12};
    int index = binarySearch(vec, 8);
    std::cout << index << std::endl;

    return 0;
}
