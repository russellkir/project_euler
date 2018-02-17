#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void permute(vector<int> &vec, int p){
    for(int i = 0; i < p - 1; ++i) {
        next_permutation(vec.begin(), vec.end());
    }
}
int main() {

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    permute(v, 1000000);
    for(auto i : v) {
        cout << i << "";
    }
    cout << endl;
	return 0;
}
