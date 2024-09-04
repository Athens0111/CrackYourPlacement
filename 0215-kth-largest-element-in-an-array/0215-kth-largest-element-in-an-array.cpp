class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a max-heap (priority queue) to store elements in decreasing order
        priority_queue<int> pq;

        // Push all elements from the array into the priority queue
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        // Pop the top element from the heap (which is the largest) k-1 times
        // This will leave the k-th largest element at the top of the heap
        while(k > 1) {
            pq.pop();  // Remove the current largest element
            k--;  // Decrease k to track the number of pops
        }

        // The top of the heap now contains the k-th largest element, so return it
        return pq.top();
    }
};