//Approach1 : 
class Solution {
public:
    int totalMoney(int n) {
        int start_monday = 1;
        int total_money = 0;
        while(n > 0){
            int money = start_monday;

            for(int i = 1; i <= min(7,n); i++){
                total_money += money;
                money++;
            }

            n = n-7;
            start_monday++;
        }

        return total_money;
    }
};

//T.C :O(n)
//S.C :O(1)


//Approach two : using ap
class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7;//weeks

        int first = 28;
        int last = first + (terms - 1) * 7;//Ap formula for nth term

        int result = terms * (first + last)/2;//sum of nth term in Ap

        //final week remaining_days  = n%7

        int start_money = 1 + terms;

        for(int day = 1; day <= (n%7) ; day++){
            result += start_money;
            start_money++;
        }

        return result;
    }
};
//T.C : O(1)
//S.C : O)(1)

//Approach2 : using ap  but different code
class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7;//weeks

        int first = 28;
        int last = first + (terms - 1) * 7;//Ap formula for nth term

        int result = terms * (first + last)/2;//sum of nth term in Ap

        //remaining days
        int remain = n%7;
        int first_terms = 1+terms;
        int last_terms = first_terms +(remain-1);

        result += remain * (first_terms + last_terms)/2;
        

        return result;
    }
};
//T.C : O(1)
//S.C :O(1)
