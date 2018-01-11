#include <iostream>
#include <vector>

int maxDiff(std::vector<int> &vec)
{
    int max_diff = 0;
    int min = vec[0];

    for (int i = 0; i < vec.size(); ++i)
    {
        int diff = vec[i] - min;
        if (diff > max_diff)
        {
            max_diff = diff;
        }

        if (vec[i] < min)
        {
            min = vec[i];
        }
    }

    return max_diff;
}

int main()
{
    std::vector<int> vec = {9, 10, 1, 2, 8, 7};
    //std::vector<int> vec = {2, 3, 4, 5, 10, 6, 4, 8 ,1};
    //std::vector<int> vec = {7, 9, 5, 6, 3, 2};

    std::cout << maxDiff(vec) << std::endl;

    return 0;
}
