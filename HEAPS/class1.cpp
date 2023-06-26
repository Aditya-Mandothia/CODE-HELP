#include<bits/stdc++.h>
using namespace std;

class Heap{

    public:
    int arr[101];
    int size;

    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while ( index > 1)
        {
            int parentIndex = index/2;

            if(arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex] , arr[index]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }
};


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class compare {
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class node{
    public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};
 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> minHeap;
        int k = nums.size();
        for(int i=0; i<k; i++) {
            int element = nums[i][0];
            maxi = max( maxi, element);
            mini = min(mini, element);
            minHeap.push(new node(element, i, 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;


        while(!minHeap.empty()) {
            
            node* top = minHeap.top();
            int topelement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            //mini updated
            mini = topelement;

            //check for answer
            int currRange = maxi-mini;
            int ansRange = ansEnd - ansStart;
            if(currRange < ansRange) {
                ansStart = mini;
                ansEnd = maxi;
            }

            //check for new element in the same list
            if(topCol + 1 < nums[topRow].size()) {
                maxi = max( maxi , nums[topRow][topCol+1]);
                node* newNode = new node(nums[topRow][topCol+1], topRow, topCol+1);
                minHeap.push(newNode);
            }
            else {
                //there is no element int the same array or list
                break;
            }
        }

        vector<int> ans ;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;




    }
};








class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if(k == 0) 
            return NULL;

        //first element of every blinked list ko insert krdo heap me 
        for(int i=0; i<k; i++) {
            if(lists[i] != NULL ) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();

            //temp may or may not be the first element of answer linked list 
            if(head == NULL) {
                //temp -> first element of ans LL
                head = temp;
                tail = temp;
                if(tail->next != NULL) {
                    minHeap.push(tail->next);
                }

            }
            else {
                //temp isnnot the first element of LL
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL) {
                    minHeap.push(tail->next);
                }
            }
        }
    return head;
    }
};










int main()
{
    Heap h;
    h.arr[0] = -1;



return 0;
}