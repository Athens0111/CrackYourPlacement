class Solution {
public:
// Function to count reverse pairs and merge two sorted halves of the array
    int merge(vector<int> &nums, int low, int mid, int high) {
        int j = mid + 1;
        int count = 0;

        // Counting reverse pairs
        // For each element in the left half, find how many elements in the right half satisfy the condition nums[i] > 2 * nums[j]
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            // The number of valid reverse pairs for the current nums[i] is the number of elements from mid+1 to j-1
            count += (j - (mid + 1));
        }

        // Merging the two sorted halves
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge elements in sorted order
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        // Copy remaining elements from the left half, if any
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        // Copy remaining elements from the right half, if any
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        // Copy the sorted subarray back into the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        // Return the count of reverse pairs found in this merge step
        return count;
    }

    // Function to recursively split the array and count reverse pairs
    int result(vector<int> &nums, int i, int j) {
        // Base case: if the array has one or zero elements, there are no reverse pairs
        if (i >= j) {
            return 0;
        }

        // Calculate the middle index to split the array into two halves
        int mid = (i + j) / 2;

        // Recursively count reverse pairs in the left and right halves
        int ans = result(nums, i, mid);
        ans += result(nums, mid + 1, j);

        // Count reverse pairs and merge the two halves
        ans += merge(nums, i, mid, j);

        // Return the total count of reverse pairs
        return ans;
    }

    // Function to count the total number of reverse pairs in the array
    int reversePairs(vector<int>& nums) {
        // Start the recursive process to count reverse pairs
        int ans = result(nums, 0, nums.size() - 1);

        // Return the final count
        return ans;
    }
};