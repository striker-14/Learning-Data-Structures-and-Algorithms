#include <iostream>
using namespace std;

void pattern1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "*";
        }
        cout << endl; // Move to the next row
    }
}

void pattern2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}

void pattern5(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern6(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i+1; j++) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern7(int n) {
    for (int i = 0; i < n; i++) {

        // Loop for Spaces
        for (int j = 0; j < n-i-1; j++) {
            cout << " ";
        }

        for (int j = 0; j < 2*i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern8(int n) {
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = 0; j < 2*n - 2*i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern9(int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n-i-1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2*i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2*n-2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n) {
    for (int i = 0; i < 2*n-1; i++) {

        int stars = i;
        
        if (i >= n) {
            stars = 2*n-i-2;
        }

        for (int j = 0; j <= stars; j++) {
            cout << "*";
        }
         cout << endl;
    }
}

void pattern11(int n) {
    int num;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num = 1;
        } else {
            num = 0;
        }
        for (int j = 0; j <= i; j++) {
            cout << num;
            num = 1 - num;
        }
        cout << endl;
    }
}

void pattern12(int n) {
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        
        // Spaces
        for (int j = 1; j <= 2*n - 2*i; j++) {
            cout << " ";
        }

        int num = i;
        for (int j = 1; j <= i; j++) {
            cout << num;
            num--;
        }
        cout << endl;
    }
}

void pattern13(int n) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern14(int n) {
    for (int i = 0; i < n; i++) {
        for (char j = 'A'; j <= 'A' + i; j++) { // Notice till where j loops (also the declaration of j as char)
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern15(int n) {
    for (int i = 0; i < n; i++) {
        for (char j = 'A'; j < 'A' + n - i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern16(int n) {
    char alpha = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << alpha << " ";
        }
        alpha += 1;
        cout << endl;
    }
}

void pattern17(int n) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        for (char j = 'A'; j <= 'A' + i; j++) {
            cout << j;
        }

        // Last Pattern
        char alpha = 'A' + i - 1;
        for (int j = 0; j < i; j++) {
            cout << alpha;
            alpha -= 1;
        }
        cout << endl;
    }
}

void pattern18(int n) {
    for (int i = 0; i < n; i++) {
        char alpha = 'E';
        alpha -= i;
        for (int j = 0; j <= i; j++) {
            cout << alpha;
            alpha += 1;
        }
        cout << endl;
    }
}

void pattern19(int n) {
    for (int i = 0; i < 2*n; i++) {

        int stars = n - i;
        if (i >= n) {
            stars = i - n + 1;
        }
        for (int j = 0; j < stars; j++) {
            cout << "*";
        }

        // Spaces
        int spaces = 2*i;
        if (i >= n) {
            spaces = 2*n - 2*(i - n + 1);
        }
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        int stars2 = n - i;
        if (i >= n) {
            stars2 = i - n + 1;
        }
        for (int j = 0; j < stars2; j++) {
            cout << "*";
        }
        
        cout << endl;
    }
}

void pattern20(int n) {
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }

        // 1 Spaces
        for (int j = 0; j < 2*n - 2*i - 2; j++) {
            cout << " ";
        }

        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // 2nd Half of vertical pattern (after 5th row)
    for (int i = 0; i < n-1; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            cout << "*";
        }

        // Spaces
        for (int j = 0; j < 2*i + 2; j++) {
            cout << " ";
        }

        for (int j = 0; j < n - i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern21(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n-1 || j == n-1) { // Print stars only at the boundaries (to make a square)
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void pattern22(int n) {
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            /* For every number find its top, left, right and bottom position, find which among them is minimum, then subtract it from n */
            int top = i; // Distance from top (is nothing but the row number, of the number in focus)
            int left = j;
            int right = (2*n - 2) - j;
            int bottom = (2*n - 2) - i;
            cout << n - min(min(top, bottom), min(left, right));
        }
        cout << endl;
    }
}

int main() {
    int t; // How many tests do you want to conduct
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; // Size of the pattern (each time)
        cin >> n;
        pattern22(n);
    }
}