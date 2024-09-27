class MyCalendarTwo {
    vector<pair<int, int>> doubleBooking; // {start,end}
    vector<pair<int, int>> booking; // {start,end}
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // find if overlapping: max(s1,s2) < min(e1,e2) then overlapping
        // overlapping interval: {max(s1,s2),min(e1,e2)}

        for(auto it: doubleBooking){
            int pehla = it.first;
            int dusra = it.second;

            if(max(start,pehla) < min(dusra,end)) return false; //overlapping so triple booking jo ki nhi chaiye mereko
        }

        for(auto it: booking){
            int pehla = it.first;
            int dusra = it.second;

            if(max(start,pehla) < min(dusra,end)){
                doubleBooking.push_back({max(pehla,start),min(dusra,end)});
            }
        }

        booking.push_back({start,end});

        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */