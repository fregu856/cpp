#include <iostream>

// TODO! NOT CORRECT!

const int STACK_SIZE = 10;

class Stack
{
public:
    Stack();

    void push(int value);

    int pop();

    int peek();

    bool isEmpty();

    void print();

private:
    int buffer[STACK_SIZE];
    int index;
};

Stack::Stack(): index(0) {}

void Stack::push(int value)
{
    buffer[index] = value;
    index++;
}

int Stack::pop()
{
    index--;
    return buffer[index];
}

int Stack::peek()
{
    return buffer[index-1];
}

bool Stack::isEmpty()
{
    return index == 0;
}

void Stack::print()
{
    std::cout << "Stack:" << std::endl;

    for (int i = index-1; i >= 0; --i)
    {
        std::cout << buffer[i] << std::endl;
    }

    std::cout << "#######################" << std::endl;
}

void sortStack(Stack &stack)
{
    Stack buffer_stack;
    int value, buffer_value;

    while (!stack.isEmpty())
    {
        if (buffer_stack.isEmpty())
        {
            value = stack.pop();
            buffer_stack.push(value);
        }
        else
        {
            value = stack.peek();
            if (value < buffer_stack.peek())
            {
                value = stack.pop();
                buffer_stack.push(value);
            }
            else // swap:
            {
                value = stack.pop();
                buffer_value = buffer_stack.pop();

                buffer_stack.push(value);
                stack.push(buffer_value);
            }
        }
    }

    while (!buffer_stack.isEmpty())
    {
        buffer_value = buffer_stack.pop();
        stack.push(buffer_value);
    }
}

int main()
{
    int value;

    Stack stack;
    stack.push(4);
    stack.push(2);
    stack.push(5);
    stack.push(0);
    stack.push(1);
    stack.push(3);
    stack.print();

    sortStack(stack);
    stack.print();

    return 0;
}
