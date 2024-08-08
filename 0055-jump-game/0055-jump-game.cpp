class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reach = nums[0];
        int capacity = 0;
        for(int i=0;i<n;i++){
            max_reach = max(max_reach, capacity);

            if(max_reach == n-1)
                return true;

            if(i < max_reach && i<n-1)
                capacity = nums[i+1] + i+1;  
            else if(i >= max_reach && i != n-1){
                return false;
            }

            cout<<i<<":"<<max_reach<<":"<<capacity<<"  ";
        }

        return true;
    }
};