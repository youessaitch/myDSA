class MyCalendar {
    vector<pair<int, int>> intervals; // {start,end}
public:
    MyCalendar() {}

    bool book(int start, int end) {
        int l = 0;
        int r = intervals.size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            int s = intervals[mid].first;
            int e = intervals[mid].second;

            if(s<end && e>start) return false;

            if(start >= e){
                l = mid+1;
            }else if(end <= s){
                r = mid-1;
            }
        }

        intervals.insert(intervals.begin()+l,{start,end}); // No overlap, add interval
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */