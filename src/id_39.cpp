#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool is_right(int a, int b, int c) {
    return pow(a,2) + pow(b,2) == pow(c,2);
}

int per(int i, int j, int k) {
    return i + j + k;
}

int num_tri(int max, int p) {
    int count = 0;
    for(int i = 1; i <= max; ++i) {
        for(int j = i; j <= max; ++j) {
            for(int k = j; k <= max; ++k) {
                if(per(i, j, k) == p && is_right(i, j, k)) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int max_p(int max) {
    int max_count = 0;
    int max_p = 0;
    for(int i = 0; i <= max; ++i) {
        int count = num_tri(max, i);
        cout << i << ": " << count << endl;
        if(count > max_count) {
            max_count = count;
            max_p = i;
        }
    }
    return max_p;
}

int main() {

    num_tri(150, 120);
    cout << max_p(1000) << endl;
	return 0;
}
