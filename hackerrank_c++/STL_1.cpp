#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int no_of_values;

    cin >> no_of_values;

    vector<int> vec;

    int value;
    for (int i = 0; i < no_of_values; ++i)
    {
        cin >> value;
        vec.push_back(value);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
