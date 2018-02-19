#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool is_tri(int n){
    for(int i = 1; i <= n; ++i) {
        if(n == i*(i+1)/2) {
            return true;
        }
    }
    return false;
}

int word_to_num(string s) {
    int sum = 0;
    for(char c : s) {
        sum += (c - 64);
    }
    return sum;
}

bool tri_word(string s) {
    return is_tri(word_to_num(s));
}

int tri_word_count(vector<string> words) {
    int count = 0;
    for(string word : words) {
        if(tri_word(word)) {
            ++count;
        }
    }
    return count;
}

int main() {
    
    vector<string> words;
    string line;
    ifstream file("id_42.txt");
    if(file.is_open()) {
        while(getline(file, line, ',')) {
            string tmp = line.erase(0, 1);
            words.push_back(tmp.erase(tmp.size()-1,1));
        }
        file.close();
    } else {
        cout << "Can't open names.txt" << endl;
    }

    cout << tri_word_count(words) << endl;
	return 0;
}
