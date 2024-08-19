//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> ans;
            int n = text.size();
            int m = pattern.size();

            
            for(int i=0;i<n; i++){
                int j=0;
                if(text[i] != pattern[j])
                    continue;
                
                int start = i;

                while(j<m && start<n && text[start] == pattern[j]){
                    start++;
                    j++;
                }
                start--;
                
                if(start-i+1 == m)
                    ans.push_back(i+1);
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends