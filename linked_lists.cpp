#include <iostream>

struct Node
{
    int data;
    Node *next;
};

void append(Node *&head, int value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
}

void printList(Node *head)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        std::cout << ptr->data << " --> ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void insert(Node *node, int value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = node->next;

    node->next = new_node;
}

void listDelete(Node *node)
{
    Node *old_next = node->next;

    node->data = node->next->data;
    node->next = node->next->next;

    delete old_next;
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
    Node *head = NULL;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    printList(head);

    insert(head->next->next, 10);
    printList(head);

    listDelete(head->next);
    printList(head);

    head = reverseList(head);
    printList(head);

    return 0;
}
