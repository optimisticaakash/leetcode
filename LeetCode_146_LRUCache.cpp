//Approach1 : using vector
class LRUCache {
public:
    vector<pair<int,int>> cache;
    int n;
    LRUCache(int capacity) {
        n= capacity;
    }
    
    int get(int key) {
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                int val = cache[i].second;

                pair<int,int> temp = cache[i];

                cache.erase(cache.begin()+ i);//cache[i] ko vector se erase kr denge
                cache.push_back(temp);//abhi recently use kiya cache[i] ko last me bhej denge taki phle na delete ho 

                return val;
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < cache.size();i++){
            if(cache[i].first == key){
                //isko update krna padega
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});//update krke last me push kr denge , abhi use hua to bad me delete hoga phle nhi 

                return ;
            }
        }

        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key,value});
        }else{
            cache.push_back({key,value});
        }
    }
};

//T.C : O(N) get and put
//S.c : O(capacity)

//Approach2 : using c++ doubly linkedlist
class LRUCache {
public:
    list<int> dll; 
    //map<int,pair<Address , int>> mp;
    map<int,pair<list<int>::iterator,int>> mp;

    int n ;

    LRUCache(int capacity) {
        n = capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);//address bhej ke linkedlist se erase kr diya

        dll.push_front(key);
        mp[key].first = dll.begin();//map me address update krenge

    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        makeRecentlyUsed(key);//ye linkedlist ke front me recentlyUsed ko krdega

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;

            makeRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
            n--;
        }

        if(n < 0){//extra element dal diye to back se delete krenge
            int key_to_deleted = dll.back();
            mp.erase(key_to_deleted);

            dll.pop_back();

            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//T.c : O(logN) because map taked lognN in insertion and deletion
//S.C :O(2N) map and list me har key store ho rhi hai 

//Approach2 : implement doubly linkedlist 

class LRUCache {
public:
    list<int> dll; 
    //map<int,pair<Address , int>> mp;
    unordered_map<int,pair<list<int>::iterator,int>> mp;

    int n ;

    LRUCache(int capacity) {
        n = capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);//address bhej ke linkedlist se erase kr diya

        dll.push_front(key);
        mp[key].first = dll.begin();//map me address update krenge

    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        makeRecentlyUsed(key);//ye linkedlist ke front me recentlyUsed ko krdega

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;

            makeRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
            n--;
        }

        if(n < 0){//extra element dal diye to back se delete krenge
            int key_to_deleted = dll.back();
            mp.erase(key_to_deleted);

            dll.pop_back();

            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//T.c :O(1) unordered_map
//S.C :O(N) for map
