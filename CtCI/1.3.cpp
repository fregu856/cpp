#include <iostream>
#include <string>
#include <unordered_map>

std::string first_string = "abcd";
std::string second_string = "bahdc";

bool isPermutation(std::string first, std::string second)
{
    std::unordered_map<char, int> letter_freq;

    char current_letter;
    for (int i = 0; i < first.length(); ++i)
    {
        current_letter = first[i];
        if (letter_freq.find(current_letter) == letter_freq.end())
        {
            letter_freq[current_letter] = 1;
        }
        else
        {
            letter_freq[current_letter]++;
        }
    }

    for (int i = 0; i < second.length(); ++i)
    {
        current_letter = second[i];
        if (letter_freq.find(current_letter) == letter_freq.end())
        {
            return false;
        }
        else if (letter_freq[current_letter] == 0)
        {
            return false;
        }
        else
        {
            letter_freq[current_letter]--;
        }
    }
    return true;
}

int main()
{
    if (isPermutation(first_string, second_string))
    {
        std::cout << "The second string is a permutation of the first string" << std::endl;
    }
    else
    {
        std::cout << "The second string is NOT a permutation of the first string" << std::endl;
    }

    return 0;
}
