class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        priority_queue<pair<int,string>>pq;
        vector<string>res;
        for(auto x : words){
            auto it = mp.find(x);
            if(it == mp.end()){
                mp.insert({x,1});
            }else{
                it->second++;
            }
        }
        for(auto x : words){
            auto it = mp.find(x);
            if(it != mp.end()){
                pq.push({it->second,it->first});
                mp.erase(it);
            }
        }
        int prev = pq.top().first;
        vector<string>aux;
        aux.push_back(pq.top().second);
        pq.pop();
        int p = k;
        while(!pq.empty()){
           if(pq.top().first == prev){
               aux.push_back(pq.top().second);
           }else{
               sort(aux.begin(),aux.end());
               for(int i=0;i<aux.size();i++)
                   res.push_back(aux[i]);
               aux.clear();
               aux.push_back(pq.top().second);
               prev = pq.top().first;
           }
            pq.pop();
           
        }
        sort(aux.begin(),aux.end());
        for(auto x : aux)
            res.push_back(x);
        
        res.resize(p);
        return res;
    }
};