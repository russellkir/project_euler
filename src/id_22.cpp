#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int score(vector<string> words) {
    sort(words.begin(), words.end());
    long long score = 0;
    for(int i = 0; i <= (int)words.size(); ++i) {
        string word = words[i];
        int tmp = 0;
        for(int j = 1; j < (int)word.size() - 1; ++j) {
            tmp += tolower(word[j]) - 96;
        }
        score += ((i+1) * tmp);
    }
    return score;
}

int main() {

    vector<string> words;
    string line;
    ifstream file("names.txt");
    if(file.is_open()) {
        while(getline(file, line, ',')) {
            words.push_back(line);
        }
        file.close();
    } else {
        cout << "Can't open names.txt" << endl;
    }

    cout << score(words) << endl;
	return 0;
}
