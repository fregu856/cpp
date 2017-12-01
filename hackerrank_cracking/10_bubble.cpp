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

using namespace std;


int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++)
    {
       cin >> a[a_i];
    }

    int num_swaps_total = 0;
    for (int iteration = 0; iteration < n; ++iteration)
    {
        int num_swaps = 0;
        for (int i = 0; i < a.size()-1; ++i)
        {
            if (a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                ++num_swaps;
                ++num_swaps_total;
            }
        }

        if (num_swaps == 0)
        {
            break;
        }
    }

    cout << "Array is sorted in " << num_swaps_total << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size()-1] << endl;

    return 0;
}
