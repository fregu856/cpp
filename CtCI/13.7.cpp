#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* copyNode(Node *node)
{
    Node *node_copy = new Node;
    node_copy->data = node->data;

    if (node->left == NULL)
    {
        node_copy->left = NULL;
    }
    else
    {
        node_copy->left = copyNode(node->left);
    }

    if (node->right == NULL)
    {
        node_copy->right = NULL;
    }
    else
    {
        node_copy->right = copyNode(node->right);
    }

    return node_copy;
}

int main()
{
    Node *node_left = new Node;
    node_left->data = 1;
    node_left->left = NULL;
    node_left->right = NULL;

    Node *node_right = new Node;
    node_right->data = 2;
    node_right->left = NULL;
    node_right->right = NULL;

    Node *node = new Node;
    node->data = 0;
    node->left = node_left;
    node->right = node_right;

    Node *node_copy;
    node_copy = copyNode(node);

    std::cout << node->data << std::endl;
    std::cout << node->left->data << std::endl;
    std::cout << node->right->data << std::endl;
    std::cout << "####################" << std::endl;
    std::cout << node_copy->data << std::endl;
    std::cout << node_copy->left->data << std::endl;
    std::cout << node_copy->right->data << std::endl;

    node->left->data = 9999;

    std::cout << "After modificaton:" << std::endl;

    std::cout << node->data << std::endl;
    std::cout << node->left->data << std::endl;
    std::cout << node->right->data << std::endl;
    std::cout << "####################" << std::endl;
    std::cout << node_copy->data << std::endl;
    std::cout << node_copy->left->data << std::endl;
    std::cout << node_copy->right->data << std::endl;

    return 0;
}
