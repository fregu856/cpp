#include <iostream>
#include <vector>
#include <string>

int findStringUtil(std::vector<std::string> &vec, std::string str, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high-low)/2;
    int string_mid = mid;

    while (vec[string_mid] == "")
    {
        string_mid++;
        if (string_mid > high)
        {
            break;
        }
    }

    if (string_mid > high)
    {
        return findStringUtil(vec, str, low, mid-1);
    }

    if (vec[string_mid] == str)
    {
        return string_mid;
    }
    else if (str > vec[string_mid])
    {
        return findStringUtil(vec, str, mid+1, high);
    }
    else
    {
        return findStringUtil(vec, str, low, mid-1);
    }
}

int findString(std::vector<std::string> &vec, std::string str)
{
    return findStringUtil(vec, str, 0, vec.size()-1);
}

int main()
{
    std::vector<std::string> vec = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    int index = findString(vec, "ball");

    std::cout << index << std::endl;

    return 0;
}
