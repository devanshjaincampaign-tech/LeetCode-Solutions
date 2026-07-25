class Solution {
public:
    string decodeString(string s) {
        stack<int> numbers;
        stack<string> strings;
        int currnumber = 0;
        string currstring = "";

        for (char x : s) {
            if (x >= '0' && x <= '9') {
                currnumber = currnumber * 10 + (x - '0');
            } 
            else if (x == '[') {
                numbers.push(currnumber);
                strings.push(currstring);
                currnumber = 0;
                currstring = "";
            } 
            else if (x == ']') {
                int repeat = numbers.top();
                numbers.pop();
                
                string prevstring = strings.top();
                strings.pop();

                string repeatstring = "";
                for (int i = 0; i < repeat; i++) {
                    repeatstring += currstring;
                }

                currstring = prevstring + repeatstring;
            } 
            else {
                currstring += x;
            }
        }
        return currstring;
    }
};