//Approach 1 : using map 
class Solution {
public:
    typedef pair<char,int> P;
    string frequencySort(string s) {
        unordered_map<char,int>mpp;

        for(char &ch : s){
            mpp[ch]++;
        }

        vector<pair<char , int>>vec;

        for(auto &it :mpp){
            vec.push_back(it);
        }
        auto lambda = [&](P &p1 , P &p2){
            return p1.second > p2.second;
        };
        //sort(begin(vec) , end(vec) , lambda);
        sort(vec.begin() , vec.end() , lambda);
        
        string result = "";
        for(int i = 0;i< vec.size(); i++){
           
            if(vec[i].second>0){
                char ch = vec[i].first;
                int freq = vec[i].second;
                string temp = string(freq , ch);

                result += temp;
            }
        }

        return result;
    }
};
//T.C : O(n)
//S.C : O(n)

//Approach2 : using vector
class Solution {
public:
    typedef pair<char,int> P;
    string frequencySort(string s) {
        vector<P>vec(123);

        for(char &ch : s){
            int freq = vec[ch].second;
            vec[ch] = {ch , freq+1};
        }
        auto lambda = [&](P &p1 , P &p2){
            return p1.second > p2.second;
        };
        //sort(begin(vec) , end(vec) , lambda);
        sort(vec.begin() , vec.end() , lambda);
        
        string result = "";
        // for(int i = 0; i < 123; i++){
           
        //     if(vec[i].second>0){
        //         char ch = vec[i].first;
        //         int freq = vec[i].second;
        //         string temp = string(freq , ch);

        //         result += temp;
        //     }
        // }
        for(auto &it : vec{
            string += string(it.second , it.first);
          }

        return result;
    }
};
//T.C : O(n)
//S.C : O(n) 

//Approach 3 : using priority queue(heap)
class Solution {
public:
    typedef pair<char , int> P;
    struct lambda{
            bool operator()(P &p1 , P &p2){
                return p1.second < p2.second;//heap = top me maximum frquency wali entry hogi

            }
    };
    string frequencySort(string s) {

        priority_queue<P , vector<P>, lambda> pq;

        unordered_map<char , int > mp;
        //frequency updated in map 
        for(char &ch: s){
            mp[ch]++;
        }
        //fill in heap from map 
        for(auto &it : mp){
            pq.push({it.first , it.second});
        }

        string result = "";
        while(! pq.empty()){
            P temp  = pq.top();
            pq.pop();

            result += string(temp.second , temp.first);
        }
        return result;
    }
};

//different  method for comparator creation 

class Solution {
public:
    typedef pair<char , int> P;
   
    string frequencySort(string s) {
        auto lambda = [&](const P &p1 , const P &p2){
            return p1.second < p2.second;
        };
        priority_queue<P , vector<P>, decltype(lambda)> pq(lambda);

        unordered_map<char , int > mp;
        //frequency updated in map 
        for(char &ch: s){
            mp[ch]++;
        }
        //fill in heap from map 
        for(auto &it : mp){
            pq.push({it.first , it.second});
        }

        string result = "";
        while(! pq.empty()){
            P temp  = pq.top();
            pq.pop();

            result += string(temp.second , temp.first);
        }
        return result;
    }
};

//Agar phla int ho or dusra char to , max heap hi bnega by default to easy 

class Solution {
public:
    typedef pair<int, char> P;  // frequency first, character second
   
    string frequencySort(string s) {
        priority_queue<P , vector<P>> pq;
        unordered_map<char , int > mp;

        // Step 1: Count frequencies
        for(char &ch: s){
            mp[ch]++;
        }

        // Step 2: Push into max heap
        for(auto &it : mp){
            pq.push({it.second , it.first});
        }

        string result = "";

        // Step 3: Build result string
        while(!pq.empty()){
            P temp = pq.top();
            pq.pop();

            result += string(temp.first, temp.second);  ///frequency, char
        }

        return result;
    }
};
//T.C : O(n + klogk)
//S.C : O(n+k)
