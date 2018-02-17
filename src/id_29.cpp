#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int combos(int a, int b){
    unordered_set<double> set_combos;

    int count = 0;
    for(int i = a; i <= b; ++i) {
        for(int j = a; j <= b; ++j) {
            double d = pow(i, j);
            if(set_combos.find(d) == set_combos.end() ) {
                set_combos.insert(d);
                ++count;
            }
        }
    }
    return count;
}

int main() {

    cout << combos(2, 100) << endl;;
	return 0;
}
