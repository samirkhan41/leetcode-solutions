class Solution {
public:
    string multiply(string num1, string num2) {

        // Agar koi number 0 hai
        if(num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        // Maximum digits = n + m
        vector<int> result(n + m, 0);

        // Har digit ko multiply karo
        for(int i = n - 1; i >= 0; i--) {

            for(int j = m - 1; j >= 0; j--) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + result[pos2];

                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        // Leading zeros remove karo
        string ans = "";

        int i = 0;

        while(i < result.size() && result[i] == 0)
            i++;

        while(i < result.size()) {
            ans += char(result[i] + '0');
            i++;
        }

        return ans;
    }
};