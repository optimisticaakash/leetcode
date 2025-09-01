//Approach1 : class Solution {
public:
    bool issafe(vector<vector<char>>& board , int row , int col , char dig){
        //horizontal
        for(int j = 0; j < 9; j++){
            if(j!= col && board[row][j]==dig) return false;//jo cell bheja hai use check nhi krenge
        }

        //vertical
        for(int j = 0; j < 9; j++){
            if(j!= row && board[j][col]==dig) return false;//jo bheja hai cell use check nhi krenge
        }

        //for grid
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int i = srow; i <= srow+2; i++){
            for(int j = scol; j <= scol+2; j++){
                if((i!= row || j!= col ) && board[i][j] == dig){//jis cell ko bheja hai use skip krenge
                    return false;
                }
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0;j < 9; j++){
                char ch = board[i][j];
                if(ch != '.' && !issafe(board,i,j,ch)){
                    return false;
                }
            }
        }
        return true;
    }

    
};

//T.C : O(81)
//S.C : O(1)

//Approach2 : 
class Solution {
public:
    bool validcell(vector<vector<char>>& board,int row,int col , char c ){
        for(int i = 0; i <9; i++){
            //same row me har col dekhenge 
            if(i!= col && board[row][i]==c){
                return false;
            }
                

            //same col me har row pr dekhenge 
            if(i!= row && board[i][col]==c){
                return false;
            }
                
            
            //jis cell me jis char ke liye check kr rhe hai us submatrix ke har cell me dekhenge
            //woh char hai ya nhi hai to cant fill
            int subRow = 3 * (row/3) + i/3;
            int subCol = 3 * (col/3) + i%3; 
            if( (subRow!= row || subCol!= col)
                && (board[subRow][subCol]==c)){
                return false;
            }
                
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0;j < 9; j++){
                char ch = board[i][j];
                if(ch != '.' && !validcell(board,i,j,ch)){
                    return false;
                }
            }
        }
        return true;
    }

    
};

//Approach3 : using set to store already filled value
class Solution {
public:
    bool validBox(vector<vector<char>>& board,int sr , int er , int sc ,int ec){
        unordered_set<char> st;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end())
                     return false;

                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //validate rows
        for(int row = 0; row < 9; row++){
            unordered_set<char> st;
            for(int col = 0; col<9; col++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end()) return false;

                st.insert(board[row][col]);
            }

        }

        //validate cols
        for(int col = 0; col < 9; col++){
            unordered_set<char> st;
            for(int row = 0; row<9; row++){
                if(board[row][col] == '.') continue;
                if(st.find(board[row][col]) != st.end()) return false;

                st.insert(board[row][col]);
            }

        }

        //for validate traversel
        for(int sr = 0; sr < 9; sr += 3){
            int er = sr+2;
            for(int sc = 0; sc < 9; sc += 3){
                int ec =sc+2;
                if(!validBox(board,sr,er,sc,ec)) return false;
            }
        }


        return true;
    }
};

//Approach : Using string 
 class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j]=='.') continue;

                string row = string(1,board[i][j])+"_ROW_"+to_string(i);
                string col = string(1,board[i][j])+"_COL_"+to_string(j);
                string box = string(1,board[i][j])+"_BOX_"+to_string(i/3)+"_"+to_string(j/3);

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end())
                    return false;

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
            
        }
        return true;
    }
};
//T.C : O(81) 
//S.C : O(81*3) strings bnegi
