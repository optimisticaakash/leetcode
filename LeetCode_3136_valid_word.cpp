//Appraoch 1 : without using stl 
class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(word.length() < 3){
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant  = false;

        for(int i = 0; i < n; i++){
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z' || 
            ch >= 'A' &&  ch <= 'Z'){
                ch = tolower(ch);
                if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    hasVowel = true;
                }else{
                    hasConsonant = true;
                }
            }else if(!(ch >= '0' && ch <= '9')){
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
};
//T.C : O(n) 

//Appraoch2 : using stl
class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(word.length() < 3){
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant  = false;

        for(char ch : word){
            
            if(isalpha(ch)){//isalpha() ye batata hai char alphabet hai ya nhi 
                ch = tolower(ch);
                if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    hasVowel = true;
                }else{
                    hasConsonant = true;
                }
            }else if(!isdigit(ch)){
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
};
