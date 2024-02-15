// based on 'Cracking the Coding Interview', Laakmann McDowell (6th)
// (edited and expanded a bit)
// compile and execute on a mac with:
// g++ square_root_manual.cpp -o square_root_manual
// ./square_root_manual

#include <iostream>
using namespace std;

// time complexity O(sqrt n)
int sqrt(int n) {
    for (int guess = 1; guess * guess <= n; guess++) {
        if (guess * guess == n) {
            cout << "sqrt: found " << guess << "\n";
            return guess;            
        }
    }
    cout << "sqrt: square root not found\n";
    return -1; // didn't find sqrt
}

// time complexity O(log N)
int sqrt_binary_search(int n, int min, int max) {
    if (max < min) {
        cout << "sqrt_fast: square root not found\n";
        return -1; 
    }
    
    int guess = (min + max) / 2;
    if (guess * guess == n) {
        cout << "sqrt_fast: found " << guess << "\n";
        return guess;
    } else if (guess * guess < n) { // guess was too low
        return sqrt_binary_search(n, guess + 1, max);
    } else { // guess was too high
        return sqrt_binary_search(n, min, guess - 1);
    }
} 

int sqrt_fast(int n) {
    return sqrt_binary_search(n, 1, n); 
    }

int main() {
    int target;
    cout << "Enter value you want sqrt of: ";
    cin >> target;
    sqrt(target);
    sqrt_fast(target);
}