#include <iostream>
#include <vector>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

void preOrderPrint(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        std::cout << node->data << " ";
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}

void createMinHeightBST(TreeNode *&node, std::vector<int> vec, int start_index, int last_index)
{
    if (start_index == last_index)
    {
        node = new TreeNode;
        node->data = vec[start_index];
        node->left = NULL;
        node->right = NULL;
    }
    else
    {
        int mid_index = start_index + (last_index - start_index + 1)/2;

        node = new TreeNode;
        node->data = vec[mid_index];
        createMinHeightBST(node->left, vec, start_index, mid_index-1);
        createMinHeightBST(node->right, vec, mid_index+1, last_index);
    }
}

int main()
{
    std::vector<int> vec = {1, 3, 4, 6, 8, 11, 15};

    TreeNode *root;
    createMinHeightBST(root, vec, 0, vec.size()-1);

    preOrderPrint(root);

    return 0;
}
