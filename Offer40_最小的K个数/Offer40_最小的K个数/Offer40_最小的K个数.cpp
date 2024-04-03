#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
    
public:

    std::vector<int> GetLeastNumbers_Solution(std::vector<int>& input, int k) {
        if (k == 0) {
            return {};
        }
        
        std::priority_queue<int, std::vector<int>, std::less<>> que;
        for (int i : input) {
            if (que.size() < k) {
                que.push(i);
            } else if (i <= que.top()) {
                que.pop();
                que.push(i);
            }
        }
        
        std::vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }

    std::vector<int> GetLeastNumbers_Solution2(std::vector<int>& input, int k) {
        if (k == 0) {
            return {};
        }
        
        std::vector<int> heap = ConstructHeap(input, k);
        for (int i = k; i < input.size(); ++i) {
            Push(heap, input[i]);
        }
        return heap;
    }

private:

    void Push(std::vector<int> &heap, int num) {
        if (num >= heap[0]) {
            return;
        }

        heap[0] = num;
        Traversal(heap, 0);
    }

    void Traversal(std::vector<int> &heap, int node) {
        int left = 2*node+1, right = 2*node+2;
        if (left < heap.size() && heap[left] > heap[node]) {
            std::swap(heap[left], heap[node]);
            Traversal(heap, left);
        }
        if (right < heap.size() && heap[right] > heap[node]) {
            std::swap(heap[right], heap[node]);
            Traversal(heap, right);
        }
    }

    std::vector<int> ConstructHeap(const std::vector<int>& input, int k) {
        std::vector<int> heap;
        for (int i = 0; i < k; ++i) {
            heap.push_back(input[i]);
        }

        for (int i = k/2-1; i >= 0; --i) {
            Traversal(heap, i);
        }
        return heap;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> input{4,5,1,6,2,7,3,8};
    int k = 7;
    Solution sol;
    sol.GetLeastNumbers_Solution2(input, k);
    
    return 0;
}
