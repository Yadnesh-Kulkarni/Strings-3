//Time complexity : O(n)
//Space complexity : O(1)

class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        
        int calc = 0;
        long int curr = 0;
        int tail = 0;
        char lastSign = '+';
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            char c = s[i];
            if(isdigit(c))
            {
                curr = curr * 10 + c - '0';
            }
            if((!isdigit(c) && c != ' ') || i == s.size() - 1)
            {
                if(lastSign == '+')
                {
                    calc = calc + curr;
                    tail = curr;
                }
                else if(lastSign == '-')
                {
                    calc = calc - curr;
                    tail = -curr;
                }
                else if(lastSign == '*')
                {
                    calc = calc - tail + tail * curr;
                    tail = tail * curr;
                }
                else
                {
                    calc = calc - tail + tail / curr;
                    tail = tail / curr;
                }
                lastSign = c;
                curr = 0;
            }
        }
        return calc;
    }
};