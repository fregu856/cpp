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

List partitionList(List list, int value)
{
    List less_list;
    Node *less_ptr = less_list.head;

    List greater_list;
    Node *greater_ptr = greater_list.head;

    Node *ptr = list.head;
    int current_element;
    while (ptr != NULL)
    {
        current_element = ptr->data;
        if (current_element < value)
        {
            if (less_ptr->data == 999)
            {
                less_ptr->data = current_element;
                less_ptr->next = NULL;
            }
            else
            {
                Node *new_node = new Node;
                new_node->data = current_element;
                new_node->next = NULL;
                less_ptr->next = new_node;
                less_ptr = less_ptr->next;
            }
        }
        else
        {
            if (greater_ptr->data == 999)
            {
                greater_ptr->data = current_element;
                greater_ptr->next = NULL;
            }
            else
            {
                Node *new_node = new Node;
                new_node->data = current_element;
                new_node->next = NULL;
                greater_ptr->next = new_node;
                greater_ptr = greater_ptr->next;
            }
        }

        ptr = ptr->next;
    }

    less_ptr->next = greater_list.head;

    std::cout << less_list.head->data << std::endl;

    return less_list;
}

int main()
{
    List list(6);
    list.append(3);
    list.append(3);
    list.append(1);
    list.append(9);
    list.append(2);
    list.append(4);
    list.append(3);
    list.append(0);
    list.print();

    list = partitionList(list, 4);
    list.print();

    return 0;
}
