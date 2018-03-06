#include <iostream>
#include <queue>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

void insert(TreeNode *&root, int value)
{
    if (root == NULL)
    {
        TreeNode *new_node = new TreeNode;
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;

        root = new_node;
        return;
    }

    if (value <= root->data)
    {
        insert(root->left, value);
    }
    else
    {
        insert(root->right, value);
    }
}

void printTreePreOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    std::cout << root->data << " ";

    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

void printTreePostOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printTreePostOrder(root->left);
    printTreePostOrder(root->right);

    std::cout << root->data << " ";
}

void printTreeInOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printTreeInOrder(root->left);

    std::cout << root->data << " ";

    printTreeInOrder(root->right);
}

void printTreeLevelOrder(TreeNode *root)
{
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.pop();

        std::cout << node->data << " ";

        if (node->left != NULL)
        {
            queue.push(node->left);
        }

        if (node->right != NULL)
        {
            queue.push(node->right);
        }
    }
}

int main()
{
    TreeNode *root = NULL;

    insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);

    printTreePreOrder(root);
    std::cout << std::endl;

    printTreePostOrder(root);
    std::cout << std::endl;

    printTreeInOrder(root);
    std::cout << std::endl;

    printTreeLevelOrder(root);
    std::cout << std::endl;

    return 0;
}
