#include <iostream>
#include <string>
#include <stdexcept>
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

// ========== Base Exception Class ==========
class BaseException {
public:
    virtual string what() const {
        return "Base Exception Occurred!";
    }
};

// ========== Derived Exception Classes ==========
class DivideByZero : public BaseException {
public:
    string what() const override {
        return "Error: Division by zero is not allowed!";
    }
};

class NegativeNumber : public BaseException {
public:
    string what() const override {
        return "Error: Negative number is not allowed!";
    }
};

class OutOfRangeException : public BaseException {
public:
    string what() const override {
        return "Error: Value out of allowed range (0–1000)!";
    }
};

// ========== Function That Can Throw Exceptions ==========
double safeDivide(int a, int b) {
    if (b == 0)
        throw DivideByZero();
    return static_cast<double>(a) / b;
}

void checkNumber(int num) {
    if (num < 0)
        throw NegativeNumber();
    else if (num > 1000)
        throw OutOfRangeException();
}

// ========== MAIN FUNCTION ==========
int main() {
    Answer input;
    try {
        int num1 = input.input("Enter first number: ");
        int num2 = input.input("Enter second number: ");

        checkNumber(num1);
        checkNumber(num2);

        double result = safeDivide(num1, num2);
        cout << "\nResult = " << result << endl;
    }

    // Base class handler — can catch all derived exceptions
    catch (BaseException &ex) {
        cout << "\nCaught Exception: " << ex.what() << endl;
    }

    cout << "\nProgram ended safely.\n";
    return 0;
}
