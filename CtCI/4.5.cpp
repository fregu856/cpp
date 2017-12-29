#include <iostream>
#include <algorithm>

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

////////////////////////////////////////////////////////////////////////////////

// n^2 solution:
// int minValue(TreeNode *node)
// {
//     if (node == NULL)
//     {
//         return 999;
//     }
//     else
//     {
//         return std::min(std::min(node->data, minValue(node->left)), minValue(node->right));
//     }
// }
//
// int maxValue(TreeNode *node)
// {
//     if (node == NULL)
//     {
//         return -999;
//     }
//     else
//     {
//         return std::max(std::max(node->data, maxValue(node->left)), maxValue(node->right));
//     }
// }
//
// bool isBST(TreeNode *node)
// {
//     if (node == NULL)
//     {
//         return true;
//     }
//     else
//     {
//         int max_value_left = maxValue(node->left);
//         if (!(max_value_left <= node->data) && max_value_left != -999)
//         {
//             return false;
//         }
//
//         int min_value_right = minValue(node->right);
//         if (!(min_value_right > node->data) && min_value_right != 999)
//         {
//             return false;
//         }
//
//         return isBST(node->left) && isBST(node->right);
//     }
// }

bool isBSTUtil(TreeNode *node, int min, int max)
{
    if (node == NULL)
    {
        return true;
    }
    else
    {
        if (!(node->data <= max && node->data > min))
        {
            return false;
        }

        return isBSTUtil(node->left, min, node->data) && isBSTUtil(node->right, node->data, max);
    }
}

bool isBST(TreeNode *node)
{
    return isBSTUtil(node, -999, 999);
}

int main()
{
    TreeNode *bst_node = new TreeNode;
    bst_node->data = 5;
    bst_node->left = new TreeNode;
    bst_node->left->data = 1;
    bst_node->left->left = NULL;
    bst_node->left->right = NULL;
    bst_node->right = new TreeNode;
    bst_node->right->data = 7;
    bst_node->right->left = NULL;
    bst_node->right->right = NULL;
    bst_node->left->right = new TreeNode;
    bst_node->left->right->data = 3;
    bst_node->left->right->left = new TreeNode;
    bst_node->left->right->left->data = 2;
    bst_node->left->right->left->left = NULL;
    bst_node->left->right->left->right = NULL;
    bst_node->left->right->right = new TreeNode;
    bst_node->left->right->right->data = 4;
    bst_node->left->right->right->left = NULL;
    bst_node->left->right->right->right = NULL;

    TreeNode *node = new TreeNode;
    node->data = 5;
    node->left = new TreeNode;
    node->left->data = 1;
    node->left->left = NULL;
    node->left->right = NULL;
    node->right = new TreeNode;
    node->right->data = 7;
    node->right->left = NULL;
    node->right->right = NULL;
    node->left->right = new TreeNode;
    node->left->right->data = 3;
    node->left->right->left = new TreeNode;
    node->left->right->left->data = 2;
    node->left->right->left->left = NULL;
    node->left->right->left->right = NULL;
    node->left->right->right = new TreeNode;
    node->left->right->right->data = 10;
    node->left->right->right->left = NULL;
    node->left->right->right->right = NULL;

    preOrderPrint(bst_node);
    std::cout << std::endl;

    preOrderPrint(node);
    std::cout << std::endl;

    if (isBST(bst_node))
    {
        std::cout << "BST!" << std::endl;
    }
    else
    {
        std::cout << "NOT BST!" << std::endl;
    }

    if (isBST(node))
    {
        std::cout << "BST!" << std::endl;
    }
    else
    {
        std::cout << "NOT BST!" << std::endl;
    }

    return 0;
}
