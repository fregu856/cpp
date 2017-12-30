#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

void addProducts(std::set<int> &s, int value)
{
    s.insert(value*3);
    s.insert(value*5);
    s.insert(value*7);
}

int popMin(std::set<int> &s)
{
    int min_value = *(s.begin());
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        int value = *i;
        if (value < min_value)
        {
            min_value = value;
        }
    }
    s.erase(min_value);

    return min_value;
}

int getKthNumber(int k)
{
    std::set<int> candidates;

    int kth_number = 1;
    addProducts(candidates, kth_number);

    for (int i = 0; i < k; ++i)
    {
        kth_number = popMin(candidates);
        addProducts(candidates, kth_number);
    }

    return kth_number;
}

int main()
{
    int k;
    while (true)
    {
        std::cin >> k;
        int kth_number = getKthNumber(k);

        std::cout << "Kth number: " << kth_number << std::endl;
        std::cout << "###########" << std::endl;
    }

    return 0;
}
