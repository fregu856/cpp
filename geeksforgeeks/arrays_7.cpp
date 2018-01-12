#include <iostream>
#include <vector>

void printLeaders(std::vector<int> &vec)
{
    std::vector<int> maxs(vec.size());
    int max = vec[vec.size()-1];
    for (int i = vec.size()-1; i >= 0; --i)
    {
        if (vec[i] > max)
        {
            max = vec[i];
        }

        maxs[i] = max;
    }

    for (int i = 0; i < vec.size()-1; ++i)
    {
        if (vec[i] > maxs[i+1])
        {
            std::cout << vec[i] << " ";
        }
    }

    std::cout << vec[vec.size()-1] << std::endl;
}

int main()
{
    std::vector<int> vec = {16, 17, 4, 3, 5, 2};
    //std::vector<int> vec = {1, 2, 3, 4, 0};

    printLeaders(vec);

    return 0;
}
