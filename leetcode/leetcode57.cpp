//insert an interval into sorted intervals (sorted by start index)
// similar to 56

#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
    if(intervals.empty()){
        intervals.push_back(newInterval);
        return intervals;
    }
    std::vector<Interval> mergedList;
    bool inserted = false;
    
    if(newInterval.start < intervals[0].start){
        mergedList.push_back(newInterval);
        inserted = true;
    }
    
    for(int i=0; i<intervals.size(); i++){
        if(mergedList.empty() || mergedList[mergedList.size()-1].end < intervals[i].start){
            mergedList.push_back(intervals[i]);
        }
        else{
            mergedList[mergedList.size()-1].end = std::max(mergedList[mergedList.size()-1].end, intervals[i].end);
        }
        
        //check if it is the right time to insert to mergedList
        if(i != intervals.size()-1 && newInterval.start > intervals[i+1].start){
            continue;
        }
        
        //right place to merge to mergedList
        if(newInterval.start >= mergedList[mergedList.size()-1].start && !inserted){
            if(mergedList[mergedList.size()-1].end < newInterval.start){
                mergedList.push_back(newInterval);
            }
            else{
                mergedList[mergedList.size()-1].end = std::max(mergedList[mergedList.size()-1].end, newInterval.end);
            }
            inserted = true;
        }
    }

    return mergedList;
}