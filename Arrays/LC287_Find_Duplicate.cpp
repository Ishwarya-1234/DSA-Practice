class Solution {
public:
    int findDuplicate(vector<int>& arr) {

        int slow = arr[0];
        int fast = arr[0];

        do {
            slow = arr[slow];           // +1 step
            fast = arr[arr[fast]];      // +2 steps
        } while (slow != fast);

        slow = arr[0];

        while (slow != fast) {
            slow = arr[slow];           // +1 step
            fast = arr[fast];           // +1 step
        }

        return slow;
    }
};
