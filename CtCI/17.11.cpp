#include <iostream>
#include <cstdlib>
#include <ctime>

int rand5()
{
    std::srand(std::time(nullptr));
    return std::rand() % 5;
}

int rand7()
{
    int num;
    while (true)
    {
        num = 5*rand5() + rand5();
        if (num < 21)
        {
            return num % 7;
        }
    }
}


int main()
{
    std::cout << rand7() << std::endl;

    return 0;
}
