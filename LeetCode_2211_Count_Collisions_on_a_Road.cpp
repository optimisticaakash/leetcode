//Approach1 : using two pointer simple simulation
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        int i = 0;
        while(i < n && directions[i] == 'L'){
            i++;
        }

        int j = n-1;
        while(j >= 0 && directions[j] == 'R'){
            j--;
        }

        int collisions = 0;
        while(i <= j){
            if(directions[i] == 'L' || directions[i] == 'R'){
                collisions++;
            }
            i++;
        }

        return collisions;
    }
};
//T.C : O(N)
//S.C : O(1)

//Code 2 : 
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        int i = 0;
        while(i < n && directions[i] == 'L'){
            i++;
        }

        int j = n-1;
        while(j >= 0 && directions[j] == 'R'){
            j--;
        }

        int collisions = 0;
        while(i <= j){
            if(directions[i] != 'S'){
                collisions++;
            }
            i++;
        }

        return collisions;
    }
};
//T.C : O(N)
//S.C : O(1)
