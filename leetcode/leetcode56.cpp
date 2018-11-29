//merge intervals
//merge all overlapping intervals

#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare (const Interval& i1, const Interval& i2){
    return i1.start < i2.start;
}

//sort by start index
//then merge one by one to the result list
std::vector<Interval> merge(std::vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);

    std::vector<Interval> mergedList;
    for(auto interval : intervals){

        if(mergedList.empty() || mergedList[mergedList.size()-1].end < interval.start){
            mergedList.push_back(interval);
        }
        else{
            mergedList[mergedList.size()-1].end = std::max(mergedList[mergedList.size()-1].end, interval.end);
        }
    }

    return mergedList;
}
