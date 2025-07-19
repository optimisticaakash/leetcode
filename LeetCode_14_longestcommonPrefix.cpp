//Approach1 : using loops 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";

        int minlength = strs[0].size();
        for(int i = 0; i < n-1; i++){
            string first = strs[i];
            string sec = strs[i+1];

            int mini = min(strs[i].size() , strs[i+1].size());
            int j = 0;
            for(; j < mini; j++){
                if(strs[i][j] != strs[i+1][j]) break;
            }
            minlength= min(minlength , j);
        }
        return strs[0].substr(0,minlength);
    }
};
//n = no of string
//m = length of shortes string
//T.C = O(m*n)
//S.C : O(m) longest common prefix 

//Approach2 : using sorting
class Solution {
public:
    //using sorting
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin() , strs.end());

        string first = strs[0];
        string last = strs[n-1];

        int mini = min(strs[0].size() , strs[n-1].size());
        int j = 0;
        while(j < mini && strs[0][j] == strs[n-1][j] ){
            j++;
        }

        return strs[0].substr(0 , j);
    }
};
//T.C : O(m*n*logn)
//n = no of string
//m = avg length of string
//l = length of maxi common string
//S.C : O(l)

//Approach3 : binary search ;

class Solution {
public:

    bool tocheckcommonprefix(vector<string>& strs , int right){
        for(int i = 0; i < strs.size()-1 ; i++){
            for(int j = 0 ; j<= right; j++){
                if(strs[i][j] != strs[i+1][j]) return false;
            }
            
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        //using binary search

        int n = strs.size();

        int miniLen = strs[0].size();
        for(int i = 0; i < n; i++){
             miniLen = min(miniLen , (int) strs[i].size());
        }

        //apply binary search to find longest common prefix length 
        int low = 0;
        int high = miniLen-1;
        int prefixlength = 0;

        while(low <= high){
            int mid = (low + high)/2;

            //we will make a function to compare all the  string 
            //from index low to high and see if they have commonprefix or not
            if(tocheckcommonprefix(strs,mid)){

                // If all the strings in the input array
                // contains common prefix till mid index
                // then update prefixLen with mid + 1 
                prefixlength = mid+1;
                low = mid+1;//search for greater index
            }else{
                high = mid-1;
            }
        }
        return strs[0].substr(0,prefixlength);
    }
};
//T.C : O(n*m*logm)
//S.C : O(m) lenght of smallest string in worst case

//Approach4: vertical scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = strs[0].size();

        for(string str: strs){
            minLen = min(minLen , (int)str.size());
        }

        int i = 0; 
        while(i < minLen){
            int j = 0;
            while(j < strs.size()-1){
                if(strs[j][i] != strs[j+1][i]) return strs[0].substr(0,i);
                j++;
            }
            i++;
        }

        return strs[0].substr(0 , i);
    }
};
//T.C : O(m*n)
//S.C : O(m) 
