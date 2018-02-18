#include <iostream>
#include <string>
#include <math.h>

using namespace std;

long long pan_mult(int n, int max) {
    long long ret = 0;
    for(int i = 1; i <= max; ++i) {
        ret += n * i * (long long)pow(10, 2 * (max - i));
    }
    return ret;
}

int main() {

    cout << pan_mult(9, 5) << endl;
	return 0;
}
