#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cmath>
#include <thread>
#include <chrono>
using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
    virtual void printProperties() const = 0;

protected:
    void drawWithDelay(char symbol, int delayMs = 50) const {
        cout << symbol << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
};

class Square : public Shape
{
private:
    double side;
public:
    Square(double s) : side(s) {}

    double getArea() const override {
        return side * side;
    }

    double getPerimeter() const override {
        return 4 * side;
    }

    void draw() const override {
        int size = (int)side;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                    drawWithDelay('$');
                else
                    drawWithDelay(' ');
                cout << " ";
            }
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void printProperties() const override {
        cout << "Square:" << endl;
        cout << "  Side: " << side << endl;
        cout << "  Area: " << getArea() << endl;
        cout << "  Perimeter: " << getPerimeter() << endl;
    }
};

class Rectangle : public Shape
{
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    void draw() const override {
        int w = (int)width;
        int h = (int)height;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                    drawWithDelay('$');
                else
                    drawWithDelay(' ');
                cout << " ";
            }
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void printProperties() const override {
        cout << "Rectangle:" << endl;
        cout << "  Width: " << width << endl;
        cout << "  Height: " << height << endl;
        cout << "  Area: " << getArea() << endl;
        cout << "  Perimeter: " << getPerimeter() << endl;
    }
};

class Triangle : public Shape
{
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() const override {
        return (base * height) / 2;
    }

    double getPerimeter() const override {
        double side = sqrt(height * height + (base / 2) * (base / 2));
        return base + 2 * side;
    }

    void draw() const override {
        int h = (int)height;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < h - i - 1; j++) {
                drawWithDelay(' ');
                cout << " ";
            }
            for (int j = 0; j <= i; j++) {
                if (i == h - 1 || j == 0 || j == i) {
                    drawWithDelay('$');
                    cout << " ";
                }
                else {
                    drawWithDelay(' ');
                    cout << " ";
                }
            }
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(150));
        }
    }

    void printProperties() const override {
        cout << "Triangle:" << endl;
        cout << "  Base: " << base << endl;
        cout << "  Height: " << height << endl;
        cout << "  Area: " << getArea() << endl;
        cout << "  Perimeter: " << getPerimeter() << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }

    void draw() const override {
        int r = (int)radius;
        int diameter = 2 * r;

        for (int y = -r; y <= r; y++) {
            for (int x = -r; x <= r; x++) {
                double distance = sqrt(x * x + y * y);
                if (abs(distance - r) < 0.8) {
                    drawWithDelay('$');
                    cout << " ";
                }
                else {
                    drawWithDelay(' ');
                    cout << " ";
                }
            }
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(120));
        }
    }

    void printProperties() const override {
        cout << "Circle:" << endl;
        cout << "  Radius: " << radius << endl;
        cout << "  Area: " << getArea() << endl;
        cout << "  Circumference: " << getPerimeter() << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");
    Shape* shapes[4];
    shapes[0] = new Square(5);
    shapes[1] = new Rectangle(6, 4);
    shapes[2] = new Triangle(6, 4);
    shapes[3] = new Circle(4);

    for (int i = 0; i < 4; i++) {
        shapes[i]->printProperties();
        this_thread::sleep_for(chrono::milliseconds(1000));
        shapes[i]->draw();
        cout << "\n----------------------------\n" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000)); 
    }

    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    return 0;
}