#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkPermutationSort(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}
bool checkPermutationCount(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    int char_set[128] = {0};
    for (int i = 0; i < str1.length(); i++) {
        char_set[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++) {
        char_set[str2[i]]--;
        if (char_set[str2[i]] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1 = "abcdee";
    string str2 = "edecba";
    cout << checkPermutationSort(str1, str2) << endl;
    cout << checkPermutationCount(str1, str2) << endl;
    return 0;
}