#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

std::vector< std::pair<int, int> > findPairs(std::vector<int> &vec, int sum)
{
    std::unordered_set<int> prev_values;
    std::vector< std::pair<int, int> > pairs;

    for (int i = 0; i < vec.size(); ++i)
    {
        int value = vec[i];
        if (prev_values.find(sum-value) != prev_values.end())
        {
            std::pair<int, int> pair = std::make_pair(sum-value, value);
            pairs.push_back(pair);
        }

        prev_values.insert(value);
    }

    return pairs;
}

int main()
{
    std::vector<int> vec = {5, -1, 2, 0, 3, 4, -2, 1};
    std::vector< std::pair<int, int> > pairs = findPairs(vec, 4);

    for (int i = 0; i < pairs.size(); ++i)
    {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;
    }

    return 0;
}
