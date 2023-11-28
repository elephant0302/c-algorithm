#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct e {
    int pos;
    int index;
    bool begin;
    bool theend;
};

struct interval {
    int start, end;
    bool eend;
    int intersects;
};

bool comparison(const e& a, const e& b) {
    if (a.pos != b.pos)
        return a.pos < b.pos;
    if (a.begin != b.begin)
        return a.begin;
    if (a.begin)
        return a.theend > b.theend;
    return a.theend < b.theend;
}

bool intersects(const interval& a, const interval& b) {
    if (a.eend && b.eend)
        return a.start <= b.end && b.start <= a.end;
    if (!a.eend && !b.eend)
        return a.start < b.end && b.start < a.end;
    return a.start < b.end && b.start < a.end;
}

int main() {
    int n;
    cin >> n;
    vector<e> events;
    vector<interval> intervals(n);

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> intervals[i].start >> intervals[i].end >> t;
        intervals[i].eend = (t == 1);
        events.push_back({ intervals[i].start, i, true, intervals[i].eend });
        events.push_back({ intervals[i].end, i, false, intervals[i].eend });
        intervals[i].intersects = 0;
    }

    sort(events.begin(), events.end(), comparison);

    vector<int> active;

    for (const auto& event : events) {
        if (event.begin) {
            for (int ai : active) {
                if (intersects(intervals[ai], intervals[event.index])) {
                    intervals[ai].intersects++;
                    intervals[event.index].intersects++;
                }
            }
            active.push_back(event.index);
        }
        else {
            active.erase(remove(active.begin(), active.end(), event.index), active.end());
        }
    }

    vector<int> results;
    for (const auto& interval : intervals) {
        results.push_back(interval.intersects);
    }

    sort(results.rbegin(), results.rend());

    for (int res : results) {
        cout << res << ' ';
    }
    cout << endl;

    return 0;
}
