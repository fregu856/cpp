#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void printTower(std::vector< std::pair<int, int> > &tower)
{
    for (int i = 0; i < tower.size(); ++i)
    {
        std::cout << "Height: " << tower[i].first << ", Width: " << tower[i].second << std::endl;
    }
}

void findLongestIncreasing(std::vector< std::pair<int, int> > &vec, std::vector< std::vector<int> > &matrix, int index)
{
    if (index == 0)
    {
        matrix[index].push_back(0);
        return;
    }

    findLongestIncreasing(vec, matrix, index-1);

    int max_height = 0;
    int max_index = -1;
    for (int i = 0; i < index; ++i)
    {
        if (vec[index].second > vec[matrix[i][matrix[i].size()-1]].second)
        {
            if (matrix[i].size()+1 > max_height)
            {
                max_height = matrix[i].size()+1;
                max_index = i;
            }
        }
    }

    if (max_index == -1)
    {
        matrix[index].push_back(index);
        return;
    }
    else
    {
        matrix[index] = matrix[max_index];
        matrix[index].push_back(index);
        return;
    }
}

// (returns true if pair1 should go before pair2)
bool customComparator(std::pair<int, int> pair1, std::pair<int, int> pair2)
{
    return (pair1.first < pair2.first);
}

std::vector< std::pair<int, int> > computeTallestTower(std::vector< std::pair<int, int> > &vec)
{
    // sort the pairs according to height:
    std::sort(vec.begin(), vec.end(), customComparator);

    std::vector< std::vector<int> > matrix(vec.size());
    findLongestIncreasing(vec, matrix, vec.size()-1);

    std::vector< std::pair<int, int> > tower;
    for (int i = 0; i < matrix[vec.size()-1].size(); ++i)
    {
        tower.push_back(vec[matrix[vec.size()-1][i]]);
    }
    return tower;
}

int main()
{
    std::pair<int, int> pair1(170, 70);
    std::pair<int, int> pair2(160, 75);
    std::pair<int, int> pair3(165, 60);
    std::pair<int, int> pair4(180, 90);
    std::pair<int, int> pair5(175, 80);
    std::vector< std::pair<int, int> > vec = {pair1, pair2, pair3, pair4, pair5};

    std::cout << "Input:" << std::endl;
    printTower(vec);

    std::vector< std::pair<int, int> > tower = computeTallestTower(vec);

    std::cout << "Tallest tower:" << std::endl;
    printTower(tower);

    return 0;
}
