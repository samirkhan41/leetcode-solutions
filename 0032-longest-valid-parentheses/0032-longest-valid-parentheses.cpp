class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1);

        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push(i);
            }
            else {

                st.pop();

                if(st.empty()) {
                    // Unmatched ')' mil gaya
                    st.push(i);
                }
                else {
                    // Valid substring ki length
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};