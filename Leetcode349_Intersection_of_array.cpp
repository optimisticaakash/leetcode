//only unique elements
//Approach 1 : simplest using sets 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //put all elments of num1 into st in one go
        //unordered_set<int> st1(nums1.begin() , nums1.end()); 
        unordered_set<int> st1(begin(nums1) , end(nums1));
        unordered_set<int> resultset;

        for(int & num:nums2){
            if(st1.count(num)){
                resultset.insert(num);
            }
        }

        //vector<int> result(resultset.begin(),resultset.end());
        vector<int> result(begin(resultset) , end(resultset));
        return result;
    }
};

//T.C = O(m+n)
//S.C = O(m+n)

//Alternate code :
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //put all elments of num1 into st in one go
        //unordered_set<int> st1(nums1.begin() , nums1.end()); 
        unordered_set<int> st1(begin(nums1) , end(nums1));
        unordered_set<int> resultset;

        for(int & num:nums2){
            if(st1.find(num) != st1.end()){
                resultset.insert(num);
            }
        }

        //vector<int> result(resultset.begin(),resultset.end());
        vector<int> result(begin(resultset) , end(resultset));
        return result;
    }
};
//Approach 2 : using 1 set only 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //put all elments of num1 into st in one go
        unordered_set<int> st1(nums1.begin() , nums1.end()); 
        
        vector<int> result;
        for(int & num:nums2){
            if(st1.find(num) != st1.end()){
                result.push_back(num);
                st1.erase(num);
            }
        }

        
        return result;
    }
};

//T.C:O(m+n)
//S.C : O(n) + O(k) 
//o(n) set me store krne ke liye 
//o(k) intersection wale elements store krne ke liye 

//Approach 3 : 2 pointers approach array ko sort krke 
//1.arrays ko sort krenge
//2.i and j 2 pointer lenge 
//3. agar dono elements me same to result me push krenge i and j ko move krenge
//4.agar ith == ith+1 element Or j== j+1 element : to i++ or j++
//5.jiska element chota uska pointer aage badha denge kyonki sorted order me hai to chote wale me bada element aage same aa skta hai 

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());

        vector<int> result;
        int i = 0; 
        int j = 0; 

        int m = nums1.size();
        int n = nums2.size();

        while(i < m && j < n){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                while( i < m-1 && nums1[i] == nums1[i+1]){
                    i++;
                }

                while(j < n-1 && nums2[j] == nums2[j+1]){
                    j++;
                }
                i++;
                j++;
            }else if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }

        return result;
    }
};

//T.C = O(m+mlogm+n+nlogn)
//S.C = O(k) for intersectionn element ko store krne ke liye 
