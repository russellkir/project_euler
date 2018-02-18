#include <iostream>
#include <vector>
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

vector<int> rots(int num) {

    vector<int> ret;
    int d = 0;
    int x = num;
    for(; x != 0; x /= 10, d++);

    int orig = num;
    int q = (int)pow(10, d - 1);
    for(int i = 0; i < d; ++i) {
        int tmp = (orig % q) * 10 + orig / q;
        ret.push_back(tmp);
        orig = tmp;
    }
    return ret;
}

bool prime_rot(vector<int> vec) {
    for(int v : vec) {
        if(!is_prime(v)) {
            return false;
        }
    }
    return true;
}

int sum_primes(int max) {
    int count = 0;
    for(int i = 1; i <= max; ++i) {
        if(prime_rot(rots(i))) {
            ++count;
        }
    }
    return count;
}

int main() {

    cout << sum_primes(1000000) << endl;

	return 0;
}
