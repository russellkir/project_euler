#include <iostream>
using namespace std;

long long fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    long long a = 0;
    long long b = 1;
    long long c;
    for(int i = 2; i <= n; ++i) {
        c = a+b;
        a = b;
        b = c;
    }
    return b;
}

long long sum(long long n) {
    long long even_sum = 0;

    int count = 1;
    long long tmp = fib(count);
    while(tmp < n) {
        cout << tmp << endl;
        if(tmp % 2 == 0) {
            even_sum += tmp;
        }
        tmp = fib(++count);

    }
    return even_sum;
}

int main() {

    long long s = sum(4000000);
    cout << "sum: " << s << endl;
	return 0;
}
