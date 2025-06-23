#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string ans = "";

        if (num >= 1000) {
            int x = num / 1000;
            for (int i = 0; i < x; ++i) { ans += 'M'; }
            num -= 1000*x;
        }      

        if (num >= 100) {
            int x = num / 100;
            if (x == 9) {
                ans += "CM";
            } else if (x >= 5) {
                ans += 'D';
                for (int i = 0; i < x - 5; ++i) {
                    ans += 'C';
                }
            } else if (x == 4) {
                ans += "CD";
            } else {
                for (int i = 0; i < x; ++i) {
                    ans += 'C';
                }
            } 
            num -= x*100;
        }
        
        if (num >= 10) {
            int x = num / 10;
            if (x == 9) {
                ans += "XC";
            } else if (x >= 5) {
                ans += 'L';
                for (int i = 0; i < x - 5; ++i) {
                    ans += 'X';
                }
            } else if (x == 4) {
                ans += "XL";
            } else {
                for (int i = 0; i < x; ++i) {
                    ans += 'X';
                }
            }
            num -= x*10;
        }

        if (num == 9) {
            ans += "IX";
        } else if (num >= 5) {
            ans += 'V';
            for (int i = 0; i < num - 5; ++i) {
                ans += 'I';
            }
        } else if (num == 4) {
            ans += "IV";
        } else {
            for (int i = 0; i < num; ++i) {
                ans += 'I';
            }
        }

        return ans;
    }
};