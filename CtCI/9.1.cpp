#include <iostream>
#include <vector>

const int MAX = 100;

int numWaysToRun(int n)
{
    if (n < 1)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return n;
    }
    else if (n == 3)
    {
        return 4;
    }

    return numWaysToRun(n-1) + numWaysToRun(n-2) + numWaysToRun(n-3);
}

////////////////////////////////////////////////////////////////////////////////

int numWaysToRun_DP_Util(int n, std::vector<int> &cache)
{
    if (n < 1)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return n;
    }
    else if (n == 3)
    {
        return 4;
    }

    if (cache[n] != -1)
    {
        return cache[n];
    }

    cache[n] = numWaysToRun_DP_Util(n-1, cache) + numWaysToRun_DP_Util(n-2, cache) + numWaysToRun_DP_Util(n-3, cache);
    return cache[n];
}

int numWaysToRun_DP(int n)
{
    std::vector<int> cache(MAX, -1);
    return numWaysToRun_DP_Util(n, cache);
}

int main()
{
    int n = 35;

    int num_ways = numWaysToRun(n);
    std::cout << "Number of possible ways to run up the stairs: " << num_ways << std::endl;


    int num_ways_DP = numWaysToRun_DP(n);
    std::cout << "Number of possible ways to run up the stairs: " << num_ways_DP << std::endl;

    return 0;
}
