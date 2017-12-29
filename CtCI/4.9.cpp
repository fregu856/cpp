#include <iostream>
#include <vector>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

class BST
{
public:
    BST();

    void insert(int value);

    void insertUtil(int value, TreeNode *&node);

    void preOrderPrint();

    void preOrderPrint(TreeNode *node);

    TreeNode *root;
};

BST::BST()
{
    root = NULL;
}

void BST::insert(int value)
{
    insertUtil(value, root);
}

void BST::insertUtil(int value, TreeNode *&node)
{
    if (node == NULL)
    {
        TreeNode *new_node = new TreeNode;
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        node = new_node;
    }
    else
    {
        if (value <= node->data)
        {
            insertUtil(value, node->left);
        }
        else
        {
            insertUtil(value, node->right);
        }
    }
}

void BST::preOrderPrint()
{
    preOrderPrint(root);
}

void BST::preOrderPrint(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    std::cout << node->data << " ";
    preOrderPrint(node->left);
    preOrderPrint(node->right);
}

////////////////////////////////////////////////////////////////////////////////

void printVector(std::vector<int> path)
{
    std::cout << "Path: ";
    for (int i = 0; i < path.size(); ++i)
    {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
}

void printPathsUtil(TreeNode *node, int value, int sum, std::vector<int> path)
{
    if (node == NULL)
    {
        return;
    }

    sum += node->data;
    path.push_back(node->data);
    if (sum == value)
    {
        printVector(path);
    }

    printPathsUtil(node->left, value, sum, path);
    printPathsUtil(node->right, value, sum, path);
}

void printPaths(TreeNode *node, int value)
{
    if (node == NULL)
    {
        return;
    }

    std::vector<int> path;
    printPathsUtil(node, value, 0, path);

    printPaths(node->left, value);
    printPaths(node->right, value);
}

int main()
{
    BST bst;
    bst.insert(5);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(2);
    bst.insert(8);
    bst.insert(-3);
    bst.insert(-4);
    bst.insert(-2);
    bst.preOrderPrint();
    std::cout << std::endl;

    printPaths(bst.root, -2);

    return 0;
}
