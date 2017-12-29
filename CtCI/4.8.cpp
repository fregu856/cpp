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

TreeNode* findNode(TreeNode *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->data == value)
        {
            return root;
        }
        else
        {
            TreeNode *found_node_left = findNode(root->left, value);
            if (found_node_left == NULL)
            {
                TreeNode *found_node_right = findNode(root->right, value);
                if (found_node_right == NULL)
                {
                    return NULL;
                }
                else
                {
                    return found_node_right;
                }
            }
            else
            {
                return found_node_left;
            }
        }
    }
}

bool isSubtreeUtil(TreeNode *tree, TreeNode *subtree)
{
    if (tree == NULL && subtree == NULL)
    {
        return true;
    }
    else if (tree == NULL || subtree == NULL)
    {
        return false;
    }
    else if (tree->data != subtree->data)
    {
        return false;
    }

    return isSubtreeUtil(tree->left, subtree->left) && isSubtreeUtil(tree->right, subtree->right);
}

bool isSubtree(TreeNode *tree, TreeNode *subtree)
{
    TreeNode *node = findNode(tree, subtree->data);
    if (node == NULL)
    {
        return false;
    }

    return isSubtreeUtil(node, subtree);
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

    BST bst_sub;
    bst_sub.insert(3);
    bst_sub.insert(2);
    bst_sub.insert(4);
    bst_sub.preOrderPrint();
    std::cout << std::endl;

    BST bst_not_sub;
    bst_not_sub.insert(3);
    bst_not_sub.insert(2);
    bst_not_sub.preOrderPrint();
    std::cout << std::endl;

    if (isSubtree(bst.root, bst_sub.root))
    {
        std::cout << "Subtree!" << std::endl;
    }
    else
    {
        std::cout << "NOT a substree!" << std::endl;
    }

    if (isSubtree(bst.root, bst_not_sub.root))
    {
        std::cout << "Subtree!" << std::endl;
    }
    else
    {
        std::cout << "NOT a substree!" << std::endl;
    }

    // TreeNode *node = findNode(bst.root, 6);
    // if (node != NULL)
    // {
    //     std::cout << node->data << std::endl;
    // }
    // else
    // {
    //     std::cout << "Value was NOT found!" << std::endl;
    // }

    return 0;
}
