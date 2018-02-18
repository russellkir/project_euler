#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int fact(int n) {
    int sum = 1;
    for(int i = n; i > 0; --i) {
        sum *= i;
    }
    return sum;
}
bool is_digitfact(int n){
    int sum = 0;
    int orig = n;
    while(n != 0) {
        int a = n % 10;
        sum += fact(a);
        n /= 10;
    }
    return sum == orig; 
}

int sum_digfact(int max) {
    int sum = 0;
    for(int i = 3; i < max; ++i) {
        if(is_digitfact(i)) {
            sum += i;
        }
    }
    return sum;
}
int main() {
    cout << "sum: " << sum_digfact(10000000) << endl;
	return 0;
}
