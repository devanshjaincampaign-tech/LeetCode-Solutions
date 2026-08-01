class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push({i, tickets[i]});
        }

        int time = 0;

        while (!q.empty()) {
            auto [index, count] = q.front();
            q.pop();

            count--;
            time++;

            if (index == k && count == 0) {
                return time;
            }

            if (count > 0) {
                q.push({index, count});
            }
        }

        return time;
    }
};