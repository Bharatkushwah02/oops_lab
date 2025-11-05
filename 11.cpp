#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Answer {
    long long a;

    bool Is_string(string str) {
        int start = 0;
        if (str.empty()) {
            return false;
        } else if (str[0] == '+' || str[0] == '-') {
            start = 1;
        }
        for (int i = start; i < str.size(); i++) {
            if (!isdigit(str[i]) && str[i] != '.') { // '.' allow for decimal
                return false;
            }
        }
        return true;
    }

    double get_input(const string &msg) {
        string str;
        while (true) {
            cout << msg;
            getline(cin, str);
            if (Is_string(str)) {
                try {
                    double val = stod(str); // support floating point input
                    return val;
                } catch (out_of_range &) {
                    cout << "Entered number is too large. Please try again.\n";
                }
            } else {
                cout << "Invalid input! Please enter a valid number.\n";
            }
        }
    }

public:
    double input(const string &msg) {
        return get_input(msg);
    }
};

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    // Multiplication operator overloading
    Complex operator*(const Complex &obj) const {
        Complex temp;
        temp.real = (real * obj.real) - (imag * obj.imag);
        temp.imag = (real * obj.imag) + (imag * obj.real);
        return temp;
    }

    // Comparison operators
    bool operator==(const Complex &obj) const {
        return (real == obj.real && imag == obj.imag);
    }

    bool operator!=(const Complex &obj) const {
        return !(*this == obj);
    }

    // Friend functions for input/output
    friend istream &operator>>(istream &input, Complex &obj);
    friend ostream &operator<<(ostream &output, const Complex &obj);
};

// Overload '>>' operator for input (with validation)
istream &operator>>(istream &input, Complex &obj) {
    Answer validator;
    obj.real = validator.input("Enter real part: ");
    obj.imag = validator.input("Enter imaginary part: ");
    return input;
}

// Overload '<<' operator for output
ostream &operator<<(ostream &output, const Complex &obj) {
    output << "(" << obj.real << ", " << obj.imag << "i)";
    return output;
}

int main() {
    Complex c1, c2, c3;

    cout << "Enter first complex number:\n";
    cin >> c1;
    cin.ignore(); // to clear buffer

    cout << "\nEnter second complex number:\n";
    cin >> c2;
    cin.ignore();

    cout << "\nFirst Complex Number: " << c1;
    cout << "\nSecond Complex Number: " << c2;

    c3 = c1 * c2;
    cout << "\n\nMultiplication Result: " << c3;

    if (c1 == c2)
        cout << "\nBoth complex numbers are equal.";
    else
        cout << "\nComplex numbers are not equal.";

    return 0;
}
