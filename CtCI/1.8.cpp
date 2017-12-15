#include <iostream>
#include <string>

std::string str = "waterbottle";
std::string sub_str = "erbott";
std::string str_rotation = "erbottlewat";

bool isSubstring(std::string str, std::string sub_str)
{
    int index = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if (index == sub_str.length())
        {
            return true;
        }

        if (str[i] == sub_str[index])
        {
            index++;
        }
        else
        {
            index = 0;
        }
    }

    return index == sub_str.length();
}

bool isRotation(std::string str, std::string rot_str)
{
   // TODO!
}

int main()
{
    if (isSubstring(str, sub_str))
    {
        std::cout << "Substring!" << std::endl;
    }
    else
    {
        std::cout << "NOT substring!" << std::endl;
    }

    if (isRotation(str, str_rotation))
    {
        std::cout << "Rotation!" << std::endl;
    }
    else
    {
        std::cout << "NOT rotation!" << std::endl;
    }

    return 0;
}
