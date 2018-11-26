//group anagrams together


#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string> > map;
    for(auto s : strs){
        string temp = s;
        sort(s.begin(), s.end());
        map[s].push_back(temp);
    }
    
    std::vector<std::vector<std::string> > result;
    for(auto s : map){
        result.push_back(s.second);
    }
    
    return result;
}