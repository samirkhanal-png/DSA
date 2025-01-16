class LRUCache {
public:
    list<int>dll;
    map<int,pair<list<int>::iterator,int>>mpp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    void makeMostRecentlyUsed(int key){
        dll.erase(mpp[key].first);//erase the key location
        dll.push_front(key);//O(1)
        //need to update the new location in the map so it is easy finding
        mpp[key].first=dll.begin();
    }
    
    int get(int key) {
       if(mpp.find(key)==mpp.end()){ //if key does not exist return -1
        return -1;
       }
       //if key exists
        makeMostRecentlyUsed(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){//if present already
            mpp[key].second=value;
            makeMostRecentlyUsed(key);
        }
        else{ //if not present already
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
        //if the capacity is exceeded then we delete from the back 
        if(dll.size()>=capacity){
            int elToBeDel=dll.back();
            mpp.erase(elToBeDel);//fully delete the least recently used key value from map and dll
            dll.pop_back();//delete the Least Recently Used item
        }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
