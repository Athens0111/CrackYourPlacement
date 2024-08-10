//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // Sort the array to facilitate the two-pointer approach
        sort(arr.begin(), arr.end());
    
        // Initialize two pointers
        int i = 0; // Start pointer
        int j = 1; // End pointer, initially set to the next element
        
        while (j < n) {
            // Calculate the difference between the two pointers
            int dif = arr[j] - arr[i];
            
            if (dif == x) {
                // If the difference matches x, return 1
                return 1;
            } else if (dif < x) {
                // If the difference is less than x, move the end pointer forward
                j++;
            } else {
                // If the difference is greater than x, move the start pointer forward
                i++;
                // Ensure that the start pointer does not catch up with the end pointer
                if (i == j) {
                    j++;
                }
            }
        }
    
        // Return -1 if no such pair is found
        return -1;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends