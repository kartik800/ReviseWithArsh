class StockPrice {
public:
    map<int,int> mp;
    multiset<int> mset;
    int time = 0;
    int curr = 0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timestamp >=time){
            time = timestamp;
            curr = price;
        }
        if(mp.find(timestamp) == mp.end()){
            mp.insert({timestamp, price});
            mset.insert(price);
        }else{
            auto it = mset.find(mp[timestamp]);
            mset.erase(it);
            mp[timestamp] = price;
            mset.insert(price);
        }
        
    }
    
    int current() {
        return curr;
        
    }
    
    int maximum() {
        return *(mset.rbegin());
        
    }
    
    int minimum() {
        return *(mset.begin());
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */