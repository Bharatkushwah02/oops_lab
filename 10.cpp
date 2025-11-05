#include <iostream>
#include <string>
using namespace std;

class MyString {
    string str;

public:
    MyString() {}

    MyString(string s) {
        str = s;
    }

    void display() const {
        cout << str << endl;
    }

    MyString operator+(const MyString &obj) {
        MyString temp;
        temp.str = str + obj.str; // Concatenate the two strings
        return temp;
    }
};

int main() {
    MyString string1("HARE ");
    MyString string2("KRISHNA");
    MyString string3;

    string3 = string1 + string2;

    cout << "Result after concatenation: ";
    string3.display();

    return 0;
}
