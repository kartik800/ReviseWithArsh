class Solution {
public
    int minMutation(string startGene, string endGene, vectorstring& bank) {
        unordered_setstring uniqueBank(bank.begin(), bank.end());
        unordered_setstring visited;

        queuestring q;
        q.push(startGene);
        visited.insert(startGene);
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;in;i++){
                string word = q.front();
                q.pop();
                if(word == endGene) return level;

                for(int j=0;jword.size(); j++){
                    for(char ch ACGT){
                        string temp = word;
                        temp[j] = ch;

                        if(visited.find(temp) == visited.end() && uniqueBank.find(temp) != uniqueBank.end()){
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }

            }
            level++;
        }
        return -1;
    }
};