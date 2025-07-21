//Approach 1; class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto myComparator = [](int a , int b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            // if(s1+s2 > s2+s1){
            //     return true;
            // }
            // return false;
            return (s1+s2 > s2+s1);
        };
        
        sort(nums.begin() , nums.end() ,    myComparator);

        if(nums[0] == 0) return "0";

        string s = "";
        for(int num : nums){
            s += to_string(num);
        }

        return s;
    }
};

//code2:
class myComparator{
    public:
        bool operator()(int a , int b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            return (s1+s2 > s2+s1);
        }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //using function object (functors)
        sort(nums.begin() , nums.end() , myComparator());

        if(nums[0] == 0) return "0";

        string s = "";
        for(int num : nums){
            s += to_string(num);
        }

        return s;
    }
};

//Code3:

class Solution {
public:

     static bool myComparator(int a , int b){
        
            string s1 = to_string(a);
            string s2 = to_string(b);

            return (s1+s2 > s2+s1);
        }

    string largestNumber(vector<int>& nums) {
        //using function
        sort(nums.begin() , nums.end() , myComparator);

        if(nums[0] == 0) return "0";

        string s = "";
        for(int num : nums){
            s += to_string(num);
        }

        return s;
    }
};


//T.C : O(nlogn + k)
//S.C : O(k)
