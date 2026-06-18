class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = hour * 30 + minutes * 0.5;
        while(hr > 360) hr = hr - 360;
        double mn = minutes * 6;

        double diff = abs(mn - hr);
        diff = min(diff, 360 - diff);
        return diff;
    }
};