#include <iostream>
#include <vector>
#include <utility>

void printMatrix(std::vector< std::vector<int> > &matrix)
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

int findElementUtil(std::vector<int> &vec, int value, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high-low)/2;
    if (value == vec[mid])
    {
        return mid;
    }
    else if (value > vec[mid])
    {
        return findElementUtil(vec, value, mid+1, high);
    }
    else
    {
        return findElementUtil(vec, value, low, mid-1);
    }
}

int findElement(std::vector<int> &vec, int value)
{
    return findElementUtil(vec, value, 0, vec.size()-1);
}

std::pair<int, int> findElementUtil(std::vector< std::vector<int> > &matrix, int value, int row_low, int row_high)
{
    if (row_low > row_high)
    {
        std::pair<int, int> return_val;
        return_val.first = -1;
        return_val.second = -1;
        return return_val;
    }
    else if (row_low == row_high)
    {
        std::pair<int, int> return_val;
        return_val.first = row_low;
        return_val.second = findElement(matrix[row_low], value);
        return return_val;
    }

    int row_mid = row_low + (row_high-row_low)/2;
    if (matrix[row_mid][0] == value)
    {
        std::pair<int, int> return_val;
        return_val.first = row_mid;
        return_val.second = 0;
        return return_val;
    }
    else if (value < matrix[row_mid][0])
    {
        return findElementUtil(matrix, value, row_low, row_mid-1);
    }
    else
    {
        std::pair<int, int> upper = findElementUtil(matrix, value, row_low, row_mid);
        if (upper.first != -1 && upper.second != -1)
        {
            return upper;
        }
        else
        {
            return findElementUtil(matrix, value, row_mid+1, row_high);
        }
    }
}

std::pair<int, int> findElement(std::vector< std::vector<int> > &matrix, int value)
{
    int num_rows = matrix.size();
    return findElementUtil(matrix, value, 0, num_rows-1);
}

int main()
{
    std::vector< std::vector<int> > matrix = {{1, 2, 3},
                                              {2, 3, 4},
                                              {3, 4, 5},
                                              {4, 5, 6}};

    std::pair<int, int> indices = findElement(matrix, 4);

    std::cout << "row: " << indices.first << ", col: " << indices.second << std::endl;

    return 0;
}
