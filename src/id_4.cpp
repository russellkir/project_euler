#include <iostream>
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

long largest_pal(int n) {
    int range = pow(10, n);
    long largest = 0;
    for(int i = 0; i < range; ++i) {
        for(int j = i; j < range; ++j) {
            long temp_m = i*j;
            if (is_palindrome(temp_m)) {
                largest = max(largest, temp_m);
            }
        }
    }
    return largest;
}

int main() {
    cout << largest_pal(2) << endl;;
    cout << largest_pal(3) << endl;;
    cout << largest_pal(4) << endl;;
	return 0;
}
