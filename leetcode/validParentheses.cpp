#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        int n = s.length();
        std::stack<char> st;

        for (const char& ch : s) {
            if (!st.empty()) {
                char last = st.top();
                if (isPair(last, ch)) {
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.empty();
    }
private:
    bool isPair(char last, char ch) {
        return (last == '(' && ch == ')') ||
            (last == '[' && ch == ']') ||
            (last == '{' && ch == '}');
    }
};