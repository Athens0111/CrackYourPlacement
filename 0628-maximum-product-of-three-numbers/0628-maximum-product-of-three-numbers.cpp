class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Check whether the product of the smallest two numbers and the largest number
        // is greater than the product of the three largest numbers.
        if((nums[0]*nums[1]*nums[n-1]) > (nums[n-1]*nums[n-2]*nums[n-3]))
            // If true, return the product of the two smallest and the largest number
            // This accounts for cases where the array has two large negative numbers
            // and a positive number, which gives a large positive product.
            return nums[0]*nums[1]*nums[n-1];
        else
            // Otherwise, return the product of the three largest numbers
            return nums[n-1]*nums[n-2]*nums[n-3];
    }
};