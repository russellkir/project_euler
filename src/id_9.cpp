#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool is_pyth_trip(int a, int b, int c) {
    return pow(a,2) + pow(b,2) == pow(c,2);
}

long triplets(int sum, int max) {
    for(int a = 1; a < max; ++a) {
        for(int b = a+1; b < max; ++b) {
            for(int c = b+1; c < max; ++c) {
                if(is_pyth_trip(a,b,c)) {
                    if(a+b+c == sum) {
                        cout << a << " " << b << " " << c << endl;
                        return a*b*c;
                    }
                }
            }
        }
    }
    return 0L;
}

int main() {
    
    cout << "product: " << triplets(1000, 500) << endl;;
	return 0;
}
