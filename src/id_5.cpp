#include <iostream>
using namespace std;

bool divisible(int n, int max) {
    for(int i = 1; i <= max; ++i) {
        if(n % i) {
            return false;
        }
    }
    return true;
}

int smallest_mult(int max) {
    int number = 10;
    while(!divisible(number, max)) {
        ++number;
    }
    return number;
}

int main() {
    cout << smallest_mult(20) << endl;
	return 0;
}
