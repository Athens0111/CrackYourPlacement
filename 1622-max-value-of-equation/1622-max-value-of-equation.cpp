class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();  // Get the number of points
        priority_queue<pair<int, int>> heap;  // Max heap to store pairs of (yi - xi, xi)
        int ans = INT_MIN;  // Initialize the maximum value of the equation to a very small value

        // Iterate over all points
        for (int i = 0; i < n; i++) {
            // Remove all points from the heap that violate the distance constraint |xi - xj| > k
            while (!heap.empty() && (points[i][0] - heap.top().second) > k)
                heap.pop();  // Remove invalid points from the heap
            
            // If the heap is not empty, calculate the value of the equation using the top element
            if (!heap.empty())
                ans = max(ans, (heap.top().first + points[i][0] + points[i][1]));  // Update the maximum value

            // Push the current point's (yi - xi) and xi into the priority queue
            heap.push({points[i][1] - points[i][0], points[i][0]});
        }

        // Return the maximum value of the equation found
        return ans;
    }
};