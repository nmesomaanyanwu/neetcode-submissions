class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count = {};
        int left = 0;
        int res = 0;

        for (int right = 0 ; right < s.size(); right++){

            // add the count to the hashmap 
            count[s[right]]++;
            vector<int> frequency{};
            int max_element = 0;

            for (auto& pair : count){
                max_element = max(max_element, pair.second);
            } 


            while (((right - left + 1) - max_element) > k){
                count[s[left]]--;
                left++;
            }




            res = max(res , right - left + 1);
        }

        return res;

        
    }
};
