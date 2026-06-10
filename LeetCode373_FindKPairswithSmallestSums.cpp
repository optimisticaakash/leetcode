//Approach1.Bruteforce but better
class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P , vector<P>> pq;//maxheap

        int m = nums1.size();
        int n = nums2.size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = nums1[i] + nums2[j];

                if(pq.size() < k ){
                    pq.push({sum,{i,j}});//
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum , {i , j}});
                }else{
                    break;
                }
            }
        }

        vector<vector<int>> pairs;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            pairs.push_back({nums1[i] , nums2[j]});
        }

        return pairs;
    }
};

//T.C : O(m * n * logk)
//S.C : O(k)

//Approach2 : optimised approach
class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P , vector<P> , greater<P>> pq;//minheap

        int m = nums1.size();
        int n = nums2.size();

        set<pair<int,int>> visited;

        int sum = nums1[0]+nums2[0];
        pq.push({sum,{0,0}}); 
        visited.insert({0,0});

        vector<vector<int>> pairs;

        while(k-- > 0 && !pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            pairs.push_back({nums1[i] , nums2[j]});

            //i , j

            //push i , j+1 if possible
            if(j+1 < n && visited.find({i , j+1}) == visited.end()){
                pq.push({nums1[i]+nums2[j+1] , {i , j+1}});
                visited.insert({i , j+1});
            }

            //push i+1 , j if possible
            if(i+1 < m && visited.find({i+1 , j}) == visited.end()){
                pq.push({nums1[i+1]+nums2[j] , {i+1 , j}});
                visited.insert({i+1 ,j});
            }
        }


        return pairs;
    }
};
//T.C : O(min(k , m*n) * log(min(k , m*n)))
//S.C : O(min(k , m*n))
