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

int num_pfacts(int n, int max) {
    int count = 0;
    for(int i = 2; i < n/2 + 1; ++i) {
        if(is_prime(i) && n % i == 0) {
            ++count;
            if(count > max) {
                return -1;
            }
        }
    }
    return count;
}

void distinct(int max, int count) {
    for(int i = 1; i < max; ++i) {
        if(num_pfacts(i, count) == count &&
           num_pfacts(i+1, count) == count &&
           num_pfacts(i+2, count) == count &&
           num_pfacts(i+3, count) == count) {
            cout << i << "," << (i+1) << 
                "," << (i+2) << "," << (i+3) << endl;
        }
    }
}

int main() {

    distinct(1000000, 4);
	return 0;
}
