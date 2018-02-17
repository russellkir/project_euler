#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int length(int a, int b, map<int, int> nums, map<string, int> words){
    int sum = 0;
    for(int i = a; i <= b; ++i) {
        if(1 <= i && i <= 19) {
            sum += nums.find(i)->second;
        }
        else if(20 <= i && i <= 99) {
            int ones = i % 10;
            int tens = (i / 10) * 10;
            sum += (nums.find(ones)->second + 
                    nums.find(tens)->second);
        }
        else if(100 <= i && i <= 999) {
            int ones = i % 10;
            int tens = ((i / 10) % 10) * 10;
            int hnds = (i / 100);
            int oneandten = i % 100;
            if(1 <= oneandten && oneandten <= 19) {
                sum += (nums.find(hnds)->second +
                        words.find("hundred")->second +
                        words.find("and")->second +
                        nums.find(oneandten)->second);
            }
            else {
                // 100, 200, 300, ... , 900
                if(ones == 0 && tens == 0) {
                    sum += (nums.find(hnds)->second +
                            words.find("hundred")->second);
                }
                // 101, 202, 303, ... , 909
                else if(ones != 0 && tens == 0) {
                    sum += (nums.find(hnds)->second +
                            words.find("hundred")->second +
                            words.find("and")->second +
                            nums.find(ones)->second);
                }
                // 110, 220, 330, ... , 990
                else if(ones == 0 && tens != 0) {
                    sum += (nums.find(hnds)->second +
                            words.find("hundred")->second +
                            words.find("and")->second +
                            nums.find(tens)->second);
                }
                // 123, 234, 345, ... , 999 
                else if(ones != 0 && tens != 0) {
                    sum += (nums.find(hnds)->second +
                            words.find("hundred")->second +
                            words.find("and")->second +
                            nums.find(tens)->second +
                            nums.find(ones)->second);
                }
            }
        }
        else if(i == 1000){
            sum += (nums.find(i/1000)->second + 
                words.find("thousand")->second);
        }
    }
    return sum;
}
int main() {

    map<int, int> nums;
    map<string, int> words;

    nums[1] = 3;
    nums[2] = 3;
    nums[3] = 5;
    nums[4] = 4;
    nums[5] = 4;
    nums[6] = 3;
    nums[7] = 5;
    nums[8] = 5;
    nums[9] = 4;

    nums[10] = 3;
    nums[11] = 6;
    nums[12] = 6;
    nums[13] = 8;
    nums[14] = 8;
    nums[15] = 7;
    nums[16] = 7;
    nums[17] = 9;
    nums[18] = 8;
    nums[19] = 8;

    nums[20] = 6;
    nums[30] = 6;
    nums[40] = 5;
    nums[50] = 5;
    nums[60] = 5;
    nums[70] = 7;
    nums[80] = 6;
    nums[90] = 6;

    words["and"] = 3;
    words["hundred"] = 7;
    words["thousand"] = 8;

    cout << "1 through 1000:\n" << length(1, 1000, nums, words) << endl;
	return 0;
}
