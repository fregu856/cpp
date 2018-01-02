#include <iostream>
#include <fstream>
#include <string>
#include <stack>

void printLastK(int k, std::string filename)
{
    std::ifstream file(filename);

    std::stack<std::string> stack;
    std::string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stack.push(line);
        }
        file.close();

        for (int i = 0; i < k; ++i)
        {
            line = stack.top();
            stack.pop();
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

int main()
{
    // std::ofstream output_file;
    // output_file.open("test.txt");
    // output_file << "Hej hej hej hej.\n";
    // output_file.close();

    int k = 5;
    std::string filename = "random_file.txt";
    printLastK(k, filename);

    return 0;
}
