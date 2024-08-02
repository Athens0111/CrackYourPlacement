class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int c = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if(c == 0)
                ans = nums[i];
            
            if(nums[i] == ans) 
                c++;
            else 
                c--;
        }

        return ans;
    }
};