class Solution {
public:
    string intToRoman(int num) {
        int count = 0;
        int x = num;
        string nums = "";
        
        while (x != 0) {
            count++;
            x = x / 10;
        }
        
        if (count == 4) {
            int a = num / 1000;
            while (a != 0) {
                nums += "M";
                a = a - 1;
            }
            count = count - 1;
            num = num % 1000;
        }

        if (count == 3) {
            int b = num / 100;
            if (b <= 3) {
                while (b != 0) {
                    nums += "C";
                    b = b - 1;
                }
            }
            else if (b == 4) {
                nums += "CD";
            }
            else if (b == 5) {
                nums += "D";
            }
            else if (b > 5 && b <= 8) {
                nums += "D";
                while (b != 5) {
                    nums += "C";
                    b = b - 1;
                }
            }
            else if (b == 9) {
                nums += "CM";
            }
            count = count - 1;
            num = num % 100;
        }
        
        if (count == 2) {
            int c = num / 10;
            if (c <= 3) {
                while (c != 0) {
                    nums += "X";
                    c = c - 1;
                }
            }
            else if (c == 4) {
                nums += "XL";
            }
            else if (c == 5) {
                nums += "L";
            }
            else if (c > 5 && c <= 8) {
                nums += "L"; // Fixed typo from 'C' to 'L'
                while (c != 5) {
                    nums += "X";
                    c = c - 1;
                }
            }
            else if (c == 9) {
                nums += "XC";
            }
            count = count - 1;
            num = num % 10;
        }
        
        if (count == 1) {
            int d = num;
            if (d <= 3) {
                while (d != 0) {
                    nums += "I";
                    d = d - 1;
                }
            }
            else if (d == 4) {
                nums += "IV";
            }
            else if (d == 5) {
                nums += "V";
            }
            else if (d > 5 && d <= 8) {
                nums += "V";
                while (d != 5) {
                    nums += "I";
                    d = d - 1;
                }
            }
            else if (d == 9) {
                nums += "IX";
            }
        }
        
        return nums;
    }
};