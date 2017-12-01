#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
};

bool less_than(Player player1, Player player2)
{
    if (player1.score > player2.score)
    {
        return true;
    }
    else if (player2.score > player1.score)
    {
        return false;
    }
    else
    {
        if (player1.name < player2.name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

vector<Player> comparator(vector<Player> players)
{
    sort(players.begin(), players.end(), &less_than);
    return players;
}

int main()
{
    int n;
    cin >> n;

    vector<Player> players;
    string name;
    int score;
    for(int i = 0; i < n; i++)
    {
        cin >> name >> score;
        Player p1;
        p1.name = name;
        p1.score = score;
        players.push_back(p1);
    }

    vector<Player> answer = comparator(players);
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i].name << " " << answer[i].score << endl;
    }

    return 0;
}
