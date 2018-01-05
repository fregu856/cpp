#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

void findFrequency(std::vector<std::string> &book)
{
    std::unordered_map<std::string, int> frequency;

    for (int i = 0; i < book.size(); ++i)
    {
        std::string word = book[i];
        if (frequency.find(word) == frequency.end())
        {
            frequency[word] = 1;
        }
        else
        {
            frequency[word]++;
        }
    }

    for (auto i = frequency.begin(); i != frequency.end(); ++i)
    {
        std::cout << i->first << ": " << i->second << std::endl;
    }
}

int main()
{
    std::vector<std::string> book = {"hej", "du", "din", "flane", "hej", "flane", "hej"};

    findFrequency(book);

    return 0;
}
