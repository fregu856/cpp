#include <bits/stdc++.h>
#include <algorithm>

// REALLY poorly formulated problem

using namespace std;

class IceCream
{
    public:
        int flavor;
        int index;

        IceCream(int flavor_val, int index_val)
        {
            flavor = flavor_val;
            index = index_val;
        }
};

int binarySearch(int first, int last, vector<IceCream> arr, int search)
{
    // cout << "binarySearch, first: " << first << ", last: " << last << ", search:" << search << endl;

    if (first == last)
    {
        if (arr[first].flavor == search)
        {
            return arr[first].index;
        }
        else
        {
            return -1;
        }
    }

    if (search == arr[first].flavor)
    {
        return arr[first].index;
    }

    if (search == arr[last].flavor)
    {
        return arr[last].index;
    }

    if (first > last)
    {
        return -1;
    }

    int mid_point = first + (last-first)/2;
    // cout << "mid_point: " << mid_point << endl;
    // cout << "arr[mid_point].flavor: " << arr[mid_point].flavor << endl;
    if (search == arr[mid_point].flavor)
    {
        return arr[mid_point].index;
    }
    else if (search < arr[mid_point].flavor)
    {
        return binarySearch(first, mid_point-1, arr, search);
    }
    else
    {
        return binarySearch(mid_point+1, last, arr, search);
    }
}

bool compare(IceCream ice_cream1, IceCream ice_cream2)
{
    return (ice_cream1.flavor < ice_cream2.flavor);
}

int main()
{
    int t;
    int n, m;
    cin >> t;

    for(int test = 0; test < t; test++)
    {
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
        {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), &compare);
        // for (auto i = arr.begin(); i != arr.end(); ++i)
        // {
        //   cout << i->flavor << endl;
        // }

        for(int i = 0; i < n - 1 ; i++)
        {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor)
            {
                int index = binarySearch(i + 1, n - 1, arr, search);
                if( index != -1 )
                {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;
                }
            }
        }

    }

}
