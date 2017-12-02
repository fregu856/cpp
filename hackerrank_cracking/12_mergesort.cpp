#include <bits/stdc++.h>

using namespace std;

long countInversions(long first_ind, long last_ind, vector<int>  &arr)
{
    // // n^2 solution:
    // int n = arr.size();
    // int num_inversions = 0;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = i + 1; j < n; ++j)
    //     {
    //         if (arr[i] > arr[j])
    //         {
    //             num_inversions++;
    //         }
    //     }
    // }
    // return num_inversions;

    // nlog(n) solution:

    long num_inversions;

    if (first_ind >= last_ind) // (if just one element)
    {
        num_inversions = 0;
    }
    else if (first_ind == last_ind - 1) // (if only two elements)
    {
        if (arr[first_ind] > arr[last_ind])
        {
            swap(arr[first_ind], arr[last_ind]);
            num_inversions = 1;
        }
        else
        {
            num_inversions = 0;
        }
    }
    else
    {
        long mid_ind = first_ind + (last_ind - first_ind)/2;
        num_inversions = countInversions(first_ind, mid_ind, arr) + countInversions(mid_ind+1, last_ind, arr);

        long ind1 = first_ind;
        long ind2 = mid_ind+1;
        vector<int> new_arr(last_ind-first_ind+1);
        long i = 0;
        while (!(ind1 > mid_ind && ind2 > last_ind))
        {
            if (ind1 > mid_ind)
            {
                new_arr[i] = arr[ind2];
                ind2++;
            }
            else if (ind2 > last_ind)
            {
              new_arr[i] = arr[ind1];
              ind1++;
            }
            else if (arr[ind1] > arr[ind2])
            {
                new_arr[i] = arr[ind2];
                ind2++;
                num_inversions += mid_ind - ind1 + 1;
            }
            else
            {
              new_arr[i] = arr[ind1];
              ind1++;
            }

            i++;
        }
        for (long i = 0; i < new_arr.size(); ++i)
        {
            arr[first_ind+i] = new_arr[i];
        }

    }

    return num_inversions;
}

int main()
{
    int t;
    cin >> t;

    for(int a0 = 0; a0 < t; ++a0)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; ++arr_i)
        {
           cin >> arr[arr_i];
        }

        long result = countInversions(0, n-1, arr);
        cout << result << endl;
    }

    return 0;
}
