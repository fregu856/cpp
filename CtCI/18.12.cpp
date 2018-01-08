#include <iostream>
#include <vector>

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

int computeSum(std::vector< std::vector<int> > &matrix, int row_low, int row_high, int col_low, int col_high)
{
    int sum = 0;
    for (int row = row_low; row <= row_high; ++row)
    {
        for (int col = col_low; col <= col_high; ++col)
        {
            sum += matrix[row][col];
        }
    }

    return sum;
}

std::vector< std::vector<int> > findSubmatrix(std::vector< std::vector<int> > &matrix)
{
    int N = matrix.size();
    int row_low, row_high, col_low, col_high = -1;
    int max_sum = matrix[0][0];

    for (int size = 1; size <= N; ++size)
    {
        for (int row_start = 0; row_start+size-1 < N; ++row_start)
        {
            for (int col_start = 0; col_start+size-1 < N; ++col_start)
            {
                int sum = computeSum(matrix, row_start, row_start+size-1, col_start, col_start+size-1);
                if (sum > max_sum)
                {
                    max_sum = sum;

                    row_low = row_start;
                    row_high = row_start+size-1;
                    col_low = col_start;
                    col_high = col_start+size-1;
                }
            }
        }
    }

    int submatrix_N = row_high-row_low+1;
    std::vector< std::vector<int> > largest_submatrix(submatrix_N, std::vector<int>(submatrix_N));
    for (int row = 0; row < submatrix_N ; ++row)
    {
        for (int col = 0; col < submatrix_N; ++col)
        {
            largest_submatrix[row][col] = matrix[row_low+row][col_low+col];
        }
    }

    return largest_submatrix;
}

int main()
{
    std::vector< std::vector<int> > matrix = {{1, -3, 4},
                                              {0, 2, 4},
                                              {-20, -4, 6}};

    //printMatrix(matrix);

    std::vector< std::vector<int> > largest_submatrix = findSubmatrix(matrix);
    printMatrix(largest_submatrix);

    return 0;
}
