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

int findMiddleElement(Node *head)
{
    Node *ptr = new Node;
    ptr = head;
    Node *fast_ptr = new Node;
    fast_ptr = head;

    while (fast_ptr->next != NULL)
    {
        ptr = ptr->next;
        fast_ptr = fast_ptr->next;

        if (fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next;
        }
        else
        {
            return ptr->data;
        }
    }

    return ptr->data;
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

    std::cout << findMiddleElement(head) << std::endl;

    return 0;
}
