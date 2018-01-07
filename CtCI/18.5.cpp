#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int findShortestDistance(std::vector<std::string> &file, std::string first, std::string second)
{
    if (first == second)
    {
        return -1;
    }

    std::string current_found_word = "@@";
    int shortest_distance = file.size();
    int index_left, index_right;
    for (int i = 0; i < file.size(); ++i)
    {
        std::string word = file[i];
        if (word == first || word == second)
        {
            if (current_found_word == "@@")
            {
                current_found_word = word;
                index_left = i;
            }
            else
            {
                if (word == current_found_word)
                {
                    index_left = i;
                }
                else
                {
                    index_right = i;
                    int distance = index_right - index_left - 1;
                    if (distance < shortest_distance)
                    {
                        shortest_distance = distance;
                    }
                    current_found_word = word;
                    index_left = i;
                }
            }
        }
    }

    if (shortest_distance == file.size())
    {
        return -1;
    }
    else
    {
        return shortest_distance;
    }
}

void preProcess(std::vector<std::string> &file, std::unordered_map<std::string, int> &unique_words, std::vector< std::unordered_map<std::string, int> > &hash_tables)
{
    int index = 0;
    for (int i = 0; i < file.size(); ++i)
    {
        std::string word = file[i];
        if (unique_words.find(word) == unique_words.end())
        {
            unique_words[word] = index;
            index++;
        }
    }
    int num_unique_words = index;

    std::vector< std::unordered_map<std::string, int> > temp(num_unique_words);
    hash_tables = temp;

    for (auto i = unique_words.begin(); i != unique_words.end(); ++i)
    {
        std::string first_word = i->first;
        int first_word_index = i->second;

        for (auto j = i; j != unique_words.end(); ++j)
        {
            std::string second_word = j->first;
            int shortest_distance = findShortestDistance(file, first_word, second_word);

            hash_tables[first_word_index][second_word] = shortest_distance;
        }
    }
}

int findShortestDistanceOptimized(std::vector<std::string> &file, std::unordered_map<std::string, int> &unique_words, std::vector< std::unordered_map<std::string, int> > &hash_tables, std::string first, std::string second)
{
    if (!( (unique_words.find(first) != unique_words.end()) && (unique_words.find(second) != unique_words.end()) ))
    {
        return -1;
    }

    int first_index = unique_words[first];
    int second_index = unique_words[second];
    std::unordered_map<std::string, int> first_hash_table = hash_tables[first_index];
    std::unordered_map<std::string, int> second_hash_table = hash_tables[second_index];

    if (first_hash_table.find(second) != first_hash_table.end())
    {
        return first_hash_table[second];
    }
    else
    {
        return second_hash_table[first];
    }
}

int main()
{
    std::vector<std::string> file = {"hej", "du", "din", "gamle", "flane", "vad", "gor", "du", "nufortiden", "hej", "gamle", "nufortiden"};

    std::unordered_map<std::string, int> unique_words;
    std::vector< std::unordered_map<std::string, int> > hash_tables;
    preProcess(file, unique_words, hash_tables);

    //std::cout << findShortestDistance(file, "gamle", "nufortiden") << std::endl;
    std::cout << findShortestDistance(file, "flane", "hej") << std::endl;

    //std::cout << findShortestDistanceOptimized(file, unique_words, hash_tables, "gamle", "nufortiden") << std::endl;
    std::cout << findShortestDistanceOptimized(file, unique_words, hash_tables, "flane", "hej") << std::endl;

    return 0;
}
