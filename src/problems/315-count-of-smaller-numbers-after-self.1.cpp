class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;
        int size = 2 * 1e4 + 1;
        vector<int> tree(size * 2);
        vector<int> result(nums.size());
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = query(0, nums[i] + offset, tree, size);
            update(nums[i] + offset, 1, tree, size);
        }
        return result;
    }
    
    void update(int index, int value, vector<int>& tree, int size) {
        index += size;
        tree[index] += value;
        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }
    
    int query(int left, int right, vector<int>& tree, int size) {
        int result = 0;
        left += size;
        right += size;
        while (left < right) {
            if (left % 2 == 1) {
                result += tree[left];
                left++;
            }
            left /= 2;
            
            if (right % 2 == 1) {
                right--;
                result += tree[right];
            }
            right /= 2;
        }
        return result;
    }
};
