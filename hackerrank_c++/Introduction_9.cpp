#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, q;

  cin >> n >> q;

  vector< vector<int> > vec_of_vecs;

  for (int i = 0; i < n; ++i)
  {
    int k;
    vector<int> vec;

    cin >> k;

    for (int j = 0; j < k; ++j)
    {
      int value;
      cin >> value;
      vec.push_back(value);
    }

    vec_of_vecs.push_back(vec);
  }

  for (int l = 0; l < q; ++l)
  {
    int i, j;
    cin >> i >> j;

    cout << vec_of_vecs[i][j] << endl;
  }

  return 0;
}
