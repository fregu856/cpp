#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Stack:
////////////////////////////////////////////////////////////////////////////////
const int STACK_SIZE = 3;

class Stack
{
public:
    Stack();

    void push (int value);

    int pop();

    void print();

    int get_index();

private:
    int buffer[STACK_SIZE];
    int index;
};

Stack::Stack() : index(0) {}

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

void Stack::print()
{
    std::cout << "Stack:" << std::endl;
    for (int i = index-1; i >= 0; --i)
    {
        std::cout << buffer[i] << std::endl;
    }
    std::cout << "########" << std::endl;
}

int Stack::get_index()
{
    return index;
}

////////////////////////////////////////////////////////////////////////////////
// SetOfStacks:
////////////////////////////////////////////////////////////////////////////////
class SetOfStacks
{
public:
    SetOfStacks();

    void push(int value);

    int pop();

    void print();

private:
    std::vector<Stack> stacks;

    int stack_index;
};

SetOfStacks::SetOfStacks()
{
    stack_index = 0;
    Stack stack;
    stacks.push_back(stack);
}

void SetOfStacks::push(int value)
{
    if (stacks[stack_index].get_index() == STACK_SIZE)
    {
        stack_index++;
        Stack stack;
        stacks.push_back(stack);
    }

    stacks[stack_index].push(value);
}

int SetOfStacks::pop()
{
    if (stacks[stack_index].get_index() == 0)
    {
        stack_index--;
        stacks.pop_back();
    }

    return stacks[stack_index].pop();
}

void SetOfStacks::print()
{
    std::cout << "Stacks: " << stacks.size() << std::endl;

    for (int i = 0; i < stacks.size(); ++i)
    {
        stacks[i].print();
    }

    std::cout << "##############################" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// main:
////////////////////////////////////////////////////////////////////////////////
int main()
{
    int value;

    // Stack stack;
    // stack.push(0);
    // stack.push(1);
    // stack.push(2);
    // stack.print();
    // value = stack.pop();
    // stack.print();

    SetOfStacks set_of_stacks;
    set_of_stacks.push(0);
    set_of_stacks.push(1);
    set_of_stacks.push(2);
    set_of_stacks.push(3);
    set_of_stacks.push(4);
    set_of_stacks.print();

    value = set_of_stacks.pop();
    set_of_stacks.print();

    value = set_of_stacks.pop();
    set_of_stacks.print();

    value = set_of_stacks.pop();
    set_of_stacks.print();

    return 0;
}
