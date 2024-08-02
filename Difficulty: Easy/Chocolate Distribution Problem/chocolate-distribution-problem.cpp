//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        // Sort the array to facilitate finding subarrays with the smallest difference
        sort(a.begin(), a.end());
        
        // Initialize two pointers i and j to find subarrays of size m
        long long i = 0, j = m - 1;
        // Initialize ans with first possible value
        long long ans = a[j] - a[i];
        
        // Loop through the array to find the minimum difference
        while (j < n) {
            // Update ans if the current difference is smaller
            if (a[j] - a[i] < ans)
                ans = a[j] - a[i];
            // Move the window to the next position
            i++;
            j++;
        }
        
        // Return the minimum difference found
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends