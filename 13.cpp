#include <iostream>
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

// ========== Template Function ==========
template <typename T>
bool isEqualTo(T a, T b) {
    return (a == b);
}

// ========== Main Function ==========
int main() {
    Answer input;
    cout << boolalpha; // prints true/false instead of 1/0

    cout << "=== Comparing Built-in Types ===\n";
    int x = input.input("Enter first integer: ");
    int y = input.input("Enter second integer: ");
    cout << "Are they equal? " << isEqualTo(x, y) << endl;

    double d1 = 3.14, d2 = 3.14;
    cout << "\nComparing doubles: " << isEqualTo(d1, d2) << endl;

    char c1 = 'A', c2 = 'B';
    cout << "Comparing chars: " << isEqualTo(c1, c2) << endl;

    string s1 = "Bharat", s2 = "Bharat";
    cout << "Comparing strings: " << isEqualTo(s1, s2) << endl;

    return 0;
}
