/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

#include <set>

bool has_cycle(Node *head)
{
    bool return_bool = false;
    set<Node*> set_of_nodes;
    while (head != nullptr)
    {
        if (set_of_nodes.find(head) == set_of_nodes.end())
        {
            set_of_nodes.insert(head);
        }
        else
        {
            return_bool = true;
            break;
        }

        head = head->next;
    }

    return return_bool;
}
