#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

int num_primes(int a, int b) {
    int n = 0;
    while(is_prime(n*n + a*n + b)) {
        ++n;
    }
    return n;
}

int max_primes(int max) {
    int max_count = 0;
    int max_a = 0;
    int max_b = 0;
    for(int a = -max; a < max; ++a) {
        for(int b = -max; b <= max; ++b) {
            int tmp = num_primes(a, b);
            if(tmp > max_count) {
                max_count = tmp;
                max_a = a;
                max_b = b;
            }
        }
    }
    cout << max_a << ", " << max_b << endl;
    return max_count;
}

int main() {

    max_primes(1000);
	return 0;
}
