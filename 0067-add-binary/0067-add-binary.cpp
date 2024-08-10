class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();   // Get the length of the first binary string
        int m = b.size();   // Get the length of the second binary string
        int i = n-1, j = m-1; // Initialize pointers to the end of each string
        int carry = 0;      // Initialize carry to 0
        string ans = "";    // Initialize the result string

        // Process both strings from the end to the beginning
        while(i >= 0 && j >= 0){
            // Calculate the sum of the current digits plus the carry
            int sum = ((a[i]-'0') + (b[j]-'0') + carry) % 2;
            carry = ((a[i]-'0') + (b[j]-'0') + carry) / 2;  // Update carry

            // If sum is 1, add '1' to the result string; else, add '0'
            if(sum == 1)
                ans = '1' + ans;
            else
                ans = '0' + ans;
            
            i--;  // Move to the next digit in the first string
            j--;  // Move to the next digit in the second string
        }

        // Process remaining digits in the first string (if any)
        while(i >= 0){
            int sum = ((a[i]-'0') + carry) % 2;  // Add the carry to the current digit
            carry = ((a[i]-'0') + carry) / 2;    // Update carry
            if(sum == 1)
                ans = '1' + ans;
            else
                ans = '0' + ans;
            i--;  // Move to the next digit
        }   

        // Process remaining digits in the second string (if any)
        while(j >= 0){
            int sum = ((b[j]-'0') + carry) % 2;  // Add the carry to the current digit
            carry = ((b[j]-'0') + carry) / 2;    // Update carry
            if(sum == 1)
                ans = '1' + ans;
            else
                ans = '0' + ans;
            j--;  // Move to the next digit          
        }

        // If there's still a carry left, add '1' to the beginning of the result string
        if(carry == 1)
            ans = '1' + ans;

        return ans;  // Return the final binary sum
    }

};