#include <iostream>

const int STACK_SIZE = 10;
const int buffer_size = STACK_SIZE*3;
int buffer[buffer_size];

int stack1_start_ind = 0;
int stack2_start_ind = STACK_SIZE;
int stack3_start_ind = 2*STACK_SIZE;

int stack1_ind = stack1_start_ind;
int stack2_ind = stack2_start_ind;
int stack3_ind = stack3_start_ind;

void push(int stack_num, int value)
{
    if (stack_num == 1)
    {
        buffer[stack1_ind] = value;
        stack1_ind++;
    }
    else if (stack_num == 2)
    {
        buffer[stack2_ind] = value;
        stack2_ind++;
    }
    else if (stack_num == 3)
    {
        buffer[stack3_ind] = value;
        stack3_ind++;
    }
}

int pop(int stack_num)
{
    if (stack_num == 1)
    {
        stack1_ind--;
        return buffer[stack1_ind];
    }
    else if (stack_num == 2)
    {
        stack2_ind--;
        return buffer[stack2_ind];
    }
    else if (stack_num == 3)
    {
        stack3_ind--;
        return buffer[stack3_ind];
    }
}

void printStacks()
{
    std::cout << "Stack 1:" << std::endl;
    for (int i = stack1_ind-1; i >= stack1_start_ind; --i)
    {
        std::cout << buffer[i] << std::endl;
    }

    std::cout << "Stack 2:" << std::endl;
    for (int i = stack2_ind-1; i >= stack2_start_ind; --i)
    {
        std::cout << buffer[i] << std::endl;
    }

    std::cout << "Stack 3:" << std::endl;
    for (int i = stack3_ind-1; i >= stack3_start_ind; --i)
    {
        std::cout << buffer[i] << std::endl;
    }

    std::cout << "############################" << std::endl;
}

int main()
{
    push(1, 0);
    push(2, 1);
    push(3, 2);
    printStacks();

    push(1, 1);
    push(1, 2);
    push(1, 3);
    push(1, 4);
    push(1, 5);
    printStacks();

    int value = pop(1);
    printStacks();

    value = pop(2);
    printStacks();

    return 0;
}
