class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Create a new vector to store the merged result with size m + n
        vector<int> ans(m + n);
        
        int i = 0, j = 0, k = 0;

        // Merge the two arrays while there are elements in both
        while (i < m && j < n) {
            // Compare elements from nums1 and nums2
            if (nums1[i] < nums2[j]) {
                // If nums1's element is smaller, add it to the result
                ans[k++] = nums1[i++];
            } else {
                // Otherwise, add nums2's element to the result
                ans[k++] = nums2[j++];
            }
        }

        // Add remaining elements from nums2 if any
        while (j < n) {
            ans[k++] = nums2[j++];
        }

        // Add remaining elements from nums1 if any
        while (i < m) {
            ans[k++] = nums1[i++];
        }

        // Copy the merged result back to nums1
        nums1 = ans;
    }
};