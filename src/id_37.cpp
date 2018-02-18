#include <iostream>
#include <string>
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

int int_len(int n) {
    int len = 0;
    for(; n != 0; n /= 10, ++len);
    return len;
}

int lt(int n) {
    return (n % (int)pow(10, int_len(n) - 1));
}

int rt(int n){
    return n / 10;
}

bool trunc_prime(int n) {
    int orig = n;
    while(orig != 0) {
        if(!is_prime(orig)) return false;
        orig = lt(orig);
    }
    orig = n;
    while(orig != 0) {
        if(!is_prime(orig)) return false;
        orig = rt(orig);
    }
    return true;
}

int trunc_sum(int max) {
    int sum = 0;
    for(int i = 8; i < max; ++i) {
        if(trunc_prime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    cout << trunc_sum(1000000) << endl;
	return 0;
}
