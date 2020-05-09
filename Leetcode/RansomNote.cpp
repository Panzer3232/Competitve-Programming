  class Solution {
    public:
        bool canConstruct(string ransomNote, string magzine) {
            if(ransomNote.empty())
                return true;
            if(magzine.empty())
                return false;
            int collection[26]={0};
            for(const auto & c:magzine)
                collection[c-'a']++;
            for(const auto& c : ransomNote){
          collection[c-'a']--;
          if(collection[c-'a']<0) return false;
        }
           return true;
        }
    };