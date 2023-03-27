// Author: OptimalKnight
#include <bits/stdc++.h>
using namespace std;

#define int long long int

// Class to perform the modular arithmetic operations
class ModularArithmetic {
private:
    int maxn, mod;

public:
    vector<int> fac, inv;

    // Class constructor to initialise the factorials and inverse factorials
    ModularArithmetic(int N, int M) {
        maxn = N, mod = M;

        fac.assign(maxn + 1, 1);
        for (int i = 1; i <= maxn; i++) {
            fac[i] = (fac[i - 1] * i) % mod;
        }

        inv.assign(maxn + 1, {});
        inv[maxn] = invmod(fac[maxn]);
        for (int i = maxn; i >= 1; i--) {
            inv[i - 1] = (inv[i] * i) % mod;
        }
    }

    // Function to calculate A raised to power B modulo 'mod'
    int mpow(int A, unsigned int B) {
        int res = 1;
        A = (A % mod);
        while (B) {
            if (B & 1) {
                res = (res * A) % mod;
            }
            A = (A * A) % mod;
            B = (B >> 1);
        }
        return res;
    }

    // Function to calculate the inverse modulo of A with respect to 'mod'
    int invmod(int A) {
        return mpow(A, mod - 2);
    }

    // Function to calculate the number of ways of choosing R objects out of N objects modulo 'mod'
    int nCr(int N, int R) {
        if ((N < 0 )or (R < 0 )or (N < R)) {
            return 0;
        }
        if (!R) {
            return 1;
        }
        return (fac[N] * inv[R] % mod * inv[N - R] % mod) % mod;
    }
};

signed main() {
    int N = 100, M = 1e9 + 7;
    ModularArithmetic obj(N, M);

    cout << "Factorial of 97 (modulo " << M << "): " << obj.fac[97] << endl;
    cout << "Inverse factorial of 97 (modulo " << M << "): " << obj.inv[97] << endl;
    cout << "97 raised to power 97 (modulo " << M << "): " << obj.mpow(97, 97) << endl;
    cout << "Number of ways of chossing 47 objects out of 97 objects (modulo " << M << "): " << obj.nCr(97, 47) << endl;
}