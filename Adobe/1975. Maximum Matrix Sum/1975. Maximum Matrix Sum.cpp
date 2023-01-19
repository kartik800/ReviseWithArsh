class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long smallestNumber = LONG_LONG_MAX;

        long long sum = 0;
        int negCnt = 0;

        for(int i=0;i<matrix.size();i++){

            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]< 0){
                    negCnt++;
                }

                sum += abs(matrix[i][j]);
                if(abs(matrix[i][j]) < smallestNumber){
                    smallestNumber = abs(matrix[i][j]);
                }
            }
        }

        if(negCnt%2==0){
            return sum;
        }
        return sum - (2* smallestNumber);

        
    }
};