#include <iostream>

class Person
{
public:
    Person();

    void aboutMe();

private:
    int id;
};

Person::Person()
{
    std::cout << "A person has been created!" << std::endl;
}

void Person::aboutMe()
{
    std::cout << "I'm a person!" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

class Student : public Person
{
public:
    Student();

    void aboutMe();

private:
    int student_id;
};

Student::Student()
{
    std::cout << "A student has been created!" << std::endl;
}

void Student::aboutMe()
{
    std::cout << "I'm a student!" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

int main()
{
    Person person;
    person.aboutMe();

    Student student;
    student.aboutMe();

    return 0;
}
