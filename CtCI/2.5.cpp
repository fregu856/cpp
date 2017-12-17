#include <iostream>
#include <cmath>
#include <string>

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

List add(List list1, List list2)
{
    Node *ptr1 = list1.head;
    int sum1 = 0;
    int exponent = 0;
    while (ptr1 != NULL)
    {
        sum1 += (int) pow(10, exponent)*ptr1->data;

        ptr1 = ptr1->next;
        exponent++;
    }

    Node *ptr2 = list2.head;
    int sum2 = 0;
    exponent = 0;
    while (ptr2 != NULL)
    {
        sum2 += (int) pow(10, exponent)*ptr2->data;

        ptr2 = ptr2->next;
        exponent++;
    }

    int sum = sum1 + sum2;
    std::string sum_string = std::to_string(sum);

    List sum_list;
    Node *ptr = sum_list.head;
    for (int i = sum_string.length()-1; i >= 0; --i)
    {
        char char_digit = sum_string[i];
        int digit = char_digit - '0';

        if (ptr->data == 999)
        {
            ptr->data = digit;
            ptr->next = NULL;
        }
        else
        {
            Node *new_node = new Node;
            new_node-> data = digit;
            new_node->next = NULL;
            ptr->next = new_node;
            ptr = ptr->next;
        }
    }

    return sum_list;
}

int main()
{
    List list1(7);
    list1.append(1);
    list1.append(6);
    list1.print();

    List list2(5);
    list2.append(9);
    list2.append(2);
    list2.print();

    List sum_list = add(list1, list2);
    sum_list.print();

    return 0;
}
