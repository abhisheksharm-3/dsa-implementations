#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
void sortAnagrams(vector<string> &aanagrams){
    unordered_map<string, vector<string>> anagrams;
    for (string &s : aanagrams){
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        anagrams[sorted].push_back(s);
    }
    int index = 0;
    for (auto &p : anagrams){
        for (string &s : p.second){
            aanagrams[index++] = s;
        }
    }
}

int main() {
    vector<string> arr = {"cat", "dog", "tac", "god", "act"};
    cout << "Original array: ";
    for (string &s : arr) cout << s << " ";
    cout << endl;
    
    sortAnagrams(arr);
    
    cout << "Sorted array: ";
    for (string &s : arr) cout << s << " ";
    cout << endl;
    
    return 0;
}