#include <sstream>
#include <vector>
#include <string>

class Solution {
public:

    

    string encode(vector<string>& strs) {
        string en;
        for (int i = 0 ; i < strs.size(); i++){
            string len = to_string(strs[i].size());
            en = en + len + '#'+ strs[i];
        }

        return en;
    }

    vector<string> decode(string s) {
        
        int i = 0;
        vector<string> res;

        while(i < s.size()){
            int j = i;
            while(s[j] != '#' ){
                j+=1;
                
            }
            string siz = s.substr(i , j - i);
            int size = stoi(siz);
           

            res.push_back(s.substr(j+1,size));
            i = j+1+ size;
         
        }
    
        return res;
    }

};
