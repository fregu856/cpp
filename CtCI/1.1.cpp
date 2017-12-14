#include <iostream>
#include <string>
#include <unordered_set>

std::string unique_string = "Hejdu";
std::string not_unique_string = "hejhej";

bool uniqueChars(std::string input_string)
{
    std::unordered_set<char> letters;

    char current_letter;
    for (int i = 0; i < input_string.length(); ++i)
    {
        current_letter = input_string[i];
        if (letters.find(current_letter) == letters.end())
        {
            letters.insert(current_letter);
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string my_string = not_unique_string;

    if (uniqueChars(my_string))
    {
        std::cout << "The string has got unique characters" << std::endl;
    }
    else
    {
        std::cout << "The string has NOT got unique characters" << std::endl;
    }
}
