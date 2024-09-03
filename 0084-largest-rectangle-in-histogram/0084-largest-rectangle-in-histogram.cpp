class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0; // Variable to store the maximum rectangle area
        stack<int> stk; // Stack to store indices of bars in the histogram
        int i; // Variable to iterate through the heights
        int n = heights.size(); // Total number of bars in the histogram

        // Iterate through each bar in the histogram
        for (i = 0; i < n; i++) {

            // If the current bar is smaller than the bar at the top of the stack
            // it means we have found a boundary where we need to calculate the area
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int curr = stk.top(); // Get the height of the bar at the top of the stack
                stk.pop(); // Pop the top bar as we are processing it
                
                // Calculate the previous smaller element (PSE)
                int pse = -1; // Default PSE is -1 (left boundary is before the first bar)
                if (!stk.empty()) 
                    pse = stk.top(); // Update PSE with the next element in the stack
                
                // Calculate the area of the rectangle with the height of the popped bar
                // The width is determined by the distance between the current index 'i' and 'pse'
                ans = max(ans, heights[curr] * (i - pse - 1));
            }

            // Push the current bar index into the stack
            stk.push(i);
        }

        // After processing all bars, some bars may still be in the stack
        // We need to calculate the area for these remaining bars
        while (!stk.empty()) {
            int curr = stk.top(); // Get the height of the bar at the top of the stack
            stk.pop(); // Pop the top bar as we are processing it
            
            // Calculate the previous smaller element (PSE)
            int pse = -1; // Default PSE is -1 (left boundary is before the first bar)
            if (!stk.empty()) 
                pse = stk.top(); // Update PSE with the next element in the stack
            
            // Calculate the area of the rectangle with the height of the popped bar
            // The width is determined by the distance between the last index 'n' and 'pse'
            ans = max(ans, heights[curr] * (i - pse - 1));
        }

        // Return the maximum rectangle area found
        return ans;
    }
};