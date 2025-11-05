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

    long long get_input(const string &msg) {
        string str;
        while (true) {
            cout << msg;
            getline(cin, str);

            if (Is_string(str)) {
                try {
                    long long val = stoll(str);
                    return val;
                } catch (out_of_range &) {
                    cout << "❌ Number too large! Try again.\n";
                }
            } else {
                cout << "❌ Invalid input! Please enter a valid number.\n";
            }
        }
    }

public:
    long long input(const string &msg) {
        a = get_input(msg);
        return a;
    }
};

// ========== Class that can throw exception in constructor ==========
class Demo {
    int value;

public:
    Demo(int v) {
        cout << "\n[Constructor] Called with value = " << v << endl;

        if (v < 0) {
            throw runtime_error("Constructor Error: Negative value not allowed!");
        }

        value = v;
        cout << "[Constructor] Object constructed successfully with value = " << value << endl;
    }

    ~Demo() {
        cout << "[Destructor] Called for value = " << value << endl;
    }
};

// ========== MAIN FUNCTION ==========
int main() {
    Answer ans;

    cout << "=== Constructor Exception Handling with Input Validation ===\n";

    try {
        int val = ans.input("Enter a number (non-negative): ");
        Demo obj(val); // Constructor may throw exception
    }
    catch (const runtime_error &e) {
        cout << "\n⚠️ Exception Caught: " << e.what() << endl;
    }

    cout << "\nProgram ended safely ✅\n";
    return 0;
}
