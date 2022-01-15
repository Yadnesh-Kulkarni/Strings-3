//Time complexity : O(1)
//Space complexity : O(1)
class Solution {
public:
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen", "Nineteen"};
    vector<string> below_100 = {"" , "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        
        string result = "";
        int i = 0;
        while(num > 0)
        {
            if(num % 1000 != 0)
            {
                result = helper(num % 1000) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }
        result.erase(std::find_if(result.rbegin(), result.rend(), std::bind1st(std::not_equal_to<char>(), ' ')).base(), result.end());
        return result;
  }
    
    string helper(int num)
    {
        if(num == 0)
            return "";
        
        if(num < 20)
        {
            return below_20[num] + " ";
        }
        else if(num < 100)
        {
            return (below_100[num / 10] + " " + helper(num % 10));
        }
        else 
        {
            return (below_20[num / 100] + " Hundred " + helper(num % 100));
        }
    }
};