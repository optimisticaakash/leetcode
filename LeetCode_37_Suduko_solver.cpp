//Appraoch1 : using recursion backtraking
class Solution {
public:

    bool validcell(int row,int col , char c,vector<vector<char>>& board ){
        for(int i = 0; i <9; i++){
            //same row me har col dekhenge 
            if(board[row][i]==c){
                return false;
            }
                

            //same col me har row pr dekhenge 
            if(board[i][col]==c){
                return false;
            }
                
            
            //jis cell me jis char ke liye check kr rhe hai us submatrix ke har cell me dekhenge
            //woh char hai ya nhi hai to cant fill 
            if(board[3 * (row/3) + i /3 ][3 * (col/3)+ i % 3]==c){
                return false;
            }
                
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){

                if(board[i][j] == '.'){

                    for(char c = '1'; c <= '9'; c++){
                        if(validcell(i , j , c,board)){
                            board[i][j] = c;

                            if(solve(board)== true)
                                return true;//mtlb ki sari position pr dal diya hai right no 
                            else
                                //jo humne bhara woh galt bhara to dubata khali kr denge
                                board[i][j] = '.';
                        }
                    } 
                    //hum kuch bhi fill nhi kr paye 
                    return false;
                }
            }
        }
        return true;//ek bhi cell empty nhi tha mtlb sb already filled hai  shi no se 
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

//T.C : O(9^81) : in worst case 81 cell total whi empty hai to sbke liye 9 optioon
//O(9^k) k is the no of empty cell

//S.C : O(81) recursion stack space


