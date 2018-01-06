#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int getRandom(int max)
{
    std::srand(std::time(nullptr));
    return std::rand() % (max+1);
}

void shuffleDeckIt(std::vector<int> &deck)
{
    for (int i = 0; i < deck.size(); ++i)
    {
        int swap_index = getRandom(i);
        int temp = deck[i];
        deck[i] = deck[swap_index];
        deck[swap_index] = temp;
    }
}

void shuffleDeckUtil(std::vector<int> &deck, int high)
{
    if (high == 0)
    {
        return;
    }

    shuffleDeckUtil(deck, high-1);

    int swap_index = getRandom(high);
    int temp = deck[high];
    deck[high] = deck[swap_index];
    deck[swap_index] = temp;
}

void shuffleDeckRec(std::vector<int> &deck)
{
    shuffleDeckUtil(deck, deck.size()-1);
}

int main()
{
    std::vector<int> deck = {0, 1, 2, 3, 4, 5 ,6, 7, 8, 9, 10};

    //shuffleDeckRec(deck);
    shuffleDeckIt(deck);

    for (int i = 0; i < deck.size(); ++i)
    {
        std::cout << deck[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
