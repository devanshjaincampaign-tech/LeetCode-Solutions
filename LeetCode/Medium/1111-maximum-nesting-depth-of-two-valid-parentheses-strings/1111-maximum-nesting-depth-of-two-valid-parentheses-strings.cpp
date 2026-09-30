class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> answer(seq.length());
        for (int i = 0; i < seq.length(); ++i) {
            answer[i] = (seq[i] == '(') ? (i & 1) : ((i + 1) & 1);
        }
        return answer;
    }
};