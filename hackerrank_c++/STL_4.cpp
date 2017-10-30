#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int no_of_queries;
    cin >> no_of_queries;

    set<int> s;
    int type, value;
    for (int i = 0; i < no_of_queries; ++i)
    {
        cin >> type >> value;

        if (type == 1)
        {
            s.insert(value);
        }

        else if (type == 2)
        {
            if (s.find(value) != s.end())
            {
                s.erase(value);
            }
            else
            {

            }
        }

        else if (type == 3)
        {
            if (s.find(value) != s.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
