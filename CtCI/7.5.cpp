#include <iostream>

class Square
{
public:
    Square(int x, int y, int size);

    void print();

    bool sameMidpoint(Square &other);

    int getX();

    int getY();

private:
    int x;
    int y;
    int size;
};

Square::Square(int x, int y, int size)
: x(x), y(y), size(size)
{}

void Square::print()
{
    std::cout << "x: " << x << ", y: " << y << ", size: " << size << std::endl;
}

int Square::getX()
{
    return x;
}

int Square::getY()
{
    return y;
}

bool Square::sameMidpoint(Square &other)
{
    return (x == other.getX() && y == other.getY());
}

////////////////////////////////////////////////////////////////////////////////

class Line
{
public:
    Line(float k, float m);

    void print();
private:
    float k;
    float m;
};

Line::Line(float k, float m)
: k(k), m(m)
{}

void Line::print()
{
    std::cout << "k: " << k << ", m: " << m << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

Line findLine(Square &square_1, Square &square_2)
{
    if (square_1.sameMidpoint(square_2))
    {
        Line line(0, square_1.getY());
        return line;
    }
    else
    {
        float numerator = (float) square_1.getY() - square_2.getY();
        float denominator = (float) square_1.getX() - square_2.getX();
        float k = numerator/denominator;
        float m = square_1.getY() - k*square_1.getX();

        Line line(k, m);
        return line;
    }
}

int main()
{
    Square square_1(1, 1, 2);
    square_1.print();

    Square square_2(3, 0, 1);
    square_2.print();

    Line line = findLine(square_1, square_2);
    line.print();

    return 0;
}
