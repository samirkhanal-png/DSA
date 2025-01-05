class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        int firstRowZero=0;
        int firstColZero=0;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(matrix[i][j]==0){
                if(i==0)firstRowZero=1;
                if(j==0)firstColZero=1;
                 matrix[i][0]=0;
                 matrix[0][j]=0;
                }
            }
        }

       //Set inner matrix elements to zero
       for(int i=1;i<rowSize;i++){
        for(int j=1;j<colSize;j++){
            if(matrix[i][0]==0||matrix[0][j]==0)
             matrix[i][j]=0;
        }
       }

       if(firstRowZero){
        for(int j=0;j<colSize;j++){
            matrix[0][j]=0;
        }
       }

        if(firstColZero){
            for(int i=0;i<rowSize;i++){
                matrix[i][0]=0;
            }
        }
    }
};
/*
TC:2*O(n*M)+O(N)+O(M)
SC:O(1)

0 2 3 4 0   i=0  if any elements in this is zero then whole col becomes zero
4 7 8 0 9
0 2 1 0 2
j=0

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     int rowSize=matrix.size();
     int colSize=matrix[0].size();
     vector<int>cols(colSize);
     vector<int>rows(rowSize);
     for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            if(matrix[i][j]==0){
                rows[i]=1;
                cols[j]=1;
            }
        }
     }

    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
         if(rows[i]||cols[j]){
            matrix[i][j]=0;
         }
        }
     }

    }
};

//SC:O(N+M)  TC:O(n*m)

