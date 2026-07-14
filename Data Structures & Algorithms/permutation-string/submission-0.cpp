class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()){
            return false; 
        }
        int length = 0;

        unordered_map<char , int> s1_count;
        unordered_map<char , int> s2_count;
        int left = 0;

        for (int i = 0 ; i < s1.size(); i++){
            s1_count[s1[i]]++;
            s2_count[s2[i]]++;
            length++;
        }

        if (s1_count == s2_count){
            return true; 
        }

        for (int right = s1.size(); right < s2.size(); right++){
            s2_count[s2[right]]++;
            length++;

            while(length > s1.size()){
                s2_count[s2[left]]--;

                if (s2_count[s2[left]] == 0){
                    s2_count.erase(s2[left]);
                }
                left++;
                length--;
                
            }

            if (s2_count == s1_count){
                return true;
            }
        }

        if (s2_count == s1_count){
                return true;
            }
        else{
            return false;
        }

        
    }
};
