#include <iostream>
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
                    if (val <= 0) {
                        cout << "Please enter a positive number greater than 0.\n";
                        continue;
                    }
                    return val;
                } catch (out_of_range&) {
                    cout << "Entered number is too large! Please try again.\n";
                }
            } else {
                cout << "Invalid input! Please enter a valid number.\n";
            }
        }
    }

public:
    long long input() {
        a = get_input("Enter the number of disks: ");
        return a;
    }
};

void towerOfHanoi(int n, char source, char destination, char helper) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, helper, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, helper, destination, source);
}

int main() {
    Answer ans;
    int n = ans.input();
    cout << "\nSteps to solve Tower of Hanoi:\n";
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
