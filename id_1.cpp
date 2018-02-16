#include <iostream>
using namespace std;

int sum(int n) {
	int sum = 0;
	for(int i = 1; i < n; ++i) {
       if(i % 3 == 0 || i % 5 == 0) {
       		sum += i;
	   }
	}
	return sum;
}

int main() {
	cout << "Hello World!" << endl;
	cout << sum(10) << endl;
	cout << sum(1000) << endl;
	return 0;
}
