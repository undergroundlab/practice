#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Meeting{
    private:
        int start;
        int end;
    public:
        Meeting(int st, int en) : start(st), end(en){};
        void setStart(int st) {start = st;};
        void setEnd(int en) {end = en;};
        int getStart() {return start;};
        int getEnd() {return end;};
};


void print(vector<Meeting> m){
    for(int i=0; i < m.size(); i++){
        cout << "(" << m[i].getStart() << "," << m[i].getEnd() << ") ";
    }
    cout << endl;
}

//used for sorting
bool compareMeeting(Meeting a, Meeting b){
    return (a.getStart() < b.getStart());
}


vector<Meeting> mergeRange(vector<Meeting> meetings){
    if(meetings.empty()) return meetings;
    
    vector<Meeting> result;
    sort(meetings.begin(), meetings.end(), compareMeeting);
    
    result.push_back(meetings[0]);
    
    for(int i=1; i < meetings.size(); i++){
        //meeting overlaps, merge with prev meeting
        if(result.back().getEnd() >= meetings[i].getStart()){
            if(result.back().getEnd() < meetings[i].getEnd())
                result.back().setEnd(meetings[i].getEnd());
        }
        //meeting doesn't overlap, add to list
        else{
            result.push_back(meetings[i]);
        }
    }
    
    return result;
}


int main() {
    vector<Meeting> meetings = {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8),
                                Meeting(10, 12), Meeting(9, 10), Meeting(14, 15)};
    print(meetings);

    vector<Meeting> result = mergeRange(meetings);
    print(result);
    
    return 0;
}
