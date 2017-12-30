#include <iostream>
#include <string>

void computePermutationsUtil(std::string str, int first_index)
{
    int last_index = str.length()-1;

    if (first_index == last_index)
    {
        std::cout << str << std::endl;
        return;
    }

    computePermutationsUtil(str, first_index+1);
    for (int i = first_index+1; i <= last_index; ++i)
    {
        std::string new_string = str;
        new_string[i] = str[first_index];
        new_string[first_index] = str[i];
        computePermutationsUtil(new_string, first_index+1);
    }
}

void computePermutations(std::string str)
{
    computePermutationsUtil(str, 0);
}

int main()
{
    std::string str = "hej";

    computePermutations(str);

    return 0;
}
