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

int number_needed(string a, string b)
{
    int num_common_letters = 0;

    map<char, int> a_map, b_map;

    for (int i = 0; i < a.length(); ++i)
    {
        if (a_map.find(a[i]) == a_map.end())
        {
            a_map[a[i]] = 1;
        }
        else
        {
            ++a_map[a[i]];
        }
    }

    for (int i = 0; i < b.length(); ++i)
    {
        if (b_map.find(b[i]) == b_map.end())
        {
            b_map[b[i]] = 1;
        }
        else
        {
            ++b_map[b[i]];
        }
    }

    for (auto i = a_map.begin(); i != a_map.end(); ++i)
    {
        char letter = i->first;
        if (b_map.find(letter) != b_map.end())
        {
            num_common_letters += min(i->second, b_map[letter]);
        }
    }

    return (a.length() - num_common_letters + b.length() - num_common_letters);
}

int main()
{
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
