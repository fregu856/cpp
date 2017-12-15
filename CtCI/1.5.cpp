#include <iostream>
#include <string>

std::string str = "aabccccca";
std::string str_uncompressable = "abcadef";

std::string compressString(std::string str)
{
    bool compressed = false;

    char current_letter, previous_letter;
    std::string compressed_string;
    int letter_count = 1;
    for (int i = 0; i < str.length(); ++i)
    {
        current_letter = str[i];

        if (i == 0)
        {
            previous_letter = current_letter;
            letter_count = 1;
        }
        else
        {
            if (current_letter == previous_letter)
            {
                letter_count++;
                compressed = true;
            }
            else
            {
                compressed_string.push_back(previous_letter);
                compressed_string.append(std::to_string(letter_count));
                letter_count = 1;
                previous_letter = current_letter;
            }
        }
    }

    compressed_string.push_back(previous_letter);
    compressed_string.append(std::to_string(letter_count));

    if (compressed)
    {
        return compressed_string;
    }
    else
    {
        return str;
    }
}

int main()
{
    std::cout << "Original string: " << str << std::endl;
    std::cout << "Compressed string: " << compressString(str) << std::endl;

    std::cout << "Original string: " << str_uncompressable << std::endl;
    std::cout << "Compressed string: " << compressString(str_uncompressable) << std::endl;

    return 0;
}
