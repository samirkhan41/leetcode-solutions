class Solution {
public:
    int strStr(string haystack, string needle) {

        for(int i = 0; i < haystack.length(); i++) {

            int j = 0;

            while(j < needle.length() &&
                  i + j < haystack.length() &&
                  haystack[i + j] == needle[j]) {
                j++;
            }

            if(j == needle.length()) {
                return i;
            }
        }

        return -1;
    }
};