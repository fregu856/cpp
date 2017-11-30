#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <iomanip>

using namespace std;

// https://stackoverflow.com/questions/10657503/find-running-median-from-a-stream-of-integers
// http://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

int main()
{
    int n;
    cin >> n;

    cout << setprecision(1) << fixed;

    // n*n*log(n) solution:
    
    // vector<int> integers;
    // int read_value, num_integers;
    // double median;
    // for(int a_i = 0 ;a_i < n; ++a_i)
    // {
    //     cin >> read_value;
    //     integers.push_back(read_value);
    //
    //     sort(integers.begin(), integers.end());
    //
    //     num_integers = integers.size();
    //     if (num_integers % 2 == 0) // (even)
    //     {
    //         median = (integers[num_integers/2] + integers[num_integers/2 - 1])/2.0;
    //     }
    //     else // (odd)
    //     {
    //         median = (double) integers[num_integers/2];
    //     }
    //
    //     cout << median << endl;
    // }

    // n*log(n) solution:

    priority_queue<int> max_heap_left;
    priority_queue<int, vector<int>, greater<int>> min_heap_right;

    int read_value;
    double median;
    for(int a_i = 0 ;a_i < n; ++a_i)
    {
        cin >> read_value;

        if (a_i == 0)
        {
            median = (double) read_value;
            max_heap_left.push(read_value);
        }
        else
        {
            // insert new element:
            if (read_value < max_heap_left.top())
            {
                max_heap_left.push(read_value);
            }
            else
            {
                min_heap_right.push(read_value);
            }

            // balance heaps if necessary:
            if (max_heap_left.size() > min_heap_right.size() + 1)
            {
                min_heap_right.push(max_heap_left.top());
                max_heap_left.pop();
            }
            else if (min_heap_right.size() > max_heap_left.size() + 1)
            {
                max_heap_left.push(min_heap_right.top());
                min_heap_right.pop();
            }

            // compute median:
            if (max_heap_left.size() == min_heap_right.size())
            {
                median = (max_heap_left.top() + min_heap_right.top())/2.0;
            }
            else if (max_heap_left.size() > min_heap_right.size())
            {
                median = (double) max_heap_left.top();
            }
            else
            {
                median = (double) min_heap_right.top();
            }
        }

        cout << median << endl;
    }

    return 0;
}
