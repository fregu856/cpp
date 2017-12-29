#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

class BST
{
public:
    BST();

    void insert(int value);

    void insertUtil(int value, TreeNode *&node, TreeNode *parent);

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
    insertUtil(value, root, NULL);
}

void BST::insertUtil(int value, TreeNode *&node, TreeNode *parent)
{
    if (node == NULL)
    {
        TreeNode *new_node = new TreeNode;
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = parent;
        node = new_node;
    }
    else
    {
        if (value <= node->data)
        {
            insertUtil(value, node->left, node);
        }
        else
        {
            insertUtil(value, node->right, node);
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

void printParent(TreeNode *node)
{
    std::cout << "Node: " << node->data << ", parent: "  << node->parent->data << std::endl;
}

int main()
{
    BST bst;
    bst.insert(5);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(2);
    bst.insert(7);
    bst.preOrderPrint();
    std::cout << std::endl;

    printParent(bst.root->left);

    return 0;
}
