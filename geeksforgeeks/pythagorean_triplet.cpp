#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

bool isPairWithSquareSum(std::vector<int> &vec, int value, int skip_index)
{
    std::unordered_set<int> hash_set;

    for (int i = 0; i < vec.size(); ++i)
    {
        if (i == skip_index)
        {
            continue;
        }

        if (hash_set.find(value - pow(vec[i], 2)) != hash_set.end())
        {
            return true;
        }

        hash_set.insert(pow(vec[i], 2));
    }

    return false;
}

bool pythagoreanTriplet(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        if (isPairWithSquareSum(vec, pow(vec[i], 2), i))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int> vec = {3, 1, 4, 6, 5};
    //std::vector<int> vec = {10, 4, 6, 12, 5};

    if (pythagoreanTriplet(vec))
    {
        std::cout << "True!" << std::endl;
    }
    else
    {
        std::cout << "False!" << std::endl;
    }

    return 0;
}
