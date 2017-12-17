#include <iostream>
#include <unordered_set>

struct Node
{
    int data;
    Node *next;
};

class List
{
public:
    List(int value);
    List();

    void append(int value);

    void print();

    Node *head;
};

List::List(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    head = temp;
}

List::List()
{
    Node *temp = new Node;
    temp->data = 999;
    temp->next = NULL;

    head = temp;
}

void List::append(int value)
{
    Node *temp_data = new Node;
    temp_data->data = value;
    temp_data->next = NULL;

    Node *temp = new Node;
    temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = temp_data;
}

void List::print()
{
    Node *temp = new Node;
    temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

Node* findLoopStart(List list)
{
    std::unordered_set<Node*> nodes;

    Node *ptr = list.head;
    while (ptr != NULL)
    {
        if (nodes.find(ptr) == nodes.end())
        {
            nodes.insert(ptr);
            ptr = ptr->next;
        }
        else
        {
            return ptr;
        }
    }
}

int main()
{
    List list(1);

    Node *ptr = list.head;

    Node *new_node = new Node;
    new_node->data = 2;
    new_node->next = NULL;
    ptr->next = new_node;
    ptr = ptr->next;

    Node *new_node2 = new Node;
    new_node2->data = 3;
    new_node2->next = NULL;
    ptr->next = new_node2;
    ptr = ptr->next;

    Node *new_node3 = new Node;
    new_node3->data = 4;
    new_node3->next = NULL;
    ptr->next = new_node3;
    ptr = ptr->next;

    ptr->next = new_node;

    Node *loop_start_node = findLoopStart(list);
    std::cout << "Start node of the loop: " << loop_start_node->data << std::endl;

    return 0;
}
