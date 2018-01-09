#include <iostream>
#include <vector>
#include <unordered_map>

void findSubarrayWithSum(std::vector<int> &vec, int sum)
{
    std::unordered_map<int, int> hash_table;

    int current_sum = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        current_sum += vec[i];

        if (current_sum == sum)
        {
            std::cout << 0 << " to " << i << std::endl;
            return;
        }

        if (hash_table.find(current_sum-sum) != hash_table.end())
        {
            std::cout << hash_table[current_sum-sum]+1 << " to " << i << std::endl;
            return;
        }

        hash_table[current_sum] = i;
    }

    std::cout << "Couldn't find subarray!" << std::endl;
}


int main()
{
    std::vector<int> vec = {2, 0, 4, 3, 5, 1};

    findSubarrayWithSum(vec, 4);

    return 0;
}
