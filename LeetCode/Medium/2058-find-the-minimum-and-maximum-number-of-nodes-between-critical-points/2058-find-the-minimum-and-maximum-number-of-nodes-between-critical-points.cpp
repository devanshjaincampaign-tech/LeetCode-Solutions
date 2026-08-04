class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextnode = curr->next;

        int firstIdx = -1;
        int prevIdx = -1;
        int minDistance = INT_MAX;
        int currentIndex = 1;

        while (nextnode != nullptr) {
            if ((curr->val > prev->val && curr->val > nextnode->val) ||
                (curr->val < prev->val && curr->val < nextnode->val)) {
                
                if (firstIdx == -1) {
                    firstIdx = currentIndex;
                } else {
                    minDistance = min(minDistance, currentIndex - prevIdx);
                }
                prevIdx = currentIndex;
            }

            prev = curr;
            curr = nextnode;
            nextnode = nextnode->next;
            currentIndex++;
        }

        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = prevIdx - firstIdx;
        return {minDistance, maxDistance};
    }
};