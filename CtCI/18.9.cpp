#include <iostream>
#include <vector>
#include <queue>
#include <functional> // (std::greater)

float getMedian(std::priority_queue<int> &max_heap, std::priority_queue<int, std::vector<int>, std::greater<int> > &min_heap)
{
    int max_heap_size = max_heap.size();
    int min_heap_size = min_heap.size();
    if (max_heap_size == 1+min_heap_size)
    {
        return max_heap.top();
    }
    else if (min_heap_size == 1+max_heap_size)
    {
        return min_heap.top();
    }
    else if (max_heap_size == min_heap_size)
    {
        float median = (min_heap.top() + max_heap.top())/2.0;
        return median;
    }
    else if (max_heap_size == 2+min_heap_size)
    {
        int value = max_heap.top();
        max_heap.pop();

        min_heap.push(value);

        return max_heap.top();
    }
    else if (min_heap_size == 2+max_heap_size)
    {
        int value = min_heap.top();
        min_heap.pop();

        max_heap.push(value);

        return min_heap.top();
    }
    else
    {
        return -999;
    }
}

float findStreamingMedian(int number, std::priority_queue<int> &max_heap, std::priority_queue<int, std::vector<int>, std::greater<int> > &min_heap)
{
    if (max_heap.empty() && min_heap.empty())
    {
        max_heap.push(number);
        return number;
    }

    int current_median = getMedian(max_heap, min_heap);
    if (number > current_median)
    {
        min_heap.push(number);
    }
    else
    {
        max_heap.push(number);
    }

    return getMedian(max_heap, min_heap);
}

void findStreamingMedian(std::vector<int> &numbers)
{
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;

    float median;
    std::vector<int> processed_numbers;
    for (auto i = numbers.begin(); i != numbers.end(); ++i)
    {
        int number = *i;
        median = findStreamingMedian(number, max_heap, min_heap);
        processed_numbers.push_back(number);

        std::cout << "Processed numbers: ";
        for (auto i = processed_numbers.begin(); i != processed_numbers.end(); ++i)
        {
            std::cout << *i << " ";
        }
        std::cout << ", Median: " << median << std::endl;
    }
}

int main()
{
    std::vector<int> numbers = {1, 3, 0, 4, 5, 3, 3, 4, 7, 8, 1, 9, 2, 3, 5};
    findStreamingMedian(numbers);

    return 0;
}
