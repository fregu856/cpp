#include <iostream>
#include <vector>

int findRotation(std::vector<int> &vec, int low, int high)
{
    int mid = low + (high-low)/2;

    if (vec[mid] > vec[mid+1])
    {
        return mid;
    }
    else if (vec[mid] < vec[mid-1])
    {
        return mid-1;
    }

    if (vec[mid] > vec[low])
    {
        return findRotation(vec, mid+1, high);
    }
    else
    {
        return findRotation(vec, low, mid-1);
    }
}

int findElementUtil(std::vector<int> &vec, int value, int low, int high)
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
    else if (value > vec[mid])
    {
        return findElementUtil(vec, value, mid+1, high);
    }
    else
    {
        return findElementUtil(vec, value, low, mid-1);
    }
}

int findElement(std::vector<int> &vec, int value)
{
    int rot_index = findRotation(vec, 0, vec.size()-1);

    if (vec[rot_index] == value)
    {
        return rot_index;
    }
    else if (value > vec[rot_index])
    {
        return -1;
    }
    else if (value >= vec[0])
    {
        return findElementUtil(vec, value, 0, rot_index-1);
    }
    else
    {
        return findElementUtil(vec, value, rot_index+1, vec.size()-1);
    }
}

int main()
{
    std::vector<int> vec = {4, 5, 6, 7, 8, 9, 10, 0, 2, 3};
    int index = findElement(vec, 2);

    std::cout << index << std::endl;

    return 0;
}
