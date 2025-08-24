//Approach1 : 
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int cnt = 0;
        while(ans >0){
            if(ans%2==1)cnt++;
            ans/=2;
        }
        return cnt;
    }
};
//T.C : O(logans) = O(31)
//T.C : O(1) 

//Approach2: 
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int cnt = 0;
        while(ans >0){
            ans = ans&ans-1;
            cnt++;
        }
        return cnt;
    }
};
//T.c : O(31)
//S.C : O(1)
