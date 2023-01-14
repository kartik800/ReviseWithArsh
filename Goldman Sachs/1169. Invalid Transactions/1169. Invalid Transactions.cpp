class Transaction{
public:
    string personName;
    int transactionTime;
    int transactionAmount;
    string transactionCity;

    Transaction(string name, int time, int amount, string city){
        this->personName = name;
        this->transactionTime = time;
        this->transactionAmount = amount;
        this->transactionCity = city;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int numTransaction = transactions.size();

        vector<bool> isValid(numTransaction, true);
        vector<Transaction> inputTransactions;

        for(int i=0; i <numTransaction;i++){
          string currTransaction = transactions[i];
            string name = "", time = "", amount = "", city = "";
            int j = 0;
            
            // Extracting name
            while(currTransaction[j] != ',')
            {
                name += currTransaction[j++];
            }
            j++;
            // Extracting time
            while(currTransaction[j] != ',')
            {
                time += currTransaction[j++];
            }
            j++;
            // Extracting amount
            while(currTransaction[j] != ',')
            {
                amount += currTransaction[j++];
            }
            j++;
            // Extracting city
            while((j < currTransaction.size()) && (currTransaction[j] != ','))
            {
                city += currTransaction[j++];
            }
            
            // Creating a new transaction object with the extracted information
            Transaction newTransaction(name, stoi(time), stoi(amount), city);
            inputTransactions.push_back(newTransaction);
        }

        // First check: transaction amount > 1000
        for(int i=0;i<inputTransactions.size(); i++)
        {
            if(inputTransactions[i].transactionAmount > 1000)
                isValid[i] = false;
        }
        // Second check, pair-wise
        for(int i=0;i<(inputTransactions.size()); i++)
        {
            for(int j=0; j<inputTransactions.size(); j++)
            {
                // We do not need to check a transaction against itself
                if(i == j)
                    continue;
                    int timeDiff = abs(inputTransactions[j].transactionTime - inputTransactions[i].transactionTime);
                if(timeDiff <= 60)
                {
                    if((inputTransactions[j].personName == inputTransactions[i].personName) && (inputTransactions[j].transactionCity != inputTransactions[i].transactionCity))
                    {
                    // If the above conditions are met, the transaction is invalid.
                    isValid[i] = false;
                    isValid[j] = false;
                    }
                }
            }
        }

         // Adding invalid transactions to the answer
        vector<string> invalidTransactions;
        for(int i=0;i<inputTransactions.size(); i++)
        {
            if(!isValid[i])
                invalidTransactions.push_back(transactions[i]);
        }
        return invalidTransactions;
    }
};