
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

