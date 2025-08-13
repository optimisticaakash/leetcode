//Approach1 : using plain recursion
class Solution {
public:
    bool isValid(const string&s){
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0' && s[i-1] =='0') return false;
        }
        return true;
    }
    void stringGenerator(int n , string curr , vector<string> &ans){
        if(curr.size() == n){
            if(isValid(curr)) ans.push_back(curr);
            return;
        }

        //generating all if last is 0
        stringGenerator(n , curr+"0" , ans);

        //generating all if last is 1
        stringGenerator(n,curr+"1" , ans);
    }
    //Approach1 : using recursion
    vector<string> validStrings(int n) {
        vector<string>ans;

        stringGenerator(n , "" , ans);
        return ans;
    }
};
//T.C : O(2^n * n) 
//S.C : O(n) //recursive depth

//Approach 2 : using  recursion + pruning 
class Solution {
public:
    //using recursion + pruning
    void stringGenerator(int n , string &curr ,vector<string> &ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        //choice 1 : add 1 
        curr.push_back('1');
        stringGenerator(n , curr ,ans);
        curr.pop_back();

        //choice 1 : 0 tb hi add kr skte , when last is not 0
        if(curr.empty() || curr.back() != '0'){
            curr.push_back('0');
            stringGenerator(n,curr, ans);
            curr.pop_back();
        } 
    }
    //Approach1 : using recursion
    vector<string> validStrings(int n) {
        vector<string>ans;
        string curr;//empty string ""
        stringGenerator(n ,curr , ans);
        return ans;
    }
};
//T.C : O(2^n)
//S.C : O(n) //recursive depth

//Approach3 : using backtracking
class Solution {
public:
    //using recursion + backtracking
    void stringGenerator(int n , string &curr ,vector<string> &ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        //choice 1 : add 1 
        curr.push_back('1');
        stringGenerator(n , curr ,ans);
        curr.pop_back();

        //choice 1 : 0 tb hi add kr skte , when last is not 0
        if(curr.empty() || curr.back() != '0'){
            curr.push_back('0');
            stringGenerator(n,curr, ans);
            curr.pop_back();
        } 
    }
    //Approach1 : using recursion
    vector<string> validStrings(int n) {
        vector<string>ans;
        string curr;//empty string ""
        stringGenerator(n ,curr , ans);
        return ans;
    }
};
//T.C : O(2^n)
//S.C : O(n) 

//Approach 4 : using bit manipulation 
//BAd me kregne
