#include <iostream>
#include <vector>

int findMissingNumber(std::vector<int> &vec)
{
    int n = vec.size()+1;
    std::vector<bool> present(n, false);

    for (int i = 0; i < vec.size(); ++i)
    {
        present[vec[i]-1] = true;
    }

    for (int i = 0; i < present.size(); ++i)
    {
        if (!present[i])
        {
            return (i+1);
        }
    }

    return -1;
}

int main()
{
    //std::vector<int> vec = {1, 2, 3, 5};
    std::vector<int> vec = {10, 8, 1, 3, 2, 5, 4, 7 ,6};

    std::cout << findMissingNumber(vec) << std::endl;

    return 0;
}
