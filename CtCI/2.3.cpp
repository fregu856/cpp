#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class List
{
public:
    List(int value);

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

void removeNode(Node *ptr)
{
    ptr->data = ptr->next->data;
    ptr->next = ptr->next->next;
}

int main()
{
    List list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.print();

    Node *ptr = list.head;
    for (int i = 0; i < 4; ++i)
    {
        ptr = ptr->next;
    }
    std::cout << "Node to remove: " << ptr->data << std::endl;

    removeNode(ptr);
    list.print();

    return 0;
}
