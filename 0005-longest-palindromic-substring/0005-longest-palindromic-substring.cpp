class Solution {
public:

    // Palindrome ko center se expand karega
    int expandAroundCenter(string &s, int left, int right) {
        
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // Actual palindrome ki length
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        
        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            int len1 = expandAroundCenter(s, i, i);

            // Even length palindrome
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);

            if(len > maxLen) {
                maxLen = len;

                // Starting index calculate
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};