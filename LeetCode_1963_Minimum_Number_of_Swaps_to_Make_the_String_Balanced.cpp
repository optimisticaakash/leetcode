//Approach1 : using stack
class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                st.push(s[i]);
            }else{
                if(!st.empty())
                    st.pop();
            }
        }


        int swap = ((st.size()+1)/2);
        return swap;
    }
};
//T.C :O(N)
//S.C :O(1)

//approach 2 : withoout stack

class Solution {
public:
    int minSwaps(string s) {
        int size = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                size++;
            }else{
                if(size>0)
                    size--;
            }
        }


        int swap = ((size+1)/2);
        return swap;
    }
};
//T.C : O(N)
//S.C :O(1)

//Cleaner version:
class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        int imbalance = 0;//for count of ']'

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                open++;
            }else{
                if(open>0)
                    open--;
                else
                    imbalance++;
            }
        }


        int swap = ((imbalance+1)/2);
        return swap;
    }
};

//T.C :O(N)
