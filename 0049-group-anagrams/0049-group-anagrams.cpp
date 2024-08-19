class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create an unordered_map to store anagrams
        unordered_map<string, vector<string>> mp;
        // Create a vector to store the final result
        vector<vector<string>> ans;

        // Iterate over each string in the input vector
        for (int i = 0; i < strs.size(); i++) {
            // Sort the characters of the string to identify anagrams
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            // Add the original string to the corresponding anagram group in the map
            mp[temp].push_back(strs[i]);
        }

        // Iterate over the map to construct the final result
        for (auto it : mp) {
            // Add the vector of strings (anagram group) to the result
            ans.push_back(it.second);
        }
        
        // Return the final result
        return ans;
    }
};