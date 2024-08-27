class Solution {
public:
    string intToRoman(int num) {
        // Predefined Roman numeral mappings for each significant value
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string ans = "";

        // Loop through the Roman numeral mappings
        for (auto &pair : romanMap) {
            while (num >= pair.first) {
                ans += pair.second;  // Add the corresponding Roman numeral
                num -= pair.first;   // Reduce the number
            }
        }

        return ans;
    }
};