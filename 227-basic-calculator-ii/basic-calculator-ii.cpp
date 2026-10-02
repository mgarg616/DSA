class Solution {
public:
    int calculate(string s) {
        long long result = 0;   // sum of finished terms
        long long last = 0;     // current term, still open to * and /
        long long num = 0;
        char op = '+';          // operator preceding num

        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // Process when we hit an operator or the end of the string
            if ((!isdigit(c) && c != ' ') || i == (int)s.size() - 1) {
                switch (op) {
                    case '+':
                        result += last;
                        last = num;
                        break;
                    case '-':
                        result += last;
                        last = -num;
                        break;
                    case '*':
                        last *= num;
                        break;
                    case '/':
                        last /= num;  // C++ truncates toward zero
                        break;
                }
                op = c;
                num = 0;
            }
        }

        return (int)(result + last);
    }
};