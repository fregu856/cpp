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

int getElement_notFancy(int k, List list)
{
    int length = 0;

    Node *ptr = list.head;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }

    ptr = list.head;
    for (int i = 0; i < length-k; ++i)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int getElement(int k, List list)
{
    Node *ptr1 = list.head;
    Node *ptr2 = list.head;

    for (int i = 0; i < k; ++i)
    {
        ptr2 = ptr2->next;
    }

    while (ptr2 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1->data;
}

int main()
{
    List list(1);
    list.append(2);
    list.append(3);
    list.append(3);
    list.append(3);
    list.append(4);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(6);
    list.append(6);
    list.append(7);
    list.append(7);
    list.print();

    int k = 6; // (k = 1: last element)
    int kth_element = getElement(k, list);
    std::cout << kth_element << std::endl;

    return 0;
}
