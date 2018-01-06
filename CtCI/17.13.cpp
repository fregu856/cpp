#include <iostream>

struct biNode
{
    int data;
    biNode *node1;
    biNode *node2;
};

biNode* convertToListUtil(biNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    biNode *left_list_ptr = convertToListUtil(root->node1);
    if (left_list_ptr == NULL)
    {
        root->node1 = NULL;
    }
    else
    {
        while (left_list_ptr->node2 != NULL)
        {
            left_list_ptr = left_list_ptr->node2;
        }

        root->node1 = left_list_ptr;
        left_list_ptr->node2 = root;
    }

    biNode *right_list_ptr = convertToListUtil(root->node2);
    if (right_list_ptr == NULL)
    {
        root->node2 = NULL;
    }
    else
    {
        while (right_list_ptr->node1 != NULL)
        {
            right_list_ptr = right_list_ptr->node1;
        }

        root->node2 = right_list_ptr;
        right_list_ptr->node1 = root;
    }

    return root;
}

biNode* convertToList(biNode *root)
{
    biNode *list_ptr = convertToListUtil(root);

    while (list_ptr->node1 != NULL)
    {
        list_ptr = list_ptr->node1;
    }

    return list_ptr; // (list_ptr now points to the list head)
}

void printList(biNode *head)
{
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->node2;
    }
    std::cout << std::endl;
}

int main()
{
    biNode *root = new biNode;
    root->data = 5;

    biNode *left_root = new biNode;
    left_root->data = 2;

    biNode *left_left = new biNode;
    left_left->data = 0;
    left_left->node1 = NULL;
    left_left->node2 = NULL;

    biNode *left_right = new biNode;
    left_right->data = 3;
    left_right->node1 = NULL;
    left_right->node2 = NULL;

    left_root->node1 = left_left;
    left_root->node2 = left_right;

    biNode *right_root = new biNode;
    right_root->data = 8;

    biNode *right_left = new biNode;
    right_left->data = 6;
    right_left->node1 = NULL;
    right_left->node2 = NULL;

    right_root->node1 = right_left;
    right_root->node2 = NULL;

    root->node1 = left_root;
    root->node2 = right_root;

    biNode *head = convertToList(root);

    printList(head);

    return 0;
}
