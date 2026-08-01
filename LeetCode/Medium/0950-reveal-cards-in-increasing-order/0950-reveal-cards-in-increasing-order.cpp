class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> result(n);
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        for (int card : deck) {
            result[q.front()] = card;
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};