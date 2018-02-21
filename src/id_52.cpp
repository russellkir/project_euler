#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<int> i2v(int i) {
    vector<int> ret;
    while(i > 0) {
        ret.push_back(i%10);
        i /= 10;
    }
    reverse(ret.begin(), ret.end()); 
    return ret;
}
bool same2x(int x){
    vector<int> vx = i2v(x);
    vector<int> v2x = i2v(2*x);
    sort(vx.begin(), vx.end());
    sort(v2x.begin(), v2x.end());
    return vx == v2x;
}

bool same6x(int x) {
    vector<int> vx = i2v(x);
    vector<int> v2x = i2v(2*x);
    vector<int> v3x = i2v(3*x);
    vector<int> v4x = i2v(4*x);
    vector<int> v5x = i2v(5*x);
    vector<int> v6x = i2v(6*x);
    sort(vx.begin(), vx.end());
    sort(v2x.begin(), v2x.end());
    sort(v3x.begin(), v3x.end());
    sort(v4x.begin(), v4x.end());
    sort(v5x.begin(), v5x.end());
    sort(v6x.begin(), v6x.end());
    if(vx != v2x) return false;
    if(v2x != v3x) return false;
    if(v3x != v4x) return false;
    if(v4x != v5x) return false;
    if(v5x != v6x) return false;
    return true;
}

int min6x() {
    int i = 1;
    while(!same6x(i)) {
        ++i;
    }
    return i;
}

int main() {

    cout << min6x() << endl;

	return 0;
}
