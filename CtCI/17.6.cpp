#include <iostream>
#include <vector>

std::vector<int> findSubArrayToSort(std::vector<int> &vec)
{
    int max_index = vec.size()-1;

    int min_value = vec[max_index];
    int max_value = vec[0];

    std::vector<int> max_value_to_left(vec.size());
    std::vector<int> min_value_to_right(vec.size());

    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i-1] > max_value)
        {
            max_value = vec[i-1];
        }

        max_value_to_left[i] = max_value;
    }

    for (int i = max_index-1; i >= 0; --i)
    {
        if (vec[i+1] < min_value)
        {
            min_value = vec[i+1];
        }

        min_value_to_right[i] = min_value;
    }

    int min_index_not_inplace = max_index+1;
    int max_index_not_inplace = -1;

    if (min_value_to_right[0] < vec[0])
    {
        min_index_not_inplace = 0;
    }

    if (max_value_to_left[max_index] > vec[max_index])
    {
        max_index_not_inplace = max_index;
    }

    for (int i = 1; i <= max_index-1; ++i)
    {
        if (min_value_to_right[i] < vec[i] || max_value_to_left[i] > vec[i]) // (if not in-place)
        {
            if (i < min_index_not_inplace)
            {
                min_index_not_inplace = i;
            }
            else if (i > max_index_not_inplace)
            {
                max_index_not_inplace = i;
            }
        }
    }

    std::vector<int> indices = {min_index_not_inplace, max_index_not_inplace};
    return indices;
}

int main()
{
    //std::vector<int> vec = {1, 2, 5, 3, 4, 6, 7};
    //std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    //std::vector<int> vec = {1, 2, 3, 4, 6, 5, 8, 7};
    std::vector<int> vec = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    //std::vector<int> vec = {3, 1, 4, 2, 5, 6, 7, 8};
    std::vector<int> indices = findSubArrayToSort(vec);

    std::cout << "from: " << indices[0] << ", to: " << indices[1] << std::endl;

    return 0;
}
