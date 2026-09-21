/*
Q9. Check if a string is palindrome (a string on reversal reads the same).
*/

#include <bits/stdc++.h>
using namespace std;

/*
//Using Single Variable
bool isPalindrome(string str, int i) {
    
    if (i >= str.size()/2) {
        return true;
    }

    if (str[i] != str[str.size() - i - 1]) {
        return false;
    } else {
        return isPalindrome(str, i+1);
    }
}

int main() {
    string str = "MADAM";
    int i = 0;

    if (isPalindrome(str, i-1)) {
        cout << str << " is Palindrome";
    } else {
        cout << str << " is not Palindrome";
    }

    return 0;
}
*/

// Using Two Pointers
bool isPalindrome(string str, int l, int r) {

    if (l >= r) {
        return true;
    }

    if (str[l] != str[r]) {
        return false;
    } else {
        return isPalindrome(str, l+1, r-1);
    }

}

int main() {
    string str = "MADAM";
    int l = 0;
    int r = str.size();

    if (isPalindrome(str, l, r-1)) {
        cout << str << " is Palindrome";
    } else {
        cout << str << " is not a Palindrome";
    }

    return 0;
}