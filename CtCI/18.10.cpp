#include <iostream>
#include <unordered_set>
#include <string>
#include <utility>
#include <vector>

std::pair<bool, std::vector<std::string> > convertUtil(std::string from, std::string to, std::unordered_set<std::string> &dictionary, std::vector<std::string> order)
{
    if (from == to)
    {
        std::pair<bool, std::vector<std::string> > output = std::make_pair(true, order);
        return output;
    }

    for (int i = 0; i < from.length(); ++i)
    {
        if (from[i] != to[i])
        {
            std::string temp = from;
            temp[i] = to[i];

            if (dictionary.find(temp) != dictionary.end())
            {
                std::vector<std::string> temp_order(order);
                temp_order.push_back(temp);
                if (convertUtil(temp, to, dictionary, temp_order).first)
                {
                    std::pair<bool, std::vector<std::string> > output = convertUtil(temp, to, dictionary, temp_order);
                    return output;
                }
            }
        }
    }

    std::pair<bool, std::vector<std::string> > output = std::make_pair(false, order);
    return output;
}

std::vector<std::string> convert(std::string from, std::string to, std::unordered_set<std::string> &dictionary)
{
    std::vector<std::string> order;
    order.push_back(from);
    std::pair<bool, std::vector<std::string> > output = convertUtil(from, to, dictionary, order);

    if (output.first)
    {
          return output.second;
    }
    else
    {
        std::vector<std::string> fail_order = {"Could not convert!"};
        return fail_order;
    }
}

int main()
{
    std::unordered_set<std::string> dictionary;
    dictionary.insert("DAMP");
    dictionary.insert("LIKE");
    dictionary.insert("LIMP");
    dictionary.insert("LIME");
    dictionary.insert("DAME");
    dictionary.insert("LAME");
    dictionary.insert("LAKE");
    dictionary.insert("DIMP");
    dictionary.insert("DIME");
    dictionary.insert("DIKE");
    dictionary.insert("DAMP");
    dictionary.insert("DAMP");
    dictionary.insert("DAMP");
    dictionary.insert("DAMP");

    std::vector<std::string> steps = convert("DAMP", "LIKE", dictionary);

    for (auto i = steps.begin(); i != steps.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
