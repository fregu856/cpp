#include <iostream>
#include <string>

std::string my_string = "Mr John Smith";

std::string replaceSpaces(std::string str)
{
    std::string return_string;

    char current_letter;
    for (int i = 0; i < str.length(); ++i)
    {
        current_letter = str[i];
        if (current_letter == ' ')
        {
            return_string.push_back('%');
            return_string.push_back('2');
            return_string.push_back('0');
        }
        else
        {
          return_string.push_back(current_letter);
        }
    }

    return return_string;
}

int main()
{
    std::cout << "Original string: " << my_string << std::endl;
    std::cout << "Modified string: " << replaceSpaces(my_string) << std::endl;

    return 0;
}
