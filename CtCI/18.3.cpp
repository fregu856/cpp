#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int getRandom(int max)
{
    std::srand(std::time(nullptr));
    return std::rand() % (max+1);
}

std::vector<int> pickM(std::vector<int> &vec, int m)
{
    std::vector<int> subset(m);
    for (int i = 0; i < m; ++i)
    {
        subset[i] = vec[i];
    }

    for (int i = m; i < vec.size(); ++i)
    {
        int insert_index = getRandom(i);
        if (insert_index < m)
        {
            subset[insert_index] = vec[i];
        }
    }

    return subset;
}

int main()
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7 ,8, 9 ,10};
    int m = 5;

    std::vector<int> subset = pickM(vec, m);

    for (int i = 0; i < subset.size(); ++i)
    {
        std::cout << subset[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
