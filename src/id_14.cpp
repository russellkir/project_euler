#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int collatz(int n) {
    //cout << n << "-";
    int count = 1;
    while (n != 1) {
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = 3*n + 1;
        }
        ++count;
        if(count > pow(10,8)) break;
        //cout << n << "-"; 
    }
    //cout << endl;
    return count;
}

int longest_c(int n) {
    int longest = 0;
    int tmp_i = 0;
    for(int i = 1; i < n; ++i) {
        int tmp = collatz(i);
        cout << i << ": " << tmp << endl;
        if(tmp > longest) {
            longest = tmp;
            tmp_i = i;
        }
    }
    return tmp_i;
}
int main() {

    cout << collatz(13) << endl;
    cout << collatz(113383) << endl;
    cout << longest_c(1000000) << endl;
	return 0;
}
