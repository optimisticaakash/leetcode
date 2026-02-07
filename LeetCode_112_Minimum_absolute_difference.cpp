//Approach1. Two pass solution
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> answer;

        sort(arr.begin(),arr.end());

        int mindiff = INT_MAX;
        //1.Find the minimum absolute difference
        for(int i = 0; i< n-1; i++){
            int diff = arr[i+1]-arr[i];

            if(diff < mindiff){
                mindiff = diff;
                answer.clear();//we need to remove old pairs
                answer.push_back({arr[i],arr[i+1]});
            }else if(diff == mindiff){
                answer.push_back({arr[i],arr[i+1]});
            }
        }

        return answer;
    }
};

//T.C : O(nlogn)
//S.C : O(N)

//Approach2. one pass solution
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> answer;

        sort(arr.begin(),arr.end());

        int mindiff = INT_MAX;
        //1.Find the minimum absolute difference
        for(int i = 0; i< n-1; i++){
            int diff = arr[i+1]-arr[i];

            if(diff < mindiff){
                mindiff = diff;
                answer.clear();//we need to remove old pairs
                answer.push_back({arr[i],arr[i+1]});
            }else if(diff == mindiff){
                answer.push_back({arr[i],arr[i+1]});
            }
        }

        return answer;
    }
};

//T.C : O(nlogn)
//S.C : O(N) 
