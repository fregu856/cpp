#include <iostream>
#include <vector>

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

    void insert(int value);

    void preOrderPrint();

    TreeNode *root;

    void insert(int value, TreeNode *&node);

    void preOrderPrint(TreeNode *node);
};

BST::BST()
{
    root = NULL;
}

void BST::insert(int value)
{
    insert(value, root);
}

void BST::preOrderPrint()
{
    std::cout << "preOrder: ";
    preOrderPrint(root);
    std::cout << std::endl;
}

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

////////////////////////////////////////////////////////////////////////////////

void createListsUtil(TreeNode *node, std::vector< std::vector<int> > &lists, int depth)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        depth++;
        if (!(depth < lists.size()))
        {
            std::vector<int> depth_list;
            depth_list.push_back(node->data);
            lists.push_back(depth_list);
        }
        else
        {
            lists[depth].push_back(node->data);
        }

        createListsUtil(node->left, lists, depth);
        createListsUtil(node->right, lists, depth);
    }
}

void createLists(TreeNode *root)
{
    std::vector< std::vector<int> > lists;

    if (root == NULL)
    {
        return;
    }
    else
    {
        int depth = 0;
        std::vector<int> depth_list;
        depth_list.push_back(root->data);
        lists.push_back(depth_list);

        createListsUtil(root->left, lists, depth);
        createListsUtil(root->right, lists, depth);
    }

    for (int i = 0; i < lists.size(); ++i)
    {
        std::cout << "Depth: " << i << std::endl;
        for (int j = 0; j < lists[i].size(); ++j)
        {
            std::cout << lists[i][j] << " ";
        }
        std::cout << std::endl;
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
    bst.preOrderPrint();

    TreeNode *root = bst.root;
    createLists(root);

    return 0;
}
