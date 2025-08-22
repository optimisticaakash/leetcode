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

//Another code 
class Solution {
public:
    bool issafe(vector<vector<char>>& board , int row , int col , char dig){
        //horizontal
        for(int j = 0; j < 9; j++){
            if(board[row][j]==dig) return false;
        }

        //vertical
        for(int j = 0; j < 9; j++){
            if(board[j][col]==dig) return false;
        }

        //for grid
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int i = srow; i <= srow+2; i++){
            for(int j = scol; j <= scol+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }
    bool solvehelper(vector<vector<char>>& board , int row , int col){
        //base case
        if(row == 9)return true;

        int nextRow = row;
        int nextCol = col+1;
        if(nextCol == 9){
            nextRow =row+1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){
            return solvehelper(board,nextRow , nextCol);
        }

        //place digit
        for(char dig = '1'; dig <= '9'; dig++){
            
            if(issafe(board,row,col,dig)){
                board[row][col]=dig;
                if(solvehelper(board,nextRow,nextCol)){
                    return true;
                }
                board[row][col]='.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solvehelper(board , 0 , 0);
    }
};

//T.C : O(9^81) : in worst case 81 cell total whi empty hai to sbke liye 9 optioon
//O(9^k) k is the no of empty cell

//S.C : O(81) recursion stack space


