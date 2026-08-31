class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int first_cp = -1;
        int prev_cp = -1;
        int min_dist = INT_MAX;
        int curr_idx = 1; // 0-based index for curr (or 1-based, relative distance remains identical)

        while (curr->next != nullptr) {
            ListNode* next_node = curr->next;

            bool is_local_max = (curr->val > prev->val) && (curr->val > next_node->val);
            bool is_local_min = (curr->val < prev->val) && (curr->val < next_node->val);

            if (is_local_max || is_local_min) {
                if (first_cp == -1) {
                    first_cp = curr_idx;
                } else {
                    min_dist = min(min_dist, curr_idx - prev_cp);
                }
                prev_cp = curr_idx;
            }

            prev = curr;
            curr = next_node;
            curr_idx++;
        }

        // If fewer than 2 critical points were found
        if (first_cp == -1 || first_cp == prev_cp) {
            return {-1, -1};
        }

        int max_dist = prev_cp - first_cp;
        return {min_dist, max_dist};
    }
};