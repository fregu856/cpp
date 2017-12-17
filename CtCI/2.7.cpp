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

bool isPalindrome(List list)
{
    Node *ptr = list.head;
    Node *ptr_reversed = NULL;

    while (ptr != NULL)
    {
        Node *new_node = new Node;
        new_node->data = ptr->data;
        new_node->next = ptr_reversed;
        ptr_reversed = new_node;

        ptr = ptr->next;
    }

    ptr = list.head;
    while (ptr != NULL)
    {
        if (ptr->data != ptr_reversed->data)
        {
            return false;
        }
        else
        {
            ptr = ptr->next;
            ptr_reversed = ptr_reversed->next;
        }
    }

    return true;
}

int main()
{
    List list_no(1);
    list_no.append(2);
    list_no.append(3);
    list_no.append(4);
    list_no.append(5);
    list_no.print();

    if (isPalindrome(list_no))
    {
        std::cout << "Palindrome!" << std::endl;
    }
    else
    {
        std::cout << "NOT a palindrome!" << std::endl;
    }

    List list_yes(1);
    list_yes.append(2);
    list_yes.append(3);
    list_yes.append(2);
    list_yes.append(1);
    list_yes.print();

    if (isPalindrome(list_yes))
    {
        std::cout << "Palindrome!" << std::endl;
    }
    else
    {
        std::cout << "NOT a palindrome!" << std::endl;
    }

    return 0;
}
