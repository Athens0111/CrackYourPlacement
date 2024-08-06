//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int sameChar(string A, string B){
        // Initialize the count of same characters to 0
        int ans = 0;
    
        // Loop through each character of the strings A and B
        for(int i = 0; i < A.size(); i++) {
            // Check if the characters at the current index are the same
            // This also includes checking for case insensitivity by comparing lowercase and uppercase equivalents
            if(A[i] == B[i] || A[i] == (B[i] + 32) || A[i] == (B[i] - 32))
                ans++; // Increment the count if characters match
        }
    
        // Return the count of same characters
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.sameChar(A,B)<<endl;
    }
    return 0;
}
// } Driver Code Ends