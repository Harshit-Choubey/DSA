class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 2, first = -1, last = -1, mn = INT_MAX;

        ListNode *prev = head, *cur = head->next;

        while (cur->next) {
            ListNode *next = cur->next;

            if ((cur->val > prev->val && cur->val > next->val) ||
                (cur->val < prev->val && cur->val < next->val)) {

                if (first == -1)
                    first = pos;
                else
                    mn = min(mn, pos - last);

                last = pos;
            }

            prev = cur;
            cur = next;
            pos++;
        }

        if (first == -1 || first == last)
            return {-1, -1};

        return {mn, last - first};
    }
};