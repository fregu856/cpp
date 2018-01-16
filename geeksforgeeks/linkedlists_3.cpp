#include <iostream>

struct Node
{
    int data;
    Node *next;
};

void listAppend(int value, Node *&head)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node *ptr = new Node;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
}

void listPrint(Node *head)
{
    Node *ptr = new Node;
    ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

Node* listRotate(int k, Node *head)
{
    Node *ptr = new Node;
    ptr = head;

    for (int i = 0; i < k-1; ++i)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        return head;
    }

    Node *new_end = new Node;
    new_end = ptr;

    Node *new_head = new Node;
    new_head = ptr->next;

    new_end->next = NULL;

    ptr = new_head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = head;

    return new_head;
}

int main()
{
    Node *head = NULL;
    listAppend(1, head);
    listAppend(2, head);
    listAppend(3, head);
    listAppend(4, head);
    listAppend(5, head);
    listAppend(6, head);
    listAppend(7, head);
    listAppend(8, head);
    listPrint(head);

    int k = 4;
    head = listRotate(k, head);
    listPrint(head);

    return 0;
}
