#include <iostream>
#include <math.h>

using namespace std;

// AKS implementation of prime number check
bool is_prime(int n) {
    if(n <= 1) {
        return false;
    }
    if(n <= 3) {
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for(int i = 5; i*i <= n; i += 6) {
        if(n % i == 0 || n % (i+2) == 0) {
            return false;
        }
    }
    return true;
}

int prime_factor(long n) {
    for(int i = sqrt(n); i > 0; i--) {
        if(is_prime(i) && n % i == 0) {
            return i;
        }
    }
    return 0;
}

int main() {

    cout << "13195 lpf: " << prime_factor(13195) << endl;
    cout << "600851475143 lpf: " << prime_factor(600851475143) << endl;
	return 0;
}
