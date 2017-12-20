#include <iostream>
#include <cstdlib>
#include <algorithm>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

////////////////////////////////////////////////////////////////////////////////
// BST:
////////////////////////////////////////////////////////////////////////////////
class BST
{
public:
    BST();
    ~BST();

    void insert(int value);

    TreeNode* search(int value);

    void inOrderPrint();

    void postOrderPrint();

    void preOrderPrint();

    TreeNode *root;

    void insert(int value, TreeNode *&node);

    TreeNode* search(int value, TreeNode *node);

    void inOrderPrint(TreeNode *node);

    void postOrderPrint(TreeNode *node);

    void preOrderPrint(TreeNode *node);

    void destroyTree(TreeNode *node);
};

////////////////////////////////////////////////////////////////////////////////
// BST - public:
////////////////////////////////////////////////////////////////////////////////
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    destroyTree(root);
}

void BST::insert(int value)
{
    insert(value, root);
}

TreeNode* BST::search(int value)
{
    return search(value, root);
}

void BST::inOrderPrint()
{
    std::cout << "inOrder: ";
    inOrderPrint(root);
    std::cout << std::endl;
}

void BST::postOrderPrint()
{
    std::cout << "postOrder: ";
    postOrderPrint(root);
    std::cout << std::endl;
}

void BST::preOrderPrint()
{
    std::cout << "preOrder: ";
    preOrderPrint(root);
    std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// BST - private:
////////////////////////////////////////////////////////////////////////////////
void BST::insert(int value, TreeNode *&node) // (pass reference to pointer, otherwise we will pass a copy of the pointer, and the pointer will not be updated)
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
        if (value < node->data)
        {
            insert(value, node->left);
        }
        else
        {
            insert(value, node->right);
        }
    }
}

TreeNode* BST::search(int value, TreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        if (value < node->data)
        {
            return search(value, node->left);
        }
        else if (value > node->data)
        {
            return search(value, node->right);
        }
        else
        {
            return node;
        }
    }
}

void BST::inOrderPrint(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        inOrderPrint(node->left);
        std::cout << node->data << " ";
        inOrderPrint(node->right);
    }
}

void BST::postOrderPrint(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        std::cout << node->data << " ";
    }
}

void BST::preOrderPrint(TreeNode *node)
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

void BST::destroyTree(TreeNode *node)
{
    if (node != NULL)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

////////////////////////////////////////////////////////////////////////////////

// n^2 solution:
int height(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + std::max(height(node->left), height(node->right));
    }
}

bool isBalanced(TreeNode *node)
{
    if (node == NULL)
    {
        return true;
    }
    else
    {
        return (abs(height(node->left) - height(node->right)) < 2) && isBalanced(node->left) && isBalanced(node->right);
    }
}

// n solution:
int checkHeigth(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left_height = checkHeigth(node->left);
    if (left_height == -1)
    {
        return -1;
    }

    int right_height = checkHeigth(node->right);
    if (right_height == -1)
    {
        return -1;
    }

    if (abs(right_height - left_height) > 1)
    {
        return -1;
    }
    else
    {
        return 1 + std::max(right_height, left_height);
    }
}

bool isBalanced_n(TreeNode *node)
{
    if (checkHeigth(node) == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    BST bst_unbalanced;
    bst_unbalanced.insert(5);
    bst_unbalanced.insert(1);
    bst_unbalanced.insert(3);
    bst_unbalanced.insert(4);
    bst_unbalanced.insert(2);
    bst_unbalanced.insert(7);
    bst_unbalanced.inOrderPrint();

    BST bst_balanced;
    bst_balanced.insert(5);
    bst_balanced.insert(2);
    bst_balanced.insert(8);
    bst_balanced.insert(1);
    bst_balanced.insert(3);
    bst_balanced.inOrderPrint();

    TreeNode *root_unbalanced = bst_unbalanced.root;
    TreeNode *root_balanced = bst_balanced.root;

    if (isBalanced(root_unbalanced))
    {
        std::cout << "Balanced tree!" << std::endl;
    }
    else
    {
        std::cout << "NOT balanced tree!" << std::endl;
    }

    if (isBalanced(root_balanced))
    {
        std::cout << "Balanced tree!" << std::endl;
    }
    else
    {
        std::cout << "NOT balanced tree!" << std::endl;
    }



    if (isBalanced_n(root_unbalanced))
    {
        std::cout << "Balanced tree!" << std::endl;
    }
    else
    {
        std::cout << "NOT balanced tree!" << std::endl;
    }

    if (isBalanced_n(root_balanced))
    {
        std::cout << "Balanced tree!" << std::endl;
    }
    else
    {
        std::cout << "NOT balanced tree!" << std::endl;
    }

    return 0;
}
