#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int sum(string s) {
    int sum = 0;
    for(char c : s) {
        sum += (c - '0');
    }
    return sum;
}
int main() {

    string s = "93326215443944152681699238856266700490715968264381621468592963"
        "895217599993229915608941463976156518286253697920827223758251185210916"
        "864000000000000000000000000";
    cout << sum(s) << endl;
	return 0;
}
