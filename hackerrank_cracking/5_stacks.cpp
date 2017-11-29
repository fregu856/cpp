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

bool is_balanced(string expression)
{
    bool return_bool = true;

    map<char, char> bracket_map;
    bracket_map['}'] = '{';
    bracket_map[')'] = '(';
    bracket_map[']'] = '[';

    stack<char> bracket_stack;
    for (auto i = expression.begin(); i != expression.end(); ++i)
    {
        char c = *i;

        if (c == '[' || c == '(' || c == '{')
        {
            bracket_stack.push(c);
        }
        else if (bracket_stack.size() == 0)
        {
            return_bool = false;
            break;
        }
        else
        {
            if (bracket_map[c] != bracket_stack.top())
            {
                return_bool = false;
                break;
            }
            bracket_stack.pop();
        }
    }

    if (bracket_stack.size() > 0)
    {
       return_bool = false;
    }

    return return_bool;
}

int main()
{
    int t;
    cin >> t;

    for(int a0 = 0; a0 < t; a0++)
    {
        string expression;
        cin >> expression;

        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
