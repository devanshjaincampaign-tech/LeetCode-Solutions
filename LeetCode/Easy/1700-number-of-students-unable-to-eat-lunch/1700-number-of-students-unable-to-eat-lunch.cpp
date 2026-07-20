class Solution {
private:
    void sendstudentback(vector<int>& students) {
        if (students.empty()) return;
        
     
        int first = students[0];
        for (int i = 0; i < students.size() - 1; i++) {
            students[i] = students[i + 1];
        }
        students.back() = first;
    }

public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int rotations = 0;
        
        while (!sandwiches.empty() && rotations < students.size()) {
            if (students[0] == sandwiches[0]) {
                
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                rotations = 0; 
            } 
            else {
                sendstudentback(students);
                rotations++;
            }
        }
        
        return students.size();
    }
};