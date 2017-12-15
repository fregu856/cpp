#include <iostream>
#include <vector>

std::vector< std::vector<int> > matrix = {{1, 2, 3},
                                          {4, 5, 6},
                                          {7, 8, 9}};

std::vector< std::vector<int> > matrix2 = {{1, 2},
                                          {3, 4},
                                          {5, 6}};

void printMatrix(std::vector< std::vector<int> > matrix)
{
    for (int row = 0; row < matrix.size(); ++row)
    {
        for (int col = 0; col < matrix[0].size(); ++col)
        {
            std::cout << matrix[row][col] << " ";
        }

        std::cout << std::endl;
    }
}

std::vector< std::vector<int> > rotateMatrix(std::vector< std::vector<int> > matrix)
{
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    std::vector< std::vector<int> > rotated_matrix(num_cols, std::vector<int>(num_rows, 0));

    int current_element;
    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_cols; ++col)
        {
            current_element = matrix[row][col];

            rotated_matrix[col][num_rows-1-row] = current_element;
        }
    }

    return rotated_matrix;
}

int main()
{
    std::cout << "Original matrix:" << std::endl;
    printMatrix(matrix);

    std::cout << "Rotated matrix:" << std::endl;
    printMatrix(rotateMatrix(matrix));

    std::cout << "Original matrix:" << std::endl;
    printMatrix(matrix2);

    std::cout << "Rotated matrix:" << std::endl;
    printMatrix(rotateMatrix(matrix2));

    return 0;
}
