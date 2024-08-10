//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        // Sort arr1 in ascending order to get the smallest elements first
        sort(arr1.begin(), arr1.end());
    
        // Sort arr2 in descending order to get the largest elements first
        sort(arr2.begin(), arr2.end(), greater<int>());
        
        // Iterate through both arrays to check if each pair's sum is at least k
        for(int i = 0; i < arr1.size(); i++){
            // Check if the sum of the smallest element in arr1 and the largest element in arr2
            // is less than k. If so, it's not possible to satisfy the condition.
            if(arr1[i] + arr2[i] < k)
                return false; // If any pair doesn't satisfy the condition, return false
        }
        
        // If all pairs satisfy the condition, return true
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr1, arr2;
        int num;
        while (ss >> num) {
            arr1.push_back(num);
        }
        getline(cin, s);
        ss.clear();
        ss.str(s);
        while (ss >> num) {
            arr2.push_back(num);
        }
        Solution ob;
        bool ans = ob.isPossible(k, arr1, arr2);
        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
// } Driver Code Ends