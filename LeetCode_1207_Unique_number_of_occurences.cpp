//Approach1: using hashmap 
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;

        for(int i : arr){
            mpp[i]++;
        }

        unordered_set<int> st;

        for(auto it : mpp){
            int freq = it.second;// it.first = number
            if(st.find(freq) != st.end()){
                return false;
            }

            st.insert(freq);
        }

        return true;
    }
};
//T.C : O(n)
//S.C : O(k) k is the number of unique elements


//Appraoch2: using array for hashing
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001);

        // for(int i = 0; i < arr.size() ; i++){
        //     vec[arr[i]+1000]++;
        // }
        for(int it: arr){
            vec[it+1000]++;
        }

        sort(vec.begin() , vec.end());

        for(int i = 0; i < 2001; i++){
            if(vec[i] != 0 && vec[i] == vec[i-1]) return false;
        }

        return true;
    }
};

//T.C : O(1)
//S.C : O(1)
