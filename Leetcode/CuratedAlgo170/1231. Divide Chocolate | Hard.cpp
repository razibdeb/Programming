/*
You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 pieces using k cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

 

Example 1:

Input: sweetness = [1,2,3,4,5,6,7,8,9], k = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
Example 2:

Input: sweetness = [5,6,7,8,9,1,2,3,4], k = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.
Example 3:

Input: sweetness = [1,2,2,1,2,2,1,2,2], k = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
 

Constraints:

0 <= k < sweetness.length <= 104
1 <= sweetness[i] <= 105

Google|3

Amazon|2

Facebook|2

*/
class Solution {
public:

    /*
    approach:
    
    think bruteforce
    let's say I can have X chocolate -> value of x can be from minimum of chocolate to total/k+1 
    
    so for all values from MIN to MAX we can try to check if we can devide all chocolate list to K+1 chunk
    
    how we can we do that?
    for VALUE from MIN to MAX
        for all chocolates from begining to end
        make a chunk untill chunks value is equal or bigger then VALUE-> increase chunk count 
        if we can make chunk count exactly equal K + 1 then this is a possible result-> store it    
    */
    
    /*
    Runtime: 34 ms, faster than 43.69% of C++ online submissions for Divide Chocolate.
Memory Usage: 15.4 MB, less than 39.32% of C++ online submissions for Divide Chocolate.
    
    */
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int MIN = INT_MAX, MAX;
        int total = 0;
        for(int i = 0; i < sweetness.size(); i++) {
            total += sweetness[i];
            MIN = min(sweetness[i], MIN);
        }
        MAX = total / (k+1);
        
        int result = INT_MIN;
        
        while(MIN <= MAX) {
            
            int mid = MIN + (MAX - MIN) / 2;
            //cout<<"checking for "<<mid<<endl;
            if(isChunkPossible(sweetness, mid, k)) {
                result = max(result, mid);
                MIN = mid + 1;
                //cout<<"\t"<<"possible"<<endl;
            } else {
                MAX = mid - 1;
            }
        }
        return result;
    }
    
    bool isChunkPossible(vector<int> & sweet, int chunkSize, int k) {
        int currentChunkSize = 0;
        int total = 0;
        for(int i = 0; i < sweet.size(); i++) {
            total += sweet[i];
            
            if(total >= chunkSize ) {
                total = 0;
                currentChunkSize++;
                if(currentChunkSize >= k + 1) return true;
            }
        }
        
        return currentChunkSize < k + 1 ? false : true;
    }
};