#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

inline long nth_triangle(int n){
    return (n*n + n) / 2;
}

int is_fact(int n, int f) {
    return n % f == 0;
}

int num_divisors(int n){
    /*
    int num_div = 0;
    for(int i = 1; i <= n; ++i) {
        if(is_fact(n, i)) {
            ++num_div;
        }   
    }*/
    int divisors = 1;
    int count = 0;
    while(n % 2 == 0) {
        ++count;
        n /= 2;
    }
    divisors *= (count + 1);

    for(int i = 3; i <= n; i+= 2) {
        int count = 0;
        while(n % i == 0) {
            n /= i;
            ++count;
        }
        divisors *= (count + 1);
    }
    return divisors;
}

long n_divisors(int n) {
    long i = 1;
    long nth_tri = nth_triangle(i);
    while(true){
        cout << i << "th tri: " << nth_tri << endl;
        if(num_divisors(nth_tri) > n) {
            cout << nth_tri << endl;
            break;
        }
        nth_tri = nth_triangle(++i);
    }
    return i;
}

int main() {
    
    n_divisors(500);
	return 0;
}
