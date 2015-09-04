#ifndef MULTIPLY_STRINGS_H_
#define MULTIPLY_STRINGS_H_

#include <string>

using std::string;

class Solution {

public:
    void addToResult(int value, int pos, string& result){
        int tmp = value;
        int carrier = 0;
        int i = pos;
        while(tmp != 0 || carrier != 0){
            int sum = result[i] - '0' + ( tmp % 10 ) + carrier;
            carrier = sum / 10;
            sum %= 10;
            result[i] = sum + '0';

            tmp /= 10;
            --i;
        }
    }

    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()){
            return string();
        }

        int digits = num1.size() + num2.size();
        int result_size = digits;
        string result(result_size, '0');

        for(int i1 = 0; i1 < num1.size(); ++i1){
            for(int i2 = 0; i2 < num2.size(); ++i2){
                int r1 = num1.size() - 1 - i1;
                int r2 = num2.size() - 1 - i2;
                int pos = result_size - 1 - (r1 + r2);
                int value1 = num1[i1] - '0';
                int value2 = num2[i2] - '0';
                int value = value1 * value2;
                addToResult(value, pos, result);
            }
        }
        int i = 0;
        while(result[i] == '0' && i < result.size() - 1){
          ++i;
        }
        result.erase(result.begin(), result.begin() + i);
        return result;
    }
};

#endif
