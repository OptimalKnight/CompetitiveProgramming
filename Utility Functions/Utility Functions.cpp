// Author: OptimalKnight
#include <bits/stdc++.h>
using namespace std;

#define int long long int

// Function to calculate ceiling of (A/B) given A and B
int _ceiling(int A, int B) {
    if (A % B) {
        return (A / B) + 1;
    }
    return (A / B);
}

// Function to return the gcd of the given two numbers
int _gcd(int A, int B) {
    if (!B) {
        return A;
    }
    return gcd(B, A % B);
}

// Function to return A raised to power B given A and B
int _power(int A, unsigned int B) {
    int res = 1;
    while (B > 0) {
        if (B & 1)
        {
            res *= A;
        }
        A *= A;
        B = (B >> 1);
    }
    return res;
}

signed main() {
    cout << "_ceiling(9, 7): " << _ceiling(9, 7) << endl;
    cout << "_gcd(20, 8): " << _gcd(20, 8) << endl;
    cout << "_power(5, 3): " << _power(5, 3) << endl;
}