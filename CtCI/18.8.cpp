#include <iostream>
#include <vector>
#include <string>

bool isSubstring(std::string str, std::string word)
{
    int index_word = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == word[index_word])
        {
            index_word++;
            if (index_word == word.length())
            {
                return true;
            }
        }
        else
        {
            index_word = 0;
        }
    }

    return false;
}

std::vector<std::string> findWordsInString(std::string str, std::vector<std::string> &words)
{
    std::vector<std::string> contained_words;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        std::string word = *i;
        if (isSubstring(str, word))
        {
            contained_words.push_back(word);
        }
    }

    return contained_words;
}

int main()
{
    std::string str = "tacocatdogwalker";
    std::vector<std::string> words = {"taco", "cat", "foot", "walker", "dog", "hejhej", "walk", "dogwalker", "tacocat"};

    std::vector<std::string> contained_words = findWordsInString(str, words);

    for (auto i = contained_words.begin(); i != contained_words.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
