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

// N time, N space:
void removeDuplicates(List list)
{
    std::unordered_set<int> unique_elements;

    Node *current_node = list.head;
    Node *previous_node = list.head;
    int current_element;
    while (current_node != NULL)
    {
        current_element = current_node->data;
        if (unique_elements.find(current_element) == unique_elements.end())
        {
            previous_node = current_node;
            current_node = current_node->next;
            unique_elements.insert(current_element);
        }
        else
        {
            previous_node->next = current_node->next;
            current_node = current_node->next;
        }
    }
}

// N^2 time, 1 space:
void removeDuplicatesNoBuffer(List list)
{
    Node *current_node = list.head;
    Node *previous_node = list.head;

    Node *ptr;
    int current_element;
    bool duplicate;
    while (current_node != NULL)
    {
        current_element = current_node->data;

        ptr = current_node->next;
        duplicate = false;
        while (ptr != NULL)
        {
            int element = ptr->data;
            if (element == current_element)
            {
                duplicate = true;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        if (duplicate)
        {
            previous_node->next = current_node->next;
            current_node = current_node->next;
        }
        else
        {
            previous_node = current_node;
            current_node = current_node->next;
        }
    }
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

    removeDuplicatesNoBuffer(list);
    list.print();

    return 0;
}
