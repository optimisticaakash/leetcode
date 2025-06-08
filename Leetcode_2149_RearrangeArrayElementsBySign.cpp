//Approach1 : Bruteforce
//Code : 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < n; i++){
        if(nums[i]>0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
    }
    
    for(int i = 0; i < n/2;i++){
        nums[2*i] = pos[i];
        nums[2*i+1] = neg[i];
    }
    return nums;
    }
};
//T.C: O(2n)
//S.C : O(n)

//Alternative Code :
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos;
    
    vector<int> neg;
    

    for(int i = 0; i < n; i++){
        if(nums[i]>0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
    }
    int a = pos.size();
    int b = neg.size();

    int i = 0;
    int j = 0;
    vector<int> result;
    while(i < a || j < b){
        if(i < a){
            result.push_back(pos[i]);
            i++;
        }
        if(j < b){
            result.push_back(neg[j]);
            j++;
        }
    }

    return result;
    }
};
//T.C = O(2n)
//S.C : O(2n)

//Approach 2 : optimal in single pass

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        int posIndex = 0 , negIndex = 1;

        for(int i = 0; i< n; i++){
            if(nums[i] > 0){
                result[posIndex] = nums[i];
                posIndex += 2;
            }else{
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return result;

    }
};
//T.C = O(n)
//S.C = O(n) 

//Varient 2 : pos != neg 
//1. Place all the elements alternately, starting with a positive no, and put the remaining elements in the last

//code
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> pos , neg;
        // seperating pos and neg element 
        
        for(int i = 0; i<n; i++){
            if(arr[i] >= 0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        //now filling them back into the array
        //if positive more
        if(pos.size() > neg.size()){
            
            for(int i = 0; i < neg.size(); i++){
                arr[2*i] = pos[i];
                arr[2*i+1]= neg[i];
            }
            //putting element which remaining in positive
            int index = 2*(neg.size());
            for(int i = neg.size(); i < pos.size(); i++){
                arr[index] = pos[i];
                index++;
            }
        }else{
            //if negative more 
            for(int i = 0; i < pos.size(); i++){
                arr[2*i] = pos[i];
                arr[2*i+1]= neg[i];
            }
            //putting element which remaining in positive
            int index = 2*(pos.size());
            for(int i = pos.size(); i < neg.size(); i++){
                arr[index] = neg[i];
                index++;
            }
        }
    }
};

//T.C = O(2n)
//S.C = O(n) 



