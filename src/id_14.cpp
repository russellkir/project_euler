#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

// cache for memoization
vector<int> cache(10000000, -1);

int collatz(long n) {
    // base case
    if(n == 1) {
        return 1;
    }
    // check if in cache
    if(n < (long)cache.size() && cache[n] != -1) {
        return cache[n];
    }
    long np1;
    if(n % 2 == 0) {
        np1 = n / 2;
    } else {
        np1 = n*3 + 1;
    }
    long result = 1 + collatz(np1);
    if(n < (long)cache.size() ) {
        cache[n] = result;
    }
    return result;
}

int longest_c(int n) {
    int longest = 0;
    int tmp_i = 0;
    for(int i = 1; i < n; ++i) {
        int tmp = collatz(i);
        if(tmp > longest) {
            longest = tmp;
            tmp_i = i;
        }
    }
    return tmp_i;
}
int main() {

    cout << longest_c(1000000) << endl;
	return 0;
}
