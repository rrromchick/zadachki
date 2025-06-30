#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        long long int sum = 0;
        int sign = 1;
        std::stack<std::pair<int, int>> st;

        for (int i = 0; i < s.length(); ++i) {
            if (std::isdigit(s[i])) {
                long long int num = 0;
                while (i < s.length() && std::isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                sum += num * sign;
                sign = 1;
            } else if (s[i] == '(') {
                st.push(std::make_pair(sum, sign));
                sum = 0;
                sign = 1;
            } else if (s[i] == ')') {
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            } else if (s[i] == '-') {
                sign = -1 * sign;
            }
        }

        return sum;
    }
};