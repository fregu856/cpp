#include <iostream>

struct Node
{
    int data;
    Node *next;
};

////////////////////////////////////////////////////////////////////////////////
// Stack:
////////////////////////////////////////////////////////////////////////////////
class Stack
{
public:
    Stack(int value);

    int pop();

    void push(int value);

    int peek();

    void print();

private:
    Node *top;
};

Stack::Stack(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    top = temp;
}

int Stack::pop()
{
    int value = top->data;
    top = top->next;

    return value;
}

void Stack::push(int value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = top;

    top = new_node;
}

int Stack::peek()
{
    return top->data;
}

void Stack::print()
{
    std::cout << "Stack:" << std::endl;

    int value;
    Node *ptr = new Node;
    ptr = top;
    while (ptr != NULL)
    {
        value = ptr->data;
        ptr = ptr->next;

        std::cout << value << std::endl;
    }

    std::cout << "###########################" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Queue:
////////////////////////////////////////////////////////////////////////////////
class Queue
{
public:
    Queue(int value);

    void enqueue(int value);

    int dequeue();

    void print();

private:
    Node *first;

    Node *last;
};

Queue::Queue(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    first = temp;
    last = temp;
}

void Queue::enqueue(int value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;

    last->next = new_node;
    last = last->next;
}

int Queue::dequeue()
{
    int value = first->data;
    first = first->next;

    return value;
}

void Queue::print()
{
    std::cout << "Queue: ";

    int value;
    Node *ptr = new Node;
    ptr = first;
    while (ptr != NULL)
    {
        value = ptr->data;
        ptr = ptr->next;

        std::cout << value << " ";
    }

    std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// main:
////////////////////////////////////////////////////////////////////////////////
int main()
{
    Stack test_stack(0);
    test_stack.push(1);
    test_stack.push(2);
    test_stack.print();
    int value = test_stack.pop();
    test_stack.print();
    value = test_stack.pop();
    test_stack.print();
    value = test_stack.pop();
    test_stack.print();
    test_stack.push(0);
    test_stack.print();
    test_stack.push(1);
    test_stack.print();

    Queue queue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.print();
    value = queue.dequeue();
    std::cout << "Value dequeued: " << value << std::endl;
    queue.print();
    value = queue.dequeue();
    std::cout << "Value dequeued: " << value << std::endl;
    queue.print();
    queue.enqueue(10);
    queue.print();

    return 0;
}
