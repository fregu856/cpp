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

int get_size_of_region(int i, int j, vector< vector<int> > &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int region_size;

    if (i < n && i >= 0 && j < m && j >= 0)
    {
        if (grid[i][j] == 0)
        {
            region_size = 0;
        }
        else
        {
            region_size = 1;
            grid[i][j] = 0;
            region_size += get_size_of_region(i-1, j-1, grid);
            region_size += get_size_of_region(i-1, j, grid);
            region_size += get_size_of_region(i-1, j+1, grid);
            region_size += get_size_of_region(i, j-1, grid);
            region_size += get_size_of_region(i, j+1, grid);
            region_size += get_size_of_region(i+1, j-1, grid);
            region_size += get_size_of_region(i+1, j, grid);
            region_size += get_size_of_region(i+1, j+1, grid);
        }
    }
    else
    {
        region_size = 0;
    }

    return region_size;
}

int get_biggest_region(vector< vector<int> > grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int biggest_region_size = 0;
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            int region_size = get_size_of_region(row, col, grid);
            biggest_region_size = max(biggest_region_size, region_size);
        }
    }

    return biggest_region_size;
}

int main()
{
    int n;-
    cin >> n;
    int m;
    cin >> m;

    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0; grid_i < n; grid_i++)
    {
       for(int grid_j = 0; grid_j < m; grid_j++)
       {
          cin >> grid[grid_i][grid_j];
       }
    }

    cout << get_biggest_region(grid) << endl;

    return 0;
}
