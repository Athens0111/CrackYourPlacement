class Solution {
public:
    bool isValid(string s) {    
    // Initialize a stack to keep track of opening parentheses
    stack<char> a;

    // Initialize index variable
    int i = 0;

    // Loop through each character in the string until the end
    while (s[i] != '\0') {
        // If the character is an opening parenthesis, push it onto the stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            a.push(s[i++]); // Move to the next character
            continue;
        }

        // If the character is a closing parenthesis
        if (!a.empty()) {
            // Check if the closing parenthesis matches the corresponding opening parenthesis
            if (s[i] == ')' && a.top() == '(')
                a.pop();
            else if (s[i] == '}' && a.top() == '{')
                a.pop();
            else if (s[i] == ']' && a.top() == '[')
                a.pop();
            else
                return false; // Mismatched parentheses, return false
        } else {
            return false; // Closing parenthesis with no corresponding opening parenthesis, return false
        }

        i++; // Move to the next character
    }

    // Check if there are any remaining opening parentheses in the stack
    if (a.empty())
        return true; // Stack is empty, and parentheses are balanced
    else
        return false; // Stack is not empty, and parentheses are not balanced

    }
};