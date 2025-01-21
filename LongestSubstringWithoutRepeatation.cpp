#include <iostream>
#include <set>
#include <string>

using namespace std;

int LongestSubstringWithoutRepeatation(string s) {
    int left = 0, right = 0, res = 0;
    set<char> St;

    while (right < s.size()) {
        // If the character is already in the set, remove from the left
        while (St.find(s[right]) != St.end()) {
            St.erase(s[left]);
            left++;
        }

        // Add the current character to the set
        St.insert(s[right]);
        
        // Update the result (current window size)
        res = max(res, right - left + 1);
        
        // Move the right pointer
        right++;
    }

    return res;
}

int main() {
    string s = "aaabbcaab";
    cout << "The string is: " << s << "\n";
    int length = LongestSubstringWithoutRepeatation(s);
    cout << "Length of the longest substring without repetition: " << length << endl;

    return 0;
}
