#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void printPhrase(int value)
{
    std::string value_str = std::to_string(value);

    int negative = false;
    if (value < 0)
    {
        negative = true;
        value_str.erase(value_str.begin());
    }

    std::unordered_map<int, std::string> map_1;
    map_1[0] = "";
    map_1[1] = "One";
    map_1[2] = "Two";
    map_1[3] = "Three";
    map_1[4] = "Four";
    map_1[5] = "Five";
    map_1[6] = "Six";
    map_1[7] = "Seven";
    map_1[8] = "Eight";
    map_1[9] = "Nine";

    std::unordered_map<int, std::string> map_10;
    map_10[0] = "";
    map_10[1] = "Ten";
    map_10[2] = "Twenty";
    map_10[3] = "Thirty";
    map_10[4] = "Fourty";
    map_10[5] = "Fifty";
    map_10[6] = "Sixty";
    map_10[7] = "Seventy";
    map_10[8] = "Eighty";
    map_10[9] = "Ninety";

    std::vector<std::string> phrase;
    for (int i = 0; i < value_str.length(); ++i)
    {
        int digit = value_str[value_str.length()-1-i] - '0';

        if (i == 3)
        {
            phrase.push_back("Thousand");
            phrase.push_back(map_1[digit]);
            continue;
        }
        else if (i == 6)
        {
            phrase.push_back("Million");
            phrase.push_back(map_1[digit]);
            continue;
        }

        switch (i)
        {
            case 0:
                phrase.push_back(map_1[digit]);
                break;
            case 1:
                phrase.push_back(map_10[digit]);
                break;
            case 2:
                phrase.push_back("Hundred");
                phrase.push_back(map_1[digit]);
                break;
            case 4:
                phrase.push_back(map_10[digit]);
                break;
            case 5:
                phrase.push_back("Hundred");
                phrase.push_back(map_1[digit]);
                break;

        }
    }

    if (negative)
    {
        phrase.push_back("Minus");
    }

    for (int i = phrase.size()-1; i >= 0; --i)
    {
        std::cout << phrase[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int value = -1234500;

    printPhrase(value);

    return 0;
}
