//Approach1 : bruteforce 
class Solution {
public:
    bool prime(int n){
        int cnt = 0;
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                cnt++;
                if(n/i != i) cnt++;
            }
        }
        return cnt == 2;
    }
    int countPrimes(int n) {
        int cntprime = 0;
        for(int i = 1; i< n; i++){
            if(prime(i))cntprime++;
        }
        return cntprime;
    }
};

//T.C : O(n* sqrt(n))
//S.C : O(1) 
//but this gives time limit exceeded

//Approach2 : optimise-using sieve of erathoness
//we will need to check prime in O(1) 
class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1);
        for(int i = 2; i <= n; i++){
            prime[i]=1;
        }

        for(int i = 2; i <= n; i++){
            if(prime[i]==1){
                for(int j = 2*i; j <= n; j+=i){
                    prime[j]=0;
                }
            }
        }

        int cnt = 0;
        for(int i =2 ; i <n; i++){
            if(prime[i] == 1)cnt++;
        }

        return cnt;
    }
};

//T.C : O(n) + O(nlogn) + O(n) 
//S.C : O(n) 

//Appraoch 3 : 2 ka better version
class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1);
        for(int i = 2; i <= n; i++){
            prime[i]=1;
        }

        for(int i = 2; i*i<= n; i++){
            if(prime[i]==1){
                for(int j = i*i; j <= n; j+=i){
                    prime[j]=0;
                }
            }
        }

        int cnt = 0;
        for(int i =2 ; i <n; i++){
            if(prime[i] == 1)cnt++;
        }

        return cnt;
    }
};

//T.C : O(N(log(logN))) 
//S.C : O(N) 

