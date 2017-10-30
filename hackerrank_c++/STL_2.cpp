#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int no_of_values;
    cin >> no_of_values;

    vector<int> vec;
    int value;
    for (int i = 0; i < no_of_values; ++i)
    {
        cin >> value;
        vec.push_back(value);
    }

    int pos_to_remove;
    cin >> pos_to_remove;

    vec.erase(vec.begin() + pos_to_remove-1);

    int range_a, range_b;
    cin >> range_a >> range_b;

    vec.erase(vec.begin() + range_a - 1, vec.begin() + range_b - 1);

    cout << vec.size() << endl;

    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
