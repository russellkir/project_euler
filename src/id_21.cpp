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

int sum_divisors(int n){
    int d_sum = 0;
    if(is_prime(n)) {
        return 1;
    }

    for(int i = 1; i <= n/2; ++i) {
        if(n % i == 0) {
            d_sum += i;
        }
    }
    return d_sum;
}

bool amicable(int a, int b) {
    return a == sum_divisors(b) && b == sum_divisors(a);
}

int amicable_sum(int max){
    long sum = 0;
    for(int i = 1; i < max; ++i) {
        for(int j = i; j < max; ++j) {
            if(i != j && amicable(i, j)) {
                cout << "("<<i<<","<<j<<")"<<endl;
                sum += (i+j);
            }
        }
    }
    return sum;
}
int main() {

    cout << amicable_sum(10000) << endl;
	return 0;
}
