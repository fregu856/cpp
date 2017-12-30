#include <iostream>
#include <set>
#include <string>

std::set<std::string> printCombinationsUtil(int n, std::set<std::string> combinations)
{
    if (n == 1)
    {
        combinations.insert("()");
        return combinations;
    }

    combinations = printCombinationsUtil(n-1, combinations);
    std::set<std::string> new_combinations;
    for (auto i = combinations.begin(); i != combinations.end(); ++i)
    {
        std::string comb = *i;
        new_combinations.insert("(" + comb + ")");
        new_combinations.insert("()" + comb);
        new_combinations.insert(comb + "()");
    }

    return new_combinations;
}

void printCombinations(int n)
{
    std::set<std::string> combinations;
    combinations = printCombinationsUtil(n, combinations);
    for (auto i = combinations.begin(); i != combinations.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
}

int main()
{
    printCombinations(3);

    return 0;
}
