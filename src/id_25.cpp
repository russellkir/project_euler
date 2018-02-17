#include <iostream>
#include <string>
#include <gmp.h>
#include <gmpxx.h>
#include <math.h>

using namespace std;

mpz_class fib(mpz_class n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    mpz_class a, b, c;
    a = 0;
    b = 1;
    for(int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int sizeOf(mpz_class n) {
    int size = 0;
    while(n > 0) {
        ++size;
        n /= 10;
    }
    return size;
}

mpz_class fib_length(mpz_class n) {
    mpz_class i = 1;
    int size = sizeOf(fib(i));
    while(size < n) {
        size = sizeOf(fib(++i));
    }
    return i;
}

int main() {

    cout << "1000: " << fib_length(1000) << endl;
	return 0;
}
