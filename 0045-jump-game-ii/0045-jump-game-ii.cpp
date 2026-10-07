class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            // Current jump se hum maximum kaha tak ja sakte hain
            farthest = max(farthest, i + nums[i]);

            // Current jump ki range khatam ho gayi
            if(i == currentEnd) {

                jumps++;

                // Next jump ki maximum range
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};