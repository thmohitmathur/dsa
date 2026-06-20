class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        int l;
    }
    
    void set(string key, string value, int timestamp) {
        pair<string, int> temp = {value, timestamp};
        mp[key].push_back(temp);
    }
    
    string get(string key, int timestamp) {

        string ans = "";
        if(mp.find(key) != mp.end()){
            auto &vec = mp[key];
            int l = 0;
            int r = vec.size()-1;
            while(l <= r){
                int mid = l + (r-l)/2;

                if(vec[mid].second <= timestamp){
                    ans = vec[mid].first;
                    l = mid + 1;
                }else{
                    r = mid-1;
                }
            }

        }
        return ans;

    }

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
