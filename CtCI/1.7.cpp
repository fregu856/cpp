#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

std::vector< std::vector<int> > matrix = {{1,2,3,4},
                                          {5,0,7,8},
                                          {9,10,11,12}};

void printMatrix(std::vector< std::vector<int> > matrix)
{
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_cols; ++col)
        {
            std::cout << matrix[row][col] << " ";
        }

        std::cout << std::endl;
    }
}

std::vector< std::vector<int> > setToZero(std::vector< std::vector<int> > matrix)
{
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    std::unordered_set<int> rows_to_skip, cols_to_skip;

    int current_element;
    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_cols; ++col)
        {
            if (rows_to_skip.find(row) != rows_to_skip.end() || cols_to_skip.find(col) != cols_to_skip.end())
            {
                continue;
            }

            current_element = matrix[row][col];

            if (current_element == 0)
            {
                std::transform(matrix[row].begin(), matrix[row].end(), matrix[row].begin(), [](int element){return 0;});

                for (int i = 0; i < num_rows; ++i)
                {
                    matrix[i][col] = 0;
                }

                rows_to_skip.insert(row);
                cols_to_skip.insert(col);
            }
        }
    }

    return matrix;
}

int main()
{
    std::cout << "Original matrix:" << std::endl;
    printMatrix(matrix);

    std::cout << "Matrix after operation:" << std::endl;
    printMatrix(setToZero(matrix));

    return 0;
}
