#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str)
{
  int string_length = str.size();
  stringstream ss(str);
  vector<int> vec;

  char ch;
  int value;
  while (ss >> value)
  {
    vec.push_back(value);
    ss >> ch;
  }

  return vec;
}

int main()
{
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for(int i = 0; i < integers.size(); i++)
  {
    cout << integers[i] << "\n";
  }

  return 0;
}
