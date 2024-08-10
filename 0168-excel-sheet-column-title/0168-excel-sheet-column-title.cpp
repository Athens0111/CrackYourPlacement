class Solution {
public:
    // Function to swap two characters by reference
    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }

    // Function to convert a column number (like Excel columns) into a string title
    // Example: 1 -> A, 28 -> AB, 701 -> ZY
    string convertToTitle(int columnNumber) {
        
        // Initialize an empty string to store the result
        string str = "";

        // Loop until the column number becomes 0
        while (columnNumber) {
            // Decrement the column number by 1 to handle the zero-based index (0 -> A, 25 -> Z)
            columnNumber -= 1;

            // Calculate the current character to append (corresponding to A-Z)
            int k = columnNumber % 26;

            // Append the character to the result string
            str += 'A' + k;

            // Move to the next digit in the column number (similar to base-26 division)
            columnNumber /= 26;
        }

        // Reverse the result string to get the correct column title
        int n = str.size();
        for (int i = 0; i < n / 2; ++i) {
            swap(str[i], str[n - 1 - i]);
        }

        // Return the final column title
        return str;
    }

};