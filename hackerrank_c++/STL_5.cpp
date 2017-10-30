#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int no_of_queries;
    cin >> no_of_queries;

    int type, value;
    string name;
    map<string, int> m;
    for (int i = 0; i < no_of_queries; ++i)
    {
        cin >> type;

        if (type == 1)
        {
            cin >> name;
            cin >> value;

            if (m.find(name) != m.end())
            {
                m[name] = m[name] + value;
            }
            else
            {
                m[name] = value;
            }
        }

        else if (type == 2)
        {
            cin >> name;

            if (m.find(name) != m.end())
            {
                m.erase(name);
            }
            else
            {

            }
        }

        else if (type == 3)
        {
            cin >> name;

            if (m.find(name) != m.end())
            {
                cout << m[name] << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
