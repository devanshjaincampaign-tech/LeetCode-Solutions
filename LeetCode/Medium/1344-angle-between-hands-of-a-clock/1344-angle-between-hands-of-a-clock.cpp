class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteangle=minutes*6.0;
        double hourangle=(hour%12)*30.0+minutes*0.5;
        double difference =abs(hourangle-minuteangle);

        return min(difference,360-difference);
    }
};