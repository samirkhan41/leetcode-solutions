
class Solution {
public:
    double angleClock(int hour, int minutes) {

        // Minute hand angle
        double minuteAngle = minutes * 6;

        // Hour hand angle
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;

        // Difference between both angles
        double diff = abs(hourAngle - minuteAngle);

        // Return smaller angle
        return min(diff, 360.0 - diff);
    }
};
