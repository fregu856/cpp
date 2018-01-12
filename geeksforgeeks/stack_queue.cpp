#include <iostream>

struct Node
{
    int data;
    Node *next;
};

////////////////////////////////////////////////////////////////////////////////
// stack:
////////////////////////////////////////////////////////////////////////////////
void stackPush(int value, Node *&top)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = top;

    top = new_node;
}

int stackPop(Node *&top)
{
    int value = top->data;

    top = top->next;

    return value;
}

int stackPeek(Node *top)
{
    return top->data;
}

bool stackEmpty(Node *top)
{
    return (top == NULL);
}

void stackPrint(Node *top)
{
    std::cout << "Stack:" << std::endl;

    Node *ptr = new Node;
    ptr = top;
    while (ptr != NULL)
    {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// queue:
////////////////////////////////////////////////////////////////////////////////
void queueEnqueue(int value, Node *&first, Node *&last)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;

    if (first == NULL || last == NULL)
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        last->next = new_node;
        last = new_node;
    }
}

int queueDequeue(Node *&first, Node *&last)
{
    int value = first->data;

    first = first->next;

    return value;
}

int queuePeek(Node *first, Node *last)
{
    return first->data;
}

void queuePrint(Node *first, Node *last)
{
    std::cout << "Queue: ";

    Node *ptr = new Node;
    ptr = first;
    while (ptr != NULL)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
    Node *top = NULL;

    stackPush(5, top);
    stackPush(10, top);
    stackPush(15, top);
    stackPrint(top);

    int num = stackPop(top);
    std::cout << "popped value: " << num << std::endl;
    stackPrint(top);

    Node *first = NULL;
    Node *last = NULL;

    queueEnqueue(5, first, last);
    queueEnqueue(10, first, last);
    queueEnqueue(15, first, last);
    queuePrint(first, last);

    num = queueDequeue(first, last);
    std::cout << "dequeued value: " << num << std::endl;
    queuePrint(first, last);

    return 0;
}
