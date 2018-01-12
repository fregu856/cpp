#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findSubarrayWithSum(std::vector<int> &vec, int value)
{
    std::unordered_map<int, int> hash_table;
    int sum = 0;
    std::vector<int> output;

    for (int i = 0; i < vec.size(); ++i)
    {
        sum += vec[i];

        if (sum == value)
        {
            output = {0, i};
            return output;
        }

        if (hash_table.find(sum-value) != hash_table.end())
        {
            output = {hash_table[sum-value]+1, i};
            return output;
        }

        hash_table[sum] = i;
    }

    output = {-1, -1};
    return output;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 7, 5};
    int value = 12;

    std::vector<int> output = findSubarrayWithSum(vec, value);

    std::cout << "From: " << output[0] << ", to: " << output[1] << std::endl;

    return 0;
}
