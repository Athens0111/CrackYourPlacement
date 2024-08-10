//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // Initialize a variable to store the product of all elements
        long long int p = 1;
        vector<long long int> ans(nums.size());
        // Initialize a flag to track the number of zeros in the array
        int zero_flag = 0;
    
        // Calculate the product of all elements and count the number of zeros
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_flag++;
                // If more than one zero is encountered, break the loop
                if (zero_flag > 1)
                    break;
            } else {
                // Update the product if the element is not zero
                p *= nums[i];
            }
        }
    
        // Update the array based on the calculated product and zero_flag
        for (int i = 0; i < nums.size(); i++) {
            if (zero_flag == 1) {
                // If there is exactly one zero, set the element to the product if it's zero, else set it to zero
                if (nums[i] == 0)
                    ans[i] = p;
                else
                    ans[i] = 0;
            } else if (zero_flag >= 2) {
                // If there are two or more zeros, set all elements to zero
                ans[i] = 0;
            } else {
                // If there are no zeros, update each element to the product divided by the original element
                ans[i] = p / nums[i];
            }
        }
    
        // Return the modified array
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends