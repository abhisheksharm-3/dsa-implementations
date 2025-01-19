#include <iostream>
#include <string>
using namespace std;

string urlify(string str, int length) {
    int spaceCount = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    int index = length + spaceCount * 2;
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        } else {
            str[index - 1] = str[i];
            index--;
        }
    }
    return str;
}

int main() {
    string str = "Mr John Smith    ";
    cout << urlify(str, 13) << endl;
    return 0;
}