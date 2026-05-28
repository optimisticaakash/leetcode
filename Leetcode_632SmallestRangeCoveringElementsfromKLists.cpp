//Approach1 : Bruteforce
class Solution {
public:
    bool checkValid(vector<vector<int>>& nums , int L , int R){
        for(int k = 0; k < nums.size(); k++){

            bool found = false;
            //har List me iterate krenge
            for(auto it : nums[k]){
                if(L <= it && it <= R){
                    found = true;
                    break;
                }
            }

            //is list me se kuch nhi mila
            if(found == false){
                return false;
            }
        }
        return true;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int> final;
        for(int i = 0; i < nums.size(); i++){
            for(auto it : nums[i]){
                final.push_back(it);
            }
        }

        sort(begin(final) , end(final));

        int start = 0;
        int end = INT_MAX;
        for(int i = 0; i < final.size(); i++){
            for(int j = i; j < final.size(); j++){
                int L = final[i];
                int R = final[j];

                if(checkValid(nums, L , R)){
                    //ab smallest check kro

                    if((R-L < end - start)||(R-L == end - start) && L < start){
                        start = L;
                        end = R;
                    }
                }
            }
        }

        return {start , end};
    }
};

//T.C : O(N^2 * n * k )
//where: N - total no of elements
// n - avg size of a list
// k - no of lists
//S.C : O(N^2)

//Approach2 : Better Approach
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k , 0);

        vector<int> resultRange = {-1000000 , 1000000};//a , b

        while(true){
            int minEle = INT_MAX;
            int maxEle = INT_MIN;
            int minEleListIndex = 0;

            for(int i = 0; i < k; i++){
                int listIdx = i;
                int elIdx = vec[i];
                int element = nums[listIdx][elIdx];

                if(element < minEle){
                    minEle = element;
                    minEleListIndex = listIdx;
                }

                maxEle = max(maxEle , element);
            }

            // better range check
            int currRange = maxEle - minEle;
            int bestRange = resultRange[1] - resultRange[0];

            if (currRange < bestRange || 
               (currRange == bestRange && minEle < resultRange[0])) {
                resultRange[0] = minEle;
                resultRange[1] = maxEle;
            }


            //Now shorted this range by moving minElment idx
            int nextIndex = vec[minEleListIndex]+1;

            //agar list end hogyi to stop
            if(nextIndex >= nums[minEleListIndex].size()){
                break;
            }
            //update index 
            vec[minEleListIndex] = nextIndex;
        }

        return resultRange;
    }
};

//T.C : O(N* k)
//where: N - total no of elements
// n - avg size of a list
// k - no of lists
//S.C : O(k)

//Approach3 : Optimised Approach
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        //{element , ListIdx , idx} vector<int>{a,b,c} 
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;

        int maxEle = INT_MIN;
        for(int i = 0; i < k; i++){
            pq.push({nums[i][0] , i , 0});
            maxEle = max(maxEle , nums[i][0]);
        }

        vector<int>resultRange = {-1000000 , 1000000};

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int minEle = curr[0];
            int Listidx = curr[1];
            int idx = curr[2];

            int currRange = maxEle - minEle;
            int BestRange = resultRange[1] - resultRange[0];

            //update if got better range
            if(currRange < BestRange || currRange == BestRange && minEle < resultRange[0]){
                resultRange[0] = minEle;
                resultRange[1] = maxEle;
            }

            //decrease the range for minimum idx

            if(idx + 1 < nums[Listidx].size()){
                int nextEle = nums[Listidx][idx+1];
                pq.push({nextEle , Listidx , idx+1});
                maxEle = max(maxEle , nextEle);
            }else{
                break;
            }
        }
        return resultRange;
    }
};
//T.C : O(N* logk)
//S.C :O(K)
