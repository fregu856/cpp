#include <iostream>
#include <vector>

std::vector< std::vector<int> > maximizeProfit(std::vector<int> &vec)
{
    bool has_bought = false;
    std::vector<int> buys;
    std::vector<int> sells;

    for (int i = 0; i < vec.size(); ++i)
    {
        if (i == vec.size()-1)
        {
            if (has_bought)
            {
                has_bought = false;
                sells.push_back(i);
                break;
            }
        }

        if (vec[i+1] > vec[i] && !has_bought)
        {
            has_bought = true;
            buys.push_back(i);
        }
        else if (vec[i+1] < vec[i] && has_bought)
        {
            has_bought = false;
            sells.push_back(i);
        }
    }

    std::vector< std::vector<int> > output = {buys, sells};
    return output;
}

int main()
{
    //std::vector<int> vec = {100, 180, 260, 310, 40, 535, 695};
    std::vector<int> vec = {500, 400, 300, 200, 100};

    std::vector< std::vector<int> > result = maximizeProfit(vec);

    std::vector<int> buys = result[0];
    std::vector<int> sells = result[1];

    std::cout << "Buy on days: ";
    for (int i = 0; i < buys.size(); ++i)
    {
        std::cout << buys[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sell on days: ";
    for (int i = 0; i < sells.size(); ++i)
    {
        std::cout << sells[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
