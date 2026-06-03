class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title="";
        while(columnNumber>0){
            columnNumber--;
            
            char remainderchar=(columnNumber%26)+'A';

            title=title+remainderchar;
            columnNumber=columnNumber/26;
        }

        reverse(title.begin(),title.end());
        return title;
    }
};