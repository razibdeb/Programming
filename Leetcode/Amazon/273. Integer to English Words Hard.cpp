/*
273. Integer to English Words
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1
*/
class Solution {
public:
    /*
    Runtime: 4 ms, faster than 65.39% of C++ online submissions for Integer to English Words.
Memory Usage: 6.4 MB, less than 58.14% of C++ online submissions for Integer to English Words.
    */
    string numberToWords(int num) {
        int billion = 1000000000;
        int million =    1000000;
        int thousand =      1000;
        
        int bDigit = num / billion;
        
        string result = "";
        if(bDigit > 0) {
            string bilStr = three(bDigit);
            if(bilStr != "")
                result = bilStr + " Billion";
        }

        
        int milDigit = num % billion;
        milDigit = milDigit / million;
        if(milDigit > 0) {
            string milStr = three(milDigit);
            if(milStr != "") {
                if(result != "") result += " ";
            
                result += milStr + " Million";
            }
        }
        
        
        int thousandDigit = num % million;
        thousandDigit = thousandDigit / thousand;
        
        if(thousandDigit != 0) {
            string thousandStr = three(thousandDigit);
            if(thousandStr != "") {
                if(result != "") result += " ";
                result += thousandStr + " Thousand";
            }
        }
        
        
        int threeDigit = num % thousand;
        if(threeDigit == 0 && result != "") {
            return result;
        }
        string threeStr = three(threeDigit);
        
        if(threeStr != "") {
            if(result != "") result += " ";
            result += threeStr;
        }
        
        return result;
    }
    
    
    
    //for 3 digit 0 to 999
    string three(int input) {
        string result = "";
        int threeDigit = input / 100;
        if(threeDigit != 0) {
            result += one(threeDigit) + " Hundred";
        }
        
        int mod = input % 100;
        if(mod == 0 && result != "" ) return result;
        string twoDigitStr = two(mod);
        if(twoDigitStr != "") {
            if(result != "") result += " "; 
            result += twoDigitStr;
        }
        
        return result;
    }
    
    
    //this will solve for two digit 
    //10 -> ten
    //11 -> eleven
    //19 -> nineteen
    
    //99 -> ninenty nine
    //accept from 1 to < 100
    string two(int input) {
        if(input >= 0 && input <= 9) return one(input);
        
        if(input == 10) {
            return "Ten";
        }
        //11 to 19
        switch(input) {
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        
        //from 20 to 99 have to generate
        int twoDigit = input / 10;
        string result ="";
        
        result += getTwo10(twoDigit);
        
        int mod = input % 10;
        if(mod == 0) {
            
        } else {
            result += " " + one(mod);
        }
        
        return result;
    }
    string getTwo10(int input) {
        switch(input) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety"; 
        }
        return "";
    }
    
    //this will return for one
    string one(int input) {
        if(input > 9) {
            //problem
            return "";
        }
        switch (input) {
            case 0: return "Zero";
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        return "";
    }
};

/*
100 hundred
1000            one thousand
1000 000        one million
1000 000 000    one billion
*/