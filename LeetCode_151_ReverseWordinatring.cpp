//Appraoch 1 : using bruteforce : 
//1. string se word nikal  kr ekvector me store kr rhe 
//2. phir unke order ko vector me hi reverse kr rhe hai 
//3. then ek result string banaya 
//4.phir ek ek krke words dale vector se result string me 
//5. or harword ke baad space bas i == 0 or 9i == n-1 pr space add nhi krna 
//suru or last word ke liye
class Solution {
public:
    string reverseWords(string s) {
       
        stringstream ss(s);
        string token ;

        vector<string> words;

        while(getline(ss,token,' ')){
            if(!token.empty())
            words.push_back(token);
        }

        int n = words.size();

        for(int i = 0; i <n/2; i++){
            swap(words[i] , words[n-i-1]);
        }
        string result = "";
        for(int i = 0; i < n; i++){
            result += words[i];
            if(i != n-1) result += " ";
        }
        return result;
    }
};
//T.C : O(n)
//S.C : O(n) 

//Alternative code:
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stringstream ss(s);
        string token="";
        string result;

        while(ss >> token){//by default space ke baisis pr todega word ko 
            result = token +" "+result;
        }

        return result.substr(0,result.size()-1);
    }
};
//T.C : O(n)
//S.C : o(2n)
//same code bas space nikalne ka treeka different
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stringstream ss(s);
        string token="";
        string result="";

        while(ss >> token){//by default space ke baisis pr todega word ko 
            result = token +" "+result;
        }

        if(!result.empty() && result.back()==' '){
            result.pop_back();
        }
        return result;
    }
};
//T.C : O(n)


//optimal approach : using two pointer
class Solution {
public:
    string reverseWords(string s) {
        //1.revere the whole string
        reverse(s.begin() , s.end());

        int i = 0;
        //2.hero honge humare l and r jo reverse krenge word between l and r
        int l = 0 ;
        int r = 0;

        int n = s.length();

        while(i<n){
            while(i<n && s[i]!= ' '){
                s[r]=s[i];
                i++;
                r++;
            }

            if(l < r){//l ...  r
                reverse(s.begin()+l , s.begin() + r); 
                s[r] = ' ';
                r++;

                l = r;
            }
            i++;// ye to badhta hi rhega
        }
        s = s.substr(0 , r-1);
        return s;
    }
};
//T.C : O(n) 
//S.C : O(n) 
