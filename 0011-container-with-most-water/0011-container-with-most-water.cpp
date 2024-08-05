class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1; // Initialize two pointers: i at the beginning, j at the end
        int ans = 0; // Initialize the variable to store the maximum area

        while (i < j) { // Loop until the two pointers meet
            // Determine the height of the shorter line
            int x = height[i] < height[j] ? height[i] : height[j];
            
            // Calculate the area with the current pair of lines
            int temp = (j - i) * x;
            
            // Update the maximum area if the current area is larger
            if (temp > ans)
                ans = temp;
            
            // Move the pointer pointing to the shorter line
            if (height[i] < height[j])
                i++; // Move the left pointer to the right
            else
                j--; // Move the right pointer to the left
        }

        return ans; // Return the maximum area found
    }

};