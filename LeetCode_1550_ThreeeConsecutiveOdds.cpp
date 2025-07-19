//Approach1 : bruteforce
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();

        for(int i = 1; i < n-1; i++){
            if(arr[i-1]%2==1 && arr[i]%2 == 1 && arr[i+1]%2 == 1) return true;
        }
        return false;
    }
};

//T.C : O(n)
///S.C: O(1)

//Approach2: 
class Solution {
public:

    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(int num:arr){
            if(num%2 == 1){
                cnt++;
                if(cnt == 3) return true;
            }else{
                cnt = 0;
            }
        }
        return false;
    }
};
//T.C : O(n)
//S.C : O(1)
