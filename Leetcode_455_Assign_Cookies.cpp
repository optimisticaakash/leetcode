//Approach 1 : 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int l = 0;
        int r = 0;

        while(l < n && r < m){
            if(g[l] <= s[r]){
                l++;//next ke liye check krenge
            }
            //agar nhi assign ho skta next cookie ke liye check krenge
            r++;
        }

        return l;
    }
};

//T.C : O(nlogn + mlogm)
//S.C : O(1) 
