class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            // Opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }

            // Closing brackets
            else {
                if (st.empty()) {
                    return false;
                }

                if (ch == ')' && st.top() != '(') {
                    return false;
                }

                if (ch == ']' && st.top() != '[') {
                    return false;
                }

                if (ch == '}' && st.top() != '{') {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};