#include <string>
#include <iostream>
using namespace std;

bool isUniqueString(string str) {
    if (str.length() > 128) {
        return false;
    }
    bool char_set[128] = {false};
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (char_set[val]) {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

int main() {
    string str = "abcdee";
    cout << isUniqueString(str) << endl;
    return 0;
}