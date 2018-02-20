#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int tri_num(int n) {
    return n * (n + 1) / 2;
}

int pent_num(int n) {
    return n * (3*n - 1) / 2;
}

int hex_num(int n) {
    return n * (2*n - 1);
}

void find(int max) {
    vector<int> t;
    vector<int> p;
    vector<int> h;
    for(int i = 1; i < max; ++i) {
        t.push_back(tri_num(i));
        p.push_back(pent_num(i));
        h.push_back(hex_num(i));
    }

    for(int i = 0; i < max; ++i) {
        vector<int>::iterator pit;
        vector<int>::iterator hit;
        pit = find(p.begin(), p.end(), t[i]);
        if(pit != p.end() ) {
            hit = find(h.begin(), h.end(), t[i]);
            if(hit != h.end() ) {
                    t[i] << ", " << *pit << ", " << *hit << endl;
            }
        }
    }
}
int main() {

    find(10);
	return 0;
}
