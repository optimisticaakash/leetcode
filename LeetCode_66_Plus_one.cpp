//Approach 1 : using maths 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n-1;//start from LSB like usual math calculation

        while(i >= 0){//O(N)
            if(digits[i] < 9){
                digits[i]+= 1;
                return digits;
            }

            //else we did get 9
            digits[i] = 0;//9+1 = 10
            i--;
        }


        //agar loop se bhahr aagye mtlb sirf 9 hi mile to append 1 

        digits.insert(begin(digits),1); //O(N)

        return digits;
    }
};
//T.C : O(N) 
//S.C : O(1) 
