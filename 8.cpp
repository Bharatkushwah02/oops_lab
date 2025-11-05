#include <iostream>
#include <cstring>  // strtok ke liye
#include <vector>   // tokens store karne ke liye
using namespace std;

int main() {
    char line[200];
    cout << "Enter a line of text: ";
    cin.getline(line, 200);   // line input lena

    vector<string> tokens;    // words store karne ke liye

    // strtok use karke split karna
    char *token = strtok(line, " ");
    while (token != NULL) {
        tokens.push_back(token);
        token = strtok(NULL, " ");
    }

    // reverse order me print karna
    cout << "\nTokens in reverse order:\n";
    for (int i = tokens.size() - 1; i >= 0; i--) {
        cout << '"' << tokens[i] << '"' << " ";
    }
    cout << endl;

    return 0;
}
