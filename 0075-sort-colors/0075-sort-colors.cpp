class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, mid = 0, h = nums.size() - 1; // Initialize pointers: l for low, mid for current, h for high

        while (mid <= h) { // Loop until mid pointer crosses the high pointer
            
            if (nums[mid] == 0) { // If the current element is 0
                // Swap the current element with the element at the low pointer
                int temp = nums[l];
                nums[l] = nums[mid];
                nums[mid] = temp;
                l++; // Move the low pointer to the right
                mid++; // Move the mid pointer to the right
            }
            
            else if (nums[mid] == 1) { // If the current element is 1
                mid++; // Simply move the mid pointer to the right
            }
            
            else { // If the current element is 2
                // Swap the current element with the element at the high pointer
                int temp = nums[h];
                nums[h] = nums[mid];
                nums[mid] = temp;
                h--; // Move the high pointer to the left
                // Do not move the mid pointer here as the swapped element needs to be re-evaluated
            }
        }
    }

};