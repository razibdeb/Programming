/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

You are not allowed to solve the problem using any serialize methods (such as eval).

 

Example 1:

Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
Example 2:

Input: dummy_input = [""]
Output: [""]
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] contains any possible characters out of 256 valid ASCII characters.
 

Follow up: Could you write a generalized algorithm to work on any possible set of characters?

Facebook 
LinkedIn
*/

class Codec {
public:
    /*
    Runtime: 74 ms, faster than 34.81% of C++ online submissions for Encode and Decode Strings.
Memory Usage: 28.2 MB, less than 22.78% of C++ online submissions for Encode and Decode Strings.
    */
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
       string result = "";
        
        for(int i = 0; i < strs.size(); i++) {
            int len = strs[i].size();
            string lenStr = getStringFromLen(len);
            result += lenStr + strs[i];
        }
        //cout<<"Encoding: "<<result<<endl;
        return result;
    }
    
    string getStringFromLen(int len) {
        string result = to_string(len);
        if(result.size() == 4) return result;
        int zeroSize = 4 - result.size();
        string zeros = "";
        for(int i = 0; i < zeroSize; i++) {
            zeros += "0";
        }
        return zeros + result;
    }
    
    int getIntLenFromString(string &str, int offset) {
        int result = 0;
        int mul = 1;
        for(int i = offset + 3; i >= offset; i--) {
            result += (str[i] - '0') * mul; 
            mul = mul * 10;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        
        for(int i = 0; i < s.size();) {
            int len = getIntLenFromString(s,i);
            
            string str = "";
            for(int l = i + 4; l < i + 4 + len; l++)
                str += s[l];
            
            result.push_back(str);
            i = i + 4 + len;  
        }
        
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));