#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

bool isCombinedWord(std::string word, std::unordered_set<std::string> &unique_words, int low)
{
    if (low > word.length()-1)
    {
        return true;
    }

    std::string sub_word;
    for (int i = low; i < word.length(); ++i)
    {
        if (low == 0 && i == (word.length()-1))
        {
            return false;
        }

        sub_word.push_back(word[i]);
        if (unique_words.find(sub_word) != unique_words.end())
        {
            if (isCombinedWord(word, unique_words, i+1))
            {
                return true;
            }
        }
    }

    return false;
}

bool isCombinedWord(std::string word, std::unordered_set<std::string> &unique_words)
{
    return isCombinedWord(word, unique_words, 0);
}

std::string findLongestWord(std::vector<std::string> &words)
{
    std::unordered_set<std::string> unique_words;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        unique_words.insert(*i);
    }

    int longest_word_length = 0;
    std::string longest_word = "@@";
    std::string word;
    for (auto i = unique_words.begin(); i != unique_words.end(); ++i)
    {
        word = *i;
        if (word.length() > longest_word_length)
        {
            if (isCombinedWord(word, unique_words))
            {
                longest_word_length = word.length();
                longest_word = word;
                std::cout << "Current longest combined word: " << longest_word << std::endl;
            }
        }
    }

    return longest_word;
}

int main()
{
    std::vector<std::string> words = {"cat", "banana", "tacocat", "walker", "taco", "dog", "tacobread", "ta", "tacocatdog", "dogcattacotaco"};

    std::string longest_word = findLongestWord(words);

    std::cout << "Longest combined word: " << longest_word << std::endl;

    return 0;
}
