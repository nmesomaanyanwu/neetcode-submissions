class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        /*
        okay so lets  start with  making an unordered_map<char , vector<char>>
        we have another map to track its states 
        we add to the string if  we have we chcked its neighbours and them update the map state to be 2
        */
        int n = words.size();
        unordered_map<char , vector<char>> dict;

        auto found = [&](auto&& self , char key, char value) -> bool{
            auto it = find(dict[key].begin(), dict[key].end(), value);

            if (it != dict[key].end()) return true;
            return false;
        };

        for (auto& w : words)
            for (char c : w) dict[c];  
    

        // now we make our adj map
        for (int i = 1 ; i < n ; i++){
            string a = words[i - 1];
            string b = words[i];
            int m = min(a.size() , b.size());
            // check for if this is impossible where a size > b and a.substr == b
            if (a.size() > m && a.substr(0 , m) == b) return "";// its impossible 
            // we check for the first cut between the current letters 
            for (int j = 0 ;  j < m ; j++){
                if (a[j] != b[j]){
                    if (!found(found, a[j], b[j])){
                        dict[a[j]].push_back(b[j]);
                    }
                    break;
                }
            }
        }
        // now we want to make a map for chkin the states of each letter 
        unordered_map<char , int> state; // 0 - unvisited , 1 - current path , 2 - completed;
        string path;

        auto dfs = [&](auto&& self , char key) -> bool{
            if (state[key] == 1) return false; // on current path
            if (state[key] == 2) return true ; // already been completed

            state[key] = 1;

            for (auto nei : dict[key]){
                if (!self(self , nei)) return false;
            }
            
            state[key] = 2;
            path += key;
            return true;
        };

        for (auto [n , _] : dict){
            dfs(dfs , n);
        }

        reverse(path.begin() , path.end());

        return path;

    }
};
