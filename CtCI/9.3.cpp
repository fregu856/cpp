#include <iostream>
#include <vector>

// n:
int findMagicIndex(std::vector<int> A)
{
    for (int i = 0; i < A.size(); ++i)
    {
        if (i == A[i])
        {
            return i;
        }
        else if (A[i] > i)
        {
            return -1;
        }
    }
}

// log(n):
int findMagicIndex_optimized_Util(std::vector<int> &A, int first_index, int last_index)
{
    if (first_index == last_index)
    {
        if (first_index == A[first_index])
        {
            return first_index;
        }
        else
        {
            return -1;
        }
    }

    int mid_index = first_index + (last_index - first_index)/2;
    int mid_value = A[mid_index];
    if (mid_index == mid_value)
    {
        return mid_index;
    }
    else if (mid_value < mid_index)
    {
        return findMagicIndex_optimized_Util(A, mid_index, last_index);
    }
    else
    {
        return findMagicIndex_optimized_Util(A, first_index, mid_index);
    }
}

int findMagicIndex_optimized(std::vector<int> &A)
{
    return findMagicIndex_optimized_Util(A, 0, A.size()-1);
}

int main()
{
    std::vector<int> A = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    std::vector<int> A_not = {1, 2, 4, 5, 8, 10};

    int magic_index = findMagicIndex(A);
    std::cout << "Magic index: " << magic_index << std::endl;

    magic_index = findMagicIndex_optimized(A);
    std::cout << "Magic index: " << magic_index << std::endl;

    return 0;
}
