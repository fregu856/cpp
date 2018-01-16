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

Node* listReverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
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
    listPrint(head);

    head = listReverse(head);
    listPrint(head);

    return 0;
}
