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

long sum_below(int n) {
    long sum = 0;
    int i = 2;
    while(i < n) {
        if(is_prime(i)) {
            sum += i;
        }
        ++i;
    }
    return sum;
}
int main() {

    cout << "sum below 10: " << sum_below(10) << endl;
    cout << "sum below 2,000,000: " << sum_below(2000000) << endl;
	return 0;
}
