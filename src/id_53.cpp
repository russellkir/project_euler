#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

unsigned long long int fact(int n) {
    if(n == 0) return 1;
    unsigned long long int f = 1;
    for(int i = n; i > 0; --i) {
        f *= i;
    }
    return f;
}

unsigned long long int ncr(int n, int r){
    return fact(n) / (fact(r) * fact(n - r));
}

void combo(int i) {
    for(int k = 0; k < i; ++k) {
        cout << i << "C" << k << ": " << ncr(i, k) << endl;
    }
}
int main() {

    cout << fact(23) << endl;
    cout << fact(10) << endl;
    cout << fact(13) << endl;
    cout << fact(23) / (fact(10) * fact(13)) << endl;
    combo(23);
	return 0;
}
