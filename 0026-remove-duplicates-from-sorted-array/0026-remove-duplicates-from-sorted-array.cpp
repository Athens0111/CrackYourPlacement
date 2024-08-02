class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        int k=1,t=nums[0];

        for(int i=0;i<nums.size();i++){
            if(i==0){
                temp.push_back(nums[i]);
            }
            else{
                if(nums[i]!=t){
                    t=nums[i];
                    temp.push_back(t);
                    k++;
                }
            }
        }
        nums = temp;
        return k;
    }
};