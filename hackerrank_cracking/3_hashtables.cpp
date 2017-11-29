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

bool ransom_note(vector<string> magazine, vector<string> ransom)
{
    unordered_map<string, int> magazine_table;
    for (auto i = magazine.begin(); i != magazine.end(); ++i)
    {
        if (magazine_table.find(*i) == magazine_table.end())
        {
            magazine_table[*i] = 1;
        }
        else
        {
            magazine_table[*i]++;
        }
    }

    bool return_bool = true;
    for (auto i = ransom.begin(); i != ransom.end(); ++i)
    {
        if (magazine_table.find(*i) != magazine_table.end())
        {
            if (magazine_table[*i] > 0)
            {

                magazine_table[*i]--;
            }
            else
            {
                return_bool = false;
                break;
            }
        }
        else
        {
            return_bool = false;
            break;
        }
    }

    return return_bool;
}

int main(){
    int m;
    int n;

    cin >> m >> n;

    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++)
    {
       cin >> magazine[magazine_i];
    }

    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++)
    {
       cin >> ransom[ransom_i];
    }

    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
