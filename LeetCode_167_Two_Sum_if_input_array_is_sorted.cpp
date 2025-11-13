//Bruteforce : using nested loops
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){

                if(numbers[i] + numbers[j] == target){
                    return {i+1,j+1};
                }
            }
        }

        return {-1,-1};
    }
};
//T.C : O(N^2)
//S.C : O(1) 

//using two pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i = 0;
        int j = n-1;

        while(i < j){
            int sum = numbers[i]+numbers[j];

            if(sum > target){
                j--;
            }else if(sum < target){
                i++;
            }else{
                return {i+1 , j+1};
            }
        }

        return {-1,-1};
    }
};

//T.C :  O(1)
