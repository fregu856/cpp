#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int minimumNumPlatforms(std::vector<int> &arrivals, std::vector<int> &departures)
{
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    int max_num_trains = 0;

    for (int i = 0; i < arrivals.size(); ++i)
    {
        min_heap.push(departures[i]);

        while (min_heap.top() < arrivals[i])
        {
            min_heap.pop();
        }

        int num_trains = min_heap.size();
        if (num_trains > max_num_trains)
        {
            max_num_trains = num_trains;
        }
    }

    return max_num_trains;
}

int main()
{
    std::vector<int> arrivals = {900, 940, 950, 1100, 1500, 1800};
    std::vector<int> departures = {910, 1200, 1120, 1130, 1900, 2000};

    std::cout << minimumNumPlatforms(arrivals, departures) << std::endl;

    return 0;
}
