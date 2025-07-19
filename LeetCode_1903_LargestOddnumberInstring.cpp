//Approach 1 
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        for(int i = n-1; i >= 0; i--){
            if((num[i]-'0')%2 == 1) return num.substr(0,i+1);
        }
        return "";
    }
};
//O(n) 

//Approach2: 
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

    
        while(!num.empty()){
            if((num.back()-'0')%2 == 0){
                num.pop_back();
            }else{
                break;
            }
        }
        return num;
    }
};
//T.C : O(n)
//S.C : O(1) 
