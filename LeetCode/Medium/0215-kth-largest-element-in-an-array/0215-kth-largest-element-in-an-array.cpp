class Solution {
private:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return (2 * i) + 1; }
    int right(int i)  { return (2 * i) + 2; }
    
    void heapify(vector<int>& heap, int index, int size) {
        int smallest = index;
        int l = left(index);
        int r = right(index);

        if (l < size && heap[l] < heap[smallest]) {
            smallest = l;
        }

        if (r < size && heap[r] < heap[smallest]) {
            smallest = r;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify(heap, smallest, size);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = (k / 2) - 1; i >= 0; i--) {
            heapify(nums, i, k);
        }

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                nums[0] = nums[i];
                heapify(nums, 0, k);
            }
        }

        return nums[0];
    }
};