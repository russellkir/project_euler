#include <iostream>
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

long nth_prime(int n){
    int count = 1;
    int i = 0;
    while(count <= n) {
        if(is_prime(i)) {
            ++count;
        }
        ++i;
    }
    return --i;
}

int main() {
    cout << "6th prime: " << nth_prime(6) << endl;
    cout << "1001th prime: " << nth_prime(1001) << endl;
    cout << "10001th prime: " << nth_prime(10001) << endl;
	return 0;
}
