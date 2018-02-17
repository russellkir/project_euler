#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool sum_of_cubes(int n) {
    int sum = 0;
    int init = n;
    while (init > 0) {
        int a = init % 10;
        sum += pow(a, 5);
        init /= 10;
    }
    return n == sum;
}

vector<int> sums(int min, int max) {
    vector<int> ret;
    for(int i = min; i < max; ++i) {
        if(sum_of_cubes(i)) {
            cout << i << endl;
            ret.push_back(i);
        }
    }
    return ret;
}

int main() {

    /*
    cout << sum_of_cubes(1634) << endl;
    cout << sum_of_cubes(8208) << endl;
    cout << sum_of_cubes(9474) << endl;
    cout << sum_of_cubes(9475) << endl;
    */
    vector<int> vec = sums(2, 10000000);

    int sum = 0;
    for(int v : vec) {
        sum += v;
    }
    cout << sum << endl;
	return 0;
}
