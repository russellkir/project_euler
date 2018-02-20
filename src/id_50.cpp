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

int prime_sum(vector<int> primes, int j, int k, int max) {
    int sum = 0;
    for(int i = j; i <= k; ++i) {
        sum += primes[i];
        if(sum > max) {
            return sum;
        }
    }
    return sum;
}

vector<int> make_primes(int ith){
    vector<int> primes;
    for(int i = 2; i < ith; ++i) {
        if(is_prime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int longest_sum(vector<int> primes, int max) {
    int max_p = 0;
    int max_d = 0;
    for(int i = 0; i < (int)primes.size(); ++i) {
        for(int j = i; j < (int)primes.size(); ++j) {
            int diff = abs(j-i);
            int tmp = prime_sum(primes, i, j, max);
            if(is_prime(tmp) && diff > max_d) {
                if(tmp > max_p && tmp < max) {
                    max_p = tmp;
                    max_d = diff;
                }
            }
        }
    }
    return max_p;
}

int main() {

    vector<int> primes = make_primes(25000);

    cout << longest_sum(primes, 1000000) << endl;
	return 0;
}
