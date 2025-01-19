#include <iostream>
#include <string>
using namespace std;

bool isPermutationOfPalindrome(string str) {
    int char_set[128] = {0};
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            char_set[tolower(str[i])]++;
        }
    }
    int odd_count = 0;
    for (int i = 0; i < 128; i++) {
        if (char_set[i] % 2 != 0) {
            odd_count++;
        }
    }
    return odd_count <= 1;
}

int main() {
    string str = "tact coa";
    cout << boolalpha << isPermutationOfPalindrome(str) << endl;
    str = "racecar";
    cout << boolalpha << isPermutationOfPalindrome(str) << endl;
    str = "hello";
    cout << boolalpha << isPermutationOfPalindrome(str) << endl;
    str = "aabbccddee";
    cout << boolalpha << isPermutationOfPalindrome(str) << endl;
    return 0;
}
