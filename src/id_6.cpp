#include <iostream>
#include <math.h>
using namespace std;

long sum_of_squares(int n) {
    long temp = 0;
    for(int i = 1; i <= n; ++i) {
        temp += pow(i, 2);
    }
    return temp;
}

long sq_of_sum(int n) {
    long temp = 0;
    for(int i = 1; i <= n; ++i) {
        temp += i;
    }
    return pow(temp, 2);
}

long difference(int n) {
    return sq_of_sum(n) - sum_of_squares(n);
}
int main() {

    cout << "difference(10): " << difference(10) << endl;
    cout << "difference(100): " << difference(100) << endl;
	return 0;
}
