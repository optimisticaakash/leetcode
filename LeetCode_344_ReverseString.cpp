//Approach1 : using two pointer without swap function
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int i = 0; 
        int j = n-1;

        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }
    }
};
//T.C : O(N) 
//S.C : O(1) 


//Approach2 : using two pointer with swap function 
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int i = 0; 
        int j = n-1;

        while(i < j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
//T.C :O(N)
//S.C :O(N)
