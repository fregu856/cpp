#include <iostream>

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

bool inTree(TreeNode *root, TreeNode *node)
{
    if (root == NULL)
    {
        return false;
    }

    return (node == root) || (inTree(root->left, node)) || (inTree(root->right, node));
}

TreeNode* findCommonAncestor(TreeNode *root, TreeNode *first, TreeNode *second)
{
    if (inTree(root->left, first) && inTree(root->left, second))
    {
        if (root->left == first || root->left == second)
        {
            return root;
        }
        else
        {
            return findCommonAncestor(root->left, first, second);
        }
    }
    else if (inTree(root->right, first) && inTree(root->right, second))
    {
        if (root->right == first || root->right == second)
        {
            return root;
        }
        else
        {
            return findCommonAncestor(root->right, first, second);
        }
    }
    else
    {
        return root;
    }
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
    bst.insert(-3);
    bst.insert(-4);
    bst.insert(-2);
    bst.preOrderPrint();
    std::cout << std::endl;

    TreeNode *ancestor = findCommonAncestor(bst.root, bst.root->left->left->left, bst.root->left->right->right);
    std::cout << "First node: " << bst.root->left->left->left->data << ", Second node: " << bst.root->left->right->right->data << ", ancestor: " << ancestor->data << std::endl;

    return 0;
}
