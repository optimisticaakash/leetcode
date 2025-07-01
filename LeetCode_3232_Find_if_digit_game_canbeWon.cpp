//approach 1 : bruteforce 
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int singlesum = 0;
        int doublesum = 0;
        for(int i : nums){
            
            if(i > 0 && i <10) singlesum += i;
            else if(i >= 10 && i <100 ) doublesum += i;
        }
        return singlesum != doublesum;
    }
};
//T.C : O(n) 
