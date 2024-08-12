class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string ans;
        int n = path.size();
        
        for (int i = 0; i < n;) {
            // Skip multiple slashes
            while (i < n && path[i] == '/') i++;
            
            // Extract the next part between slashes
            int s = i;
            while (i < n && path[i] != '/') i++;
            string part = path.substr(s, i - s);
            
            if (part == "..") {
                if (!stack.empty()) stack.pop_back();  // Go back one directory
            } else if (part != "." && !part.empty()) {
                stack.push_back(part);  // Add valid directory or file to the path
            }
        }
        
        // Build the simplified path
        for (string dir : stack) {
            ans += "/" + dir;
        }
        
        // Edge case: If the simplified path is empty, it should be "/"
        return ans.empty() ? "/" : ans;
    }
};