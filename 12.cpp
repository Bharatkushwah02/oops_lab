#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ========== Input Validation Class ==========
class Answer {
    long long a;

    bool Is_string(string str) {
        int start = 0;
        if (str.empty()) return false;
        if (str[0] == '+' || str[0] == '-') start = 1;

        for (int i = start; i < str.size(); i++) {
            if (!isdigit(str[i])) return false;
        }
        return true;
    }

    long long get_input(const string& msg) {
        string str;
        while (true) {
            cout << msg;
            getline(cin, str);
            if (Is_string(str)) {
                try {
                    long long val = stoll(str);
                    return val;
                } catch (out_of_range&) {
                    cout << "Entered number is too large. Try again.\n";
                }
            } else {
                cout << "Invalid input. Please enter a valid number.\n";
            }
        }
    }

public:
    long long input(const string& msg) {
        a = get_input(msg);
        return a;
    }
};

// ========== Base Class ==========
class Shape {
public:
    virtual void area() = 0;      // pure virtual functions
    virtual void volume() {}
};

// ========== Derived Class (2D Shapes) ==========
class TwoDShape : public Shape {
public:
    void volume() override {
        cout << "2D shapes don't have volume.\n";
    }
};

// ========== Circle Class ==========
class Circle : public TwoDShape {
    double radius;

public:
    void getData(Answer& obj) {
        radius = obj.input("Enter radius of Circle: ");
    }

    void area() override {
        cout << "Area of Circle = " << 3.14 * radius * radius << endl;
    }
};

// ========== Rectangle Class ==========
class Rectangle : public TwoDShape {
    double length, breadth;

public:
    void getData(Answer& obj) {
        length = obj.input("Enter length of Rectangle: ");
        breadth = obj.input("Enter breadth of Rectangle: ");
    }

    void area() override {
        cout << "Area of Rectangle = " << length * breadth << endl;
    }
};

// ========== Square Class ==========
class Square : public TwoDShape {
    double side;

public:
    void getData(Answer& obj) {
        side = obj.input("Enter side of Square: ");
    }

    void area() override {
        cout << "Area of Square = " << side * side << endl;
    }
};

// ========== 3D Shapes Base ==========
class ThreeDShape : public Shape {
};

// ========== Sphere Class ==========
class Sphere : public ThreeDShape {
    double radius;

public:
    void getData(Answer& obj) {
        radius = obj.input("Enter radius of Sphere: ");
    }

    void area() override {
        cout << "Surface Area of Sphere = " << 4 * 3.14 * radius * radius << endl;
    }

    void volume() override {
        cout << "Volume of Sphere = " << (4.0 / 3.0) * 3.14 * pow(radius, 3) << endl;
    }
};

// ========== Cylinder Class ==========
class Cylinder : public ThreeDShape {
    double radius, height;

public:
    void getData(Answer& obj) {
        radius = obj.input("Enter radius of Cylinder: ");
        height = obj.input("Enter height of Cylinder: ");
    }

    void area() override {
        cout << "Surface Area of Cylinder = " << 2 * 3.14 * radius * (radius + height) << endl;
    }

    void volume() override {
        cout << "Volume of Cylinder = " << 3.14 * radius * radius * height << endl;
    }
};

// ========== Main Function ==========
int main() {
    Answer input;
    Circle c;
    Rectangle r;
    Square s;
    Sphere sp;
    Cylinder cy;

    int choice;
    while (true) {
        cout << "\n=== Shape Menu ===\n";
        cout << "1. Circle\n2. Rectangle\n3. Square\n4. Sphere\n5. Cylinder\n6. Exit\n";
        choice = input.input("Enter your choice: ");

        switch (choice) {
        case 1:
            c.getData(input);
            c.area();
            c.volume();
            break;
        case 2:
            r.getData(input);
            r.area();
            r.volume();
            break;
        case 3:
            s.getData(input);
            s.area();
            s.volume();
            break;
        case 4:
            sp.getData(input);
            sp.area();
            sp.volume();
            break;
        case 5:
            cy.getData(input);
            cy.area();
            cy.volume();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
