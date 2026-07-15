class Solution {
public:
    string minWindow(string s, string t) {
        string minimum = s + "a";
        unordered_map<char, int> count;
        unordered_map<char , int> t_count;
        int left = 0;


        //count for t
        for (int i = 0 ; i < t.size(); i++){
            t_count[t[i]]++;
        }

        // FOR THE MAIN SLIDING WINDOW 
        for (int right = 0 ; right < s.size(); right++){
            count[s[right]]++;

            bool isContained = true;
            for (auto& [key , val] : t_count){
                if (count.find(key) == count.end() || count.at(key) < val){
                    isContained = false;
                }
            }
            while (isContained){
                if (minimum.size() > (right - left + 1 )){
                    minimum = s.substr(left , (right - left + 1));
                }
                count[s[left]]--;
                if (count[s[left]] == 0){
                    count.erase(s[left]);
                }
                left++;
                for (auto& [key , val] : t_count){
                if (count.find(key) == count.end() || count.at(key) < val){
                    isContained = false;
                }

            }

        }
        
        
        }

        if (minimum.size() < (s.size() + 1)) {
            return minimum;

        }
        else{
            return "";

        }

    }
};