#include <iostream>

char my_string[] = {'1', '2', '3', '4', '5', '6'};

void reverse(char* str)
{
    char* first = str;

    int i = 0;
    while (*(str + i) != '\0')
    {
        i++;
    }
    char* last = str + i-1;

    while(first < last)
    {
        char temp = *first;
        *first = *last;
        *last = temp;

        first++;
        last--;
    }
}

int main()
{
    std::cout << "Orignal string: " << my_string << std::endl;
    reverse(my_string);
    std::cout << "Reversed string:" << my_string << std::endl;

    return 0;
}
