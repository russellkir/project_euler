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

int int_len(int n) {
    int len = 0;
    for(; n != 0; n /= 10, ++len);
    return len;
}

bool pandig(int n) {
    vector<int> vec;
    int a = 0;
    while(n != 0) {
        a = n % 10;
        vec.push_back(a);
        n /= 10;
    }
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= (int)vec.size(); ++i) {
        if(vec[i - 1] != i) {
            return false;
        }
    }
    return true;
}

bool pan_prime(int n) {
    return (pandig(n) && is_prime(n));
}

int largest_pp(int max) {
    int largest = 0;
    for(int i = 1; i <= max; ++i) {
        if(pan_prime(i)) {
            int tmp = i;
            if(tmp > largest) {
                largest = tmp;
            }   
        }
    }
    return largest;
}

int main() {
    cout << largest_pp(10000000) << endl;
	return 0;
}
