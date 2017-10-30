#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int no_of_values;
    cin >> no_of_values;

    vector<int> vec_data;
    int value;
    for (int i = 0; i < no_of_values; ++i)
    {
        cin >> value;
        vec_data.push_back(value);
    }

    sort(vec_data.begin(), vec_data.end());

    int no_of_queries;
    cin >> no_of_queries;

    vector<int> vec_queries;
    for (int i = 0; i < no_of_queries; ++i)
    {
        cin >> value;
        vec_queries.push_back(value);
    }

    for (int i = 0; i < vec_queries.size(); ++i)
    {
        int query = vec_queries[i];
        if(binary_search(vec_data.begin(), vec_data.end(), query))
        {
            vector<int>::iterator index;
            index = lower_bound(vec_data.begin(), vec_data.end(), query);

            cout << "Yes " << index + 1 - vec_data.begin()  << endl;
        }
        else
        {
            vector<int>::iterator index;
            index = lower_bound(vec_data.begin(), vec_data.end(), query);

            cout << "No " << index + 1 - vec_data.begin() << endl;
        }
    }

    return 0;
}
