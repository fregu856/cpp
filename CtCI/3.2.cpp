#include <iostream>

struct Node
{
    int data;
    int node_min;
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

    int getMin();

private:
    Node *top;

    int min;
};

Stack::Stack(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->node_min = value;
    temp->next = NULL;

    min = value;

    top = temp;
}

int Stack::pop()
{
    int value = top->data;
    top = top->next;

    min = top->node_min;

    return value;
}

void Stack::push(int value)
{
    if (value < min)
    {
        min = value;
    }

    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = top;
    new_node->node_min = min;

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

int Stack::getMin()
{
    return min;
}

////////////////////////////////////////////////////////////////////////////////
// main:
////////////////////////////////////////////////////////////////////////////////
int main()
{
    Stack test_stack(5);
    test_stack.push(3);
    test_stack.push(7);
    test_stack.push(1);
    test_stack.push(8);
    test_stack.push(2);
    test_stack.push(0);
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;

    int value = test_stack.pop();
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;
    value = test_stack.pop();
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;
    value = test_stack.pop();
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;
    value = test_stack.pop();
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;
    value = test_stack.pop();
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;
    value = test_stack.pop();
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;

    test_stack.push(22);
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;

    test_stack.push(2);
    test_stack.print();
    std::cout << "Min: " << test_stack.getMin() << std::endl;

    return 0;
}
