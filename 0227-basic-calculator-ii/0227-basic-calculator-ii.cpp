class Solution {
public:
    int value(char c) {
        // Assign precedence value to operators: 
        // 1 for '+' and '-', 2 for '*' and '/'
        if (c == '+' || c == '-')
            return 1;
        return 2; // for '*' and '/'
    }

    int calculate(string s) {
        // Stack to store numbers
        stack<int> num;
        // Stack to store operators
        stack<char> operators;
        int n = s.size();
        // String to store the postfix expression
        string postfix = "";

        // Step 1: Convert infix expression to postfix
        for (int i = 0; i < n; i++) {
            // If the character is a digit, parse the full number
            if (isdigit(s[i])) {
                string number = "";
                while (i < n && isdigit(s[i])) {
                    number += s[i];
                    i++;
                }
                i--; // adjust index because of the outer loop's increment
                postfix += number + ' '; // add a space to separate numbers
            } 
            // If the character is an operator
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int temp = value(s[i]);

                // Pop operators from the stack to postfix expression until a lower precedence operator is found
                while (!operators.empty() && value(operators.top()) >= temp) {
                    postfix += operators.top();
                    postfix += ' '; // separate operators
                    operators.pop();
                }
                // Push the current operator onto the stack
                operators.push(s[i]);
            }
        }

        // Pop any remaining operators in the stack to the postfix expression
        while (!operators.empty()) {
            postfix += operators.top();
            postfix += ' ';
            operators.pop();
        }

        // Step 2: Evaluate postfix expression
        stringstream ss(postfix); // for tokenizing the postfix expression
        string token;

        while (ss >> token) {
            // If the token is a number, push it to the num stack
            if (isdigit(token[0])) {
                num.push(stoi(token)); // convert string to integer and push
            } 
            // If the token is an operator, pop two numbers from the stack and apply the operator
            else {
                int second = num.top(); // top is the second operand
                num.pop();
                int first = num.top(); // next top is the first operand
                num.pop();
                int ans;

                // Perform the operation
                if (token == "+")
                    ans = first + second;
                else if (token == "-")
                    ans = first - second;
                else if (token == "/")
                    ans = first / second;
                else if (token == "*")
                    ans = first * second;

                // Push the result back onto the num stack
                num.push(ans);
            }
        }

        // The final result will be the only number left in the stack
        return num.top();
    }
};