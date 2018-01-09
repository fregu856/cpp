#include <iostream>

struct Node
{
    int data;
    Node *next;
};

void append(Node *head, int value)
{
    Node *ptr = new Node;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;

    ptr->next = new_node;
}

void printList(Node *head)
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

Node* reverseList(Node *head)
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
    Node *head = new Node;
    head->data = 1;
    head->next = NULL;

    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    printList(head);

    head = reverseList(head);

    printList(head);

    return 0;
}
