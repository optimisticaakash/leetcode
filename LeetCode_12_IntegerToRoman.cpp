//Approach1 : 
class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones = {"","I","II","III","IV","V","VI","VII","VIII","IX","X"};
        vector<string> tens = {"" ,"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> hundreds = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> thousands = {"","M","MM","MMM"};



        string Roman = thousands[num/1000]+hundreds[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
        return Roman;
    }
};
//T.C : O(1)
//S.C : O(1)

//Approach2:
class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000 , 900, 500, 400, 100, 90 , 50, 40, 10, 9, 5, 4, 1};
        vector<string> Roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V" , "IV" ,"I"};


        string result = "";
        for(int i = 0; i < 13; i++){

            if(num == 0) break;
            int times = num/nums[i];
            while(times--){
                result += Roman[i];
            }
            num = num%nums[i];
        }
        return result;
    }
};
//T.C:O(1)
//S.C :O(1)
