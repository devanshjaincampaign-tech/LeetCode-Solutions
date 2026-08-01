class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>student;
        queue<int>sandwiche;

        for(int i=0;i<students.size();i++){
            student.push(students[i]);
            sandwiche.push(sandwiches[i]);
        }

        int failed_attempts=0;

        while(!sandwiche.empty() && failed_attempts!=student.size()){
            if(student.front()!=sandwiche.front()){
                int temp=student.front();
                student.pop();
                student.push(temp);
                failed_attempts++;
            }
            else{
                student.pop();
                sandwiche.pop();
                failed_attempts=0;
            }
        }
        return student.size();
    }
};