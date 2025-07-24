//Approach1:
class Solution {
public:
    int Number(int num){
        if(num == 'I') return 1;
        else if(num == 'V') return 5;
        else if(num == 'X') return 10;
        else if(num == 'L') return 50;
        else if(num == 'C') return 100;
        else if(num == 'D') return 500;
        else if(num == 'M') return 1000;

        return -1;
    }
    int romanToInt(string s) {
        int n = s.size();
        int i = 0; //index

        int sum = 0;
        while(i < n-1){
            if(Number(s[i])< Number(s[i+1])){
                sum -= Number(s[i]);
            }else{
                sum += Number(s[i]);
            }
            i++;
        }
        sum += Number(s[i]); //last wale ke aage to koi hai nhi to woh humesha add hi hoga

        return sum;
    }
};
//T.C : O(1)
//S.C : O(1)

//Approach2:
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>RomanMap = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        
        int n = s.size();
        int sum = 0;
        int i = 0; 
        while(i < n-1){
            if(RomanMap[s[i]] < RomanMap[s[i+1]]){
                sum -= RomanMap[s[i]];
            }else{
                sum += RomanMap[s[i]];
            }
            i++;
        }
        sum+= RomanMap[s[i]];


        return sum;
    }
};
//T.C :O(1)
//S.C : O(1)
