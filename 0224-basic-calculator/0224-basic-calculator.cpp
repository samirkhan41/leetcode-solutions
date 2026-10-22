
class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long result = 0;
        long long num = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (ch == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
                num = 0;
            }
            else if (ch == ')') {
                result += sign * num;
                num = 0;

                result *= st.top();
                st.pop();

                result += st.top();
                st.pop();
            }
        }

        result += sign * num;
        return static_cast<int>(result);
    }
};
