/*
307. Range Sum Query - Mutable Medium

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.
*/
/*
Runtime: 765 ms, faster than 36.14% of C++ online submissions for Range Sum Query - Mutable.
Memory Usage: 175.4 MB, less than 8.01% of C++ online submissions for Range Sum Query - Mutable.
*/
class NumArray {
public:
    vector<int> tree;
    int n;
    vector<int> nums;
    
    NumArray(vector<int>& ns) {
        n = ns.size();
        tree = vector<int>(n*2+n, 0);
        
        nums = vector<int>(ns.begin(), ns.end());
        buildTree(0, n - 1, 0);
    }
    //(2N)
    int buildTree(int left, int right, int index) {
        if(left == right) {
            tree[index] = nums[left];
            return tree[index];
        }
        int mid = (left + right) / 2;
        int l = buildTree(left, mid, index * 2 + 1);
        int r = buildTree(mid + 1, right, index * 2 + 2);
        
        //cout<<"Tree "<<index<<" "<<l + r<<endl;
        tree[index] = l + r;
        
        return tree[index];
    }
    //LogN
    int query(int left, int right, int index, int rangeL, int rangeR) {
        if(left >= rangeL && right <= rangeR) {
            return tree[index];
        }
        else if(rangeR < left || rangeL > right) {
            return 0;
        }
        else {
            int mid = (left + right) / 2;
            int l = query(left, mid, index * 2 + 1, rangeL, rangeR);
            int r = query(mid + 1, right, index * 2 + 2, rangeL, rangeR);
            
            return l + r;
        }
    }
    
    void updateTree(int treeIndex, int diff, int left, int right, int idx) {
        if(!(idx >= left && idx <= right)) return;
        if(left == right) {
            tree[treeIndex] += diff;
            return;
        }
        //cout<<"update Tree "<<treeIndex<<" l: "<<left<<" r: "<<right<<endl;
        int mid = (left + right) / 2;
        tree[treeIndex] += diff;
        updateTree(treeIndex * 2 + 1, diff, left, mid, idx);
        updateTree(treeIndex * 2 + 2, diff, mid+1, right, idx);
    }
    
    void update(int index, int val) {
        //cout<<"upadte"<<endl;
        int oldValue = nums[index];
        int diff = val - oldValue;
        nums[index] = val;
        updateTree(0, diff, 0, n - 1, index);
        //cout<<"update done"<<endl;
    }
    
    int sumRange(int left, int right) {
        return query(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */