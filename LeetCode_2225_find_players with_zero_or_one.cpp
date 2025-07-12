//Approach 1: bruteforce 
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        vector<vector<int>> answers(2);
        vector<int>players;

        for(int i = 0; i < n; i++){//O(n)
            players.push_back(matches[i][0]);
            players.push_back(matches[i][1]);
        }


        sort(players.begin() , players.end());//O(2nlog2n)
        players.erase(unique(players.begin() , players.end()) , players.end());//o(n)

        for(int i = 0; i < players.size() ; i++){//O(p*n) where p is no of unique plalyers
            int lostCount = 0;
            for(int j = 0; j < n; j++){
                if(matches[j][1] == players[i]) lostCount++;
            }

            if(lostCount == 0){
                answers[0].push_back(players[i]);
            }else if(lostCount == 1){
                answers[1].push_back(players[i]);
            }
        }


        return answers;
    }
};
//T.C = O(n) + O(nlogn) + O(n) + O(n^2) = O(n2)
//Note : in worst case p = 2n 

//S.C : O(n) + O(2n) = O(3n) 

//Approach2 : using hashing
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();

        unordered_map<int,int> lost_map;

        for(auto match : matches){
            lost_map[match[1]]++;
        }

        vector<vector<int>> answers(2);

        for(int i = 0; i < n; i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(lost_map.find(winner) == lost_map.end()){
                answers[0].push_back(winner);
                lost_map[winner] = 2;//jo winner humne answer me dal diya dubara na aajaye 
                //isliye map mee dal diya taki check krne pr ho map me or answer me na aaye 
                // or frequency 2 isliye kyonki ek krenge to loser me aa jyega woh
            }

            if(lost_map[loser] == 1){
                answers[1].push_back(loser);
            }
        }

        sort(answers[0].begin() , answers[0].end());
        sort(answers[1].begin() , answers[1].end());


         return answers;
    }
};
//T.C  : O(n) + O(n) + nlogn = O(nlogn)
//S.C : O(n) 
