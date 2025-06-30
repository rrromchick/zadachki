#include <stack>
#include <vector>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;

        for (const auto& c : tokens) {
            if (c == "+") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first + second);
            } else if (c == "-") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first - second);
            } else if (c == "*") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first * second);
            } else if (c == "/") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first / second);
            } else {
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};