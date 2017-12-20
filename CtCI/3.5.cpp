#include <iostream>
#include <stack>

class Queue
{
public:
    void enqueue(int value);

    int dequeue();

    void print();

    bool empty();

private:
    std::stack<int> most_recent_stack;
    std::stack<int> least_recent_stack;
};

void Queue::enqueue(int value)
{
    most_recent_stack.push(value);
}

int Queue::dequeue()
{
    int value;

    if (least_recent_stack.empty())
    {
        while (!most_recent_stack.empty())
        {
            value = most_recent_stack.top();
            most_recent_stack.pop();
            least_recent_stack.push(value);
        }
    }

    value = least_recent_stack.top();
    least_recent_stack.pop();
    return value;
}

void Queue::print()
{
    std::cout << "Queue: ";

    while (!this->empty())
    {
        std::cout << this->dequeue() << " ";
    }

    std::cout << std::endl << "####################" << std::endl;
}

bool Queue::empty()
{
    return most_recent_stack.empty() && least_recent_stack.empty();
}

int main ()
{
    int value;

    Queue queue;
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    value = queue.dequeue();
    value = queue.dequeue();
    value = queue.dequeue();
    value = queue.dequeue();
    value = queue.dequeue();
    queue.enqueue(90);
    queue.print();

    return 0;
}
