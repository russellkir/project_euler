#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


int main() {

    vector<string> vec;
    string line;
    ifstream file("id_13.txt");
    if(file.is_open()) {
        while(getline(file, line, ',')) {
            vec.push_back(line);
        }
        file.close();
    } else {
        cout << "Can't open names.txt" << endl;
    }

	return 0;
}
