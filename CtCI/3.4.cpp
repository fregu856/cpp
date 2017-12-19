#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// Tower:
////////////////////////////////////////////////////////////////////////////////
const int N = 5;

class Tower
{
public:
    Tower();

    void addDisk(int disk);

    int removeDisk();

    void print();

private:
    int disks[N];
    int index;
};

Tower::Tower(): index(0) {}

void Tower::addDisk(int disk)
{
    if (index == 0)
    {
        disks[index] = disk;
        index++;
    }
    else
    {
        if (disk > disks[index-1])
        {
            std::cout << "A disk can only be placed on top of a larger disk!" << std::endl;
        }
        else
        {
            disks[index] = disk;
            index++;
        }
    }
}

int Tower::removeDisk()
{
    if (index == 0)
    {
       std::cout << "Can't remove disks from an empty tower!" << std::endl;
    }
    else
    {
        index--;
        return disks[index];
    }
}

void Tower::print()
{
    for (int i = 0; i < index; ++i)
    {
        std::cout << disks[i] << " ";
    }
    std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// main:
////////////////////////////////////////////////////////////////////////////////

void printTowers(Tower towers[3])
{
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Tower " << i << " :" << std::endl;
        towers[i].print();
    }
    std::cout << "##########################" << std::endl;
}

int getFreeTower(int from, int to)
{
    bool arr[3] = {true, true, true};

    arr[from] = false;
    arr[to] = false;

    for (int i = 0; i < 3; ++i)
    {
        if (arr[i])
        {
            return i;
        }
    }
}

void moveDisks(Tower (&towers)[3], int disks_to_move, int from, int to)
{
    int disk;

    if (disks_to_move == 1)
    {
        disk = towers[from].removeDisk();
        towers[to].addDisk(disk);
    }
    else
    {
        moveDisks(towers, disks_to_move-1, from, getFreeTower(from, to));
        moveDisks(towers, 1, from, to);
        moveDisks(towers, disks_to_move-1, getFreeTower(from, to), to);
    }

    std::cout << "#### Inside moveDisks ###" << std::endl;
    printTowers(towers);
}

int main()
{
    int value;

    Tower towers[3];
    towers[0].addDisk(5);
    towers[0].addDisk(4);
    towers[0].addDisk(3);
    towers[0].addDisk(2);
    towers[0].addDisk(1);

    printTowers(towers);

    moveDisks(towers, N, 0, 2);
    printTowers(towers);

    return 0;
}
