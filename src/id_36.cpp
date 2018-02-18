#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool is_palindrome(int n) {
    int a = 0;
    int b = n;
    int temp = 0;

    while(n > 0) {
        a = n % 10;
        n = n / 10;
        temp = (temp*10) + a;
    }
    if(temp == b) {
        return true;
    } else {
        return false;
    }
}

long long to_binary(int n) {
    long long bin = 0;
    int r = 0;
    int i = 1;

    while (n != 0) {
        r = n % 2;
        n /= 2;
        bin += r*i;
        i *= 10;
    }
    return bin;
}

long long pal_sum(long long max){
    long long sum = 0;
    for(long long i = 1; i < max; ++i) {
        if(is_palindrome(i)) {
            if(is_palindrome(to_binary(i))) {
                cout << "--- 2: " << i << endl;
                cout << "------ b: " << to_binary(i) << endl;
                sum += i;
            }
        }
    }
    return sum;
}

int main() {

    cout << pal_sum(10000000) << endl;
    
	return 0;
}
