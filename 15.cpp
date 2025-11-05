#include <iostream>
using namespace std;

class Demo {
    string name;
public:
    Demo(string n) {
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    ~Demo() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    cout << "Program started\n";

    try {
        cout << "\nEntering try block\n";

        Demo obj1("Object 1");
        Demo obj2("Object 2");
        Demo obj3("Object 3");

        cout << "Now throwing an exception...\n";
        throw 99; // Exception throw kar diya

        cout << "This line will not execute.\n";
    }
    catch (int x) {
        cout << "\nException caught: " << x << endl;
    }

    cout << "\nProgram ended normally.\n";
    return 0;
}

