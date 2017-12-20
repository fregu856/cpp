#include <iostream>

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

private:
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

int main()
{
    TreeNode *node;

    BST bst;
    bst.insert(5);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);
    bst.insert(2);
    bst.insert(7);
    bst.inOrderPrint();
    bst.preOrderPrint();
    bst.postOrderPrint();

    node = bst.search(7);
    if (node == NULL)
    {
        std::cout << "NULL" << std::endl;
    }
    else
    {
        std::cout << node->data << std::endl;
    }

    node = bst.search(19);
    if (node == NULL)
    {
        std::cout << "NULL" << std::endl;
    }
    else
    {
        std::cout << node->data << std::endl;
    }

    return 0;
}
