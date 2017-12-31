#include <iostream>
#include <vector>

int computeNumberOfWaysUtil(int n, int denom, std::vector< std::vector<int> > &cache)
{
    if (n <= 0)
    {
        return 0;
    }

    if (cache[n][denom] != -1)
    {
        return cache[n][denom];
    }

    int next_denom;
    switch (denom)
    {
        case 25:
            next_denom = 10;
            break;
        case 10:
            next_denom = 5;
            break;
        case 5:
            next_denom = 1;
            break;
        case 1:
            cache[n][denom] = 1;
            return 1;
    }

    int num_ways = 0;
    for (int i = 0; i*denom <= n; ++i)
    {
        num_ways += computeNumberOfWaysUtil(n - i*denom, next_denom, cache);
    }

    cache[n][denom] = num_ways;
    return num_ways;
}

int computeNumberOfWays(int n)
{
    std::vector< std::vector<int> > cache(n+1, std::vector<int>(25+1, -1));
    return computeNumberOfWaysUtil(n, 25, cache);
}

int main()
{
    int n = 100;
    int num_ways = computeNumberOfWays(n);
    std::cout << "Number of ways to represent " << n << " cents: " << num_ways << std::endl;

    return 0;
}
