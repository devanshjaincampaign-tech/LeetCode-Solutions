class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        string firsthalf = "";
        int questionmarkinfirsthalf = 0;
        for (int i = 0; i < n / 2; i++) {
            firsthalf += num[i];
            if (num[i] == '?') {
                questionmarkinfirsthalf++;
            }
        }
        string secondhalf = "";
        int questionmarkinsecondhalf = 0;
        for (int i = n / 2; i < n; i++) {
            secondhalf += num[i];
            if (num[i] == '?') {
                questionmarkinsecondhalf++;
            }
        }

        int sumfirsthalf = 0;
        int sumsecondhalf = 0;

        for (char i : firsthalf) {
            if (i >= '0' && i <= '9') {
                sumfirsthalf += i - '0';
            }
        }

        for (char i : secondhalf) {
            if (i >= '0' && i <= '9') {
                sumsecondhalf += i - '0';
            }
        }

        if ((questionmarkinfirsthalf + questionmarkinsecondhalf) % 2 != 0) {
            return true;
        }

        return (sumfirsthalf - sumsecondhalf) * 2 != (questionmarkinsecondhalf - questionmarkinfirsthalf) * 9;
    }
};