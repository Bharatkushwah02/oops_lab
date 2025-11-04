#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

template <typename T>
class Answer {
    T a;

    bool Is_number(const string &str) {
    if (str.empty()) return false;

    int dotCount = 0;  // count how many '.' appear

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // allow + or - only at first position
        if ((ch == '+' || ch == '-') && i == 0)
            continue;

        // allow only one dot in the number
        else if (ch == '.') {
            dotCount++;
            if (dotCount > 1)
                return false; // more than one dot not allowed
        }

        // all other characters must be digits
        else if (!isdigit(ch))
            return false;
    }

    return true;
}


    T get_input(const string &msg) {
        string str;
        while (true) {
            cout << msg;
            getline(cin, str);

            if (Is_number(str)) {
                try {
                    stringstream ss(str);
                    T val;
                    ss >> val;
                    if (!ss.fail()) return val;
                } catch (...) {
                    cout << "Input out of range. Please try again.\n";
                }
            } else {
                cout << "Invalid number. Please try again.\n";
            }
        }
    }

public:
    T input(const string &msg = "Enter the number: ") {
        a = get_input(msg);
        return a;
    }
};

int main() {

    Answer<double> ans2;
    double x = ans2.input("Enter the value of x: ");

    Answer<int> ans1;
    int n = ans1.input("Enter number of terms (for accuracy): ");

    double term = 1.0;  // first term = 1
    double sum = 1.0;   // sum starts with 1 (first term of series)

    for (int i = 1; i <= n; i++) {
        term = term * (x / i); // x^i / i!
        sum += term;
    }

    cout << "\nThe value of e^" << x << " is approximately: " << sum << endl;
    return 0;
}
