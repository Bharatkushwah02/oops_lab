#include <iostream>
#include <string>
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
            if (!isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }

    long long get_input(const string msg) {
        string str;
        while (true) {
            cout << msg;
            getline(cin, str);
            if (Is_string(str)) {
                try {
                    long long val = stoll(str);
                    return val;
                } catch (out_of_range &) {
                    cout << "Entered number is too large. Please try again.\n";
                }
            } else {
                cout << "Invalid input. Please enter a valid number.\n";
            }
        }
    }

public:
    long long input(const string &msg) {
        a = get_input(msg);
        return a;
    }
};

class Complex {
private:
    double real;
    double imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    Complex subtract(Complex c) {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }

    void print() {
        cout << "(" << real << ", " << imag << ")" << endl;
    }
};

int main() {
    Complex c1, c2, sum, diff;
    Answer ans;

    cout << "Enter values for first complex number:\n";
    long long r1 = ans.input("  Enter real part: ");
    long long i1 = ans.input("  Enter imaginary part: ");

    cout << "\nEnter values for second complex number:\n";
    long long r2 = ans.input("  Enter real part: ");
    long long i2 = ans.input("  Enter imaginary part: ");

    c1.setData(r1, i1);
    c2.setData(r2, i2);

    sum = c1.add(c2);
    diff = c1.subtract(c2);

    cout << "\n------------------ Results ------------------\n";
    cout << "First Complex Number: ";
    c1.print();

    cout << "Second Complex Number: ";
    c2.print();

    cout << "\nAddition: ";
    sum.print();

    cout << "Subtraction: ";
    diff.print();

    return 0;
}
