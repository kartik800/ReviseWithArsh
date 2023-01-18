class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        
        // if no move then knight at same pos so prob is 1
        if(k==0) return 1.0;

        // curr chess board 
        vector<vector<double>> curr(n, vector<double>(n, 0.0));

        // next chess board
        vector<vector<double>> next(n, vector<double>(n,0.0));

        // row and col offset for generating next move;
        int rowoffset[] = {-2,-2,-1,-1,2,2,1,1};
        int coloffset[] = {1,-1,2,-2,1,-1,2,-2};

        curr[row][column] = 1.0; // at [row][col] prob is  1.0 else 0.0

        // run for k
        // move in curr chess board if element is non-empty then go all possible position
        // and update the propobability
        for(int i=0;i<k;i++){

            for(int p=0;p<n;p++){
                for(int q=0;q<n;q++){

                    if(curr[p][q] != 0){
                        double nextMoveProb = curr[p][q] / 8.0;

                        for(int w=0; w<8; w++){
                            int np = p + rowoffset[w];
                            int nq = q + coloffset[w];

                            if(np>=0 && nq>=0 && np < n && nq < n){
                                next[np][nq] += nextMoveProb;
                            }
                        }

                    }
                }
            }
            curr = next;
            fill(next.begin(), next.end(), vector<double>(n, 0.0));
        }

        double knightProb = 0.0;

        // add all the possible probability
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                knightProb += curr[i][j];
            }
        }
        return knightProb;   
    }
};