#include <iostream>
#include <vector>

void merge(std::vector<int> &A, std::vector<int> &B)
{
    int current = A.size()-1;
    int B_right = B.size()-1;
    int A_right;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == -1)
        {
            A_right = i-1;
            break;
        }
    }

    while (A_right >= 0 && B_right >= 0)
    {
        if (A[A_right] > B[B_right])
        {
            A[current] = A[A_right];
            current--;
            A_right--;
        }
        else
        {
            A[current] = B[B_right];
            current--;
            B_right--;
        }
    }

    while (B_right >= 0)
    {
        A[current] = B[B_right];
        current--;
        B_right--;
    }
}

int main()
{
    std::vector<int> A = {2, 3, 5, 8, -1, -1, -1, -1, -1};
    std::vector<int> B = {0, 1, 4, 6, 7};

    merge(A, B);

    for (int i = 0; i < A.size(); ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
