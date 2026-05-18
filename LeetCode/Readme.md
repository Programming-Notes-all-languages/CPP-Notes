# LeetCode Interview Prep

SWE internship interview preparation. Mastering 22 core problems across fundamental data structures and algorithms.

---

## Arrays & Strings (3 problems)

### 1. Two Sum
**Link:** https://leetcode.com/problems/two-sum/

**Solution:**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //map to store each unique element in the vector, with the key being the index in which the element takes in the vector
        unordered_map<int, vector<int>> numbers;
        //vector which will return the indices of what we want
        vector<int> returnVec;
        //temporary variable that will be used to help find what number in the vector we are looking for
        int needed;

        //looping through the vector and adding each unique element to the map, pushing back each index
        for (int i = 0; i < nums.size(); i++)
            numbers[nums[i]].push_back(i);
        
        //instantiating an iterator which is needed to iterate through the map
        auto it = numbers.begin();

        //iterating through the map to find our two values that sum to our target
        for (; it != numbers.end(); it++)
        {
            //given the current key, the key we are looking for is the result of target minus the first the current key
            needed = target - it->first;

            //now that we know what key we are looking for, we can use the find method and see if the key exists
            if (numbers.find(needed) != numbers.end())
            {
                //the key will always exist since it is finding itself, so we need to check if the number of elements in the vector is more than one. this means we are essentially looking to see if both keys are equal
                if (needed == it->first)
                {
                    //checking to see if both the current key the iterator is at 
                    if (it->second.size() > 1)
                    {
                        //pushing back the indices onto the vector to be returned
                        returnVec.push_back(it->second[0]);
                        returnVec.push_back(it->second[1]);
                        break;
                    }
                }

                //condition where the needed key and the key being looked at with the iterator are different, but add to the target
                else
                {
                    //pushing back the indices onto the vector to be returned
                    returnVec.push_back(numbers[needed][0]);
                    returnVec.push_back(it->second[0]);
                    break;
                }
            }
        }

        return returnVec;
    }
};
```

---

### 2. Best Time to Buy and Sell Stock
**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

**Solution:**
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //variables to store the absolute lowest price to buy stock, the maximum amount of profit that could have been earned, and the profit that could be made on the current iteration through the vector
        int minPrice = prices[0], maxProfit = 0, profit;

        //checking if the vector is empty; if so, no profit can be made
        if (prices.empty()) return 0;

        //starting on day 1, check to see how much profit can be made by iterating through the vector
        for (int i = 1; i < prices.size(); i++)
        {
            //first check if the stock at day index i is the cheapest the stock can be bought for so far; if so, update the current minimum price
            if (prices[i] < minPrice)
                minPrice = prices[i];

            //otherwise, if the stock value at index i is not the all time low, we are going to calculate how much profit could be made
            else
            {
                //given the profit today is higher than the cheapest the stock ever sold for, the profit that could be made is found by taking index i's stock price and subtracting the absolute minimum price from it
                profit = prices[i] - minPrice;

                //if today's profit is greater than all other prior profits, then we will update the max profit and see if we can make even more money on a future day
                if (profit > maxProfit)
                    maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
```

---

### 3. Valid Palindrome
**Link:** https://leetcode.com/problems/valid-palindrome/

**Solution:**
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        //checking if the string is empty; if so, the string is a palindrome
        if (s.empty()) return true;

        //creating two pointers: one which points to the head of the string, and the other which points at the last character in the string
        char *ptrF = &s[0], *ptrE = &s[s.size() - 1];

        //iterating through the string and converting each uppercase letter into a lowercase letter
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = tolower(s[i]);

        //using pointers to traverse the characters of the string from both the front end and at the tail
        for (; ptrF < ptrE;)
        {
            //if the character that the first pointer is pointing at is not valid, we are going to skip this character and move onto the next character after this character in the string
            if (!(*ptrF >= 'a' && *ptrF <= 'z' || *ptrF >= '0' && *ptrF <= '9'))
            {
                ptrF++;
                continue;
            }
                
            //if the character that the second pointer is pointing at is not valid, we are going to skip this character and move ont character backwards, closer to the front of the string
            if (!(*ptrE >= 'a' && *ptrE <= 'z' || *ptrE >= '0' && *ptrE <= '9'))
            {
                ptrE--;
                continue;
            }
            
            //if both characters the two pointers are pointing at are valid, but are not equal to each other, the string is not a palindrome
            if (*ptrF != *ptrE)
                return false;
            
            //otherwise if both characters at each end of the string match, the move one character closer on each side of the string to the center character
            ptrF++;
            ptrE--;
        }

        return true;
    }
};
```
---

## Linked Lists (4 problems)

### 4. Reverse Linked List
**Link:** https://leetcode.com/problems/reverse-linked-list/

**Solution:**
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //variables for storing the node just before the current node, a current node which initially points to head, and a temp node which will point to one node after current
        ListNode *prev = nullptr, *curr = head, *temp = head;

        //so essentially we are turning one linked list into two linked list, where current will point to the prior node and then the node after current will point to the rest of the unprocessed linked list
        while (curr != nullptr)
        {
            //temp will now point to the node just after current
            temp = curr->next;
            //the current pointer's next attribute points to prev, which for the first instance is nullptr rather than curr->next
            curr->next = prev;

            //the prior node is now the current node as we move one node to the right
            prev = curr;
            //the current node is now the node one after current since we are moving one node to the right
            curr = temp;
        }

        return prev;
    }
};
```

---

### 5. Merge Two Sorted Lists
**Link:** https://leetcode.com/problems/merge-two-sorted-lists/

**Solution:**
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //creating a new linked list called final, which will store the merged linked list, and creating a dummy pointer curr to point to the head of this new linked list
        ListNode *final = new ListNode(0), *curr = final;

        //moving through both linked lists until either list1 or list2 reaches nullptr
        while (list1 != nullptr && list2 != nullptr)
        {
            //instantiating a new linked list node for the linked list to be return from this function
            ListNode *newNode = new ListNode();

            //if the current node in the first list has a lower val attribute than the other node in the second list, we are going to copy this new node's value into our newly created node, then move list1 to point to the next element
            if (list1->val <= list2->val)
            {
                newNode->val = list1->val;
                list1 = list1->next;
            }

            //if the current node in the second list has a lower val attribute than the other node in the list list, we are going to copy this new node's value into our newly created node, then move list2 to point to the next element
            else
            {
                newNode->val = list2->val;
                list2 = list2->next;
            }

            //now we need have the curr pointer's next attribute point to this new list element, then set current to point to its next element, also known as newNode
            curr->next = newNode;
            curr = curr->next;
        }

        //now there is a chance that the number of elements in each list is different. what this means for us is when the shorter linked list reaches nullptr first, the while loop above will terminate; however, there are still element(s) in the other list that need to be merged to our newly created list. the two conditions below evaluate which list still has remaining elements, and sets the next pointer after curr to point to the remaining list elements from either list1 or list2
        if (list1 == nullptr && list2 != nullptr)
            curr->next = list2;
        else if (list2 == nullptr && list1 != nullptr)
            curr->next = list1;

        //we return the second node in the linked list since the first node we instantiated at the start of this method is a dummy value containing just zero. the head of the node being return is this second node, our first valid node for our merged linked list
        return final->next;
    }
};
```

---

### 6. Linked List Cycle
**Link:** https://leetcode.com/problems/linked-list-cycle/

**Solution:**
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //creating a set to store each unique list element
        unordered_set<ListNode *> seen;

        //traversing the linked list until either we stumble upon a node that has already been visited or we reach the end of the linked list successfully
        for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            //the count method is used to determine if an element in a set already exists. it returns a boolean value indicating that and if the element has been seen, we are going to return true and say the linked list is cyclical
            if (seen.count(ptr))
                return true;
            
            //if the current list node has not been seen yet, we are going to add it to the set
            seen.insert(ptr);
        }

        //if we get to this line in the method, then no cycle was found in the for loop above and hence we will return false
        return false;
    }
};
```

---

### 7. Remove Nth Node From End of List
**Link:** https://leetcode.com/problems/remove-nth-node-from-end-of-list/

**Solution:**
```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //creating a dummy pointer to traverse through the linked list and a variable for storing the number of nodes in the linked list
        ListNode *ptr = head;
        int size = 0;

        //traversing through the linked list and counting the number of nodes incrementally
        for (ListNode *ptr = head; ptr != nullptr; size++, ptr = ptr->next);

        //this is just to remove the first node in the list, where we can just have head point to the second node and return that
        if (size == n)
            return head->next;
        
        //traversing through the linked list until we are at the node just before the one that we want to remove
        for (int i = 0; i < size - n - 1; i++, ptr = ptr->next);

        //now we just skip the node we want to skip with the node just after that one
        ptr->next = ptr->next->next;

        return head;
    }
};
```

## Stacks & Queues (3 problems)

### 8. Valid Parentheses
**Link:** https://leetcode.com/problems/valid-parentheses/

**Solution:**
```cpp
class Solution {
public:
    bool isValid(string s) {
        //stack variable declaration to store the opening characters in s
        stack<char> characters;

        //iterating through each character of parameter s to check if the parentheses have matching opening and closing parts
        for (int i = 0; i < s.size(); i++)
        {
            //we are going to add each open parenthesis to our stack, which will then be compared with closed parentheses in the else condition
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                characters.push(s[i]);

            //for closed parentheses, we need to make sure the prior opening parenthesis matches the current character at index i in s
            else
            {
                //to avoid accessing an element that does not exist, we check to see if the stack is empty; if the stack is empty, then there is not an open parenthesis to be paired with the current character, so the string is not valid
                if (characters.empty()) return false;

                //since we are looking at an end parenthesis, we need to make sure that the most recent open parenthesis, the one on top of the stack, matches the closed parenthesis type: if it does, then great and we move on; otherwise, we say the string is not valid by returning false
                if (s[i] == ')' && characters.top() != '(' || s[i] == '}' && characters.top() != '{' || s[i] == ']' && characters.top() != '[')
                    return false;
            
                //since the pair of parentheses matches, we can pop the top of the stack so the next parenthesis can be evaluated
                characters.pop();
            }
        }

        //by returning whether the stack is empty, we are verifying that each open parenthesis has a matching closed parenthesis; if there are still items left in the stack, then there are missing closed parentheses and therefore the string is invalid
        return characters.empty();
    }
};
```

---

### 9. Min Stack
**Link:** https://leetcode.com/problems/min-stack/

**Solution:**
```cpp
class MinStack 
{
    private:
        //we need two vectors: one that stores each element of the stack and then a stack to store the current minimum value in the stack
        vector<int> stack, minStack;

    public:
        MinStack() {}
        
        //method for adding a new item to the stack
        void push (int val)
        {
            //we add each new element to the back of the stack
            stack.push_back(val);

            //if the stack is empty or this is a new minimum value, lower than the prior minimum value that has been seen, we will add this value to the minStack vector
            if (minStack.empty() || minStack.back() >= val)
                minStack.push_back(val)
            //otherwise, we will just copy the prior minimum value and push that to the back of the minStack vector
            else
                minStack.push_back(minStack.back());
        }
        
        //method for removing the top value on the stack. we need to remove the last item from both vectors to maintain the minStack functionality
        void pop() { stack.pop_back(); minStack.pop_back(); }
        
        //method for returning the element on the top of the stack
        int top() { return stack.back(); }
        
        //method for returning the minimum element in the stack
        int getMin() { return minStack.back(); }
};
```

---

### 10. Daily Temperatures
**Link:** https://leetcode.com/problems/daily-temperatures/

**Solution:**
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int> days;
        int 
    }
};
```

---

## Trees (5 problems)

### 11. Invert Binary Tree
**Link:** https://leetcode.com/problems/invert-binary-tree/

**Solution:**
```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //checking if we have reached a node with no children, if so, do not do recursion on this node
        if (root == nullptr)
            return root;
        
        //swapping the left and right children of node root
        swap(root->left, root->right);

        //now we are going to move to the nodes' children. first go to the left child and continue the swapping, then go to the right node and swap it's children
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        //eventually the last node to be returned recursively is the original root of the tree
        return root;
    }
};
```

---

### 12. Maximum Depth of Binary Tree
**Link:** https://leetcode.com/problems/maximum-depth-of-binary-tree/

**Solution:**
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //checking if we have reached a node with no children, if so, do not do recursion on this node
        if (root == nullptr)
            return 0;
        
        //variables for storing the depths of the left and right children
        int leftDepth, rightDepth;

        //traversing the left and right children and incrementing the total depth of that node by one
        leftDepth = 1 + maxDepth(root->left);
        rightDepth = 1 + maxDepth(root->right);
        
        //when returning the maximum depth of the root node, we at the last step of the recursive return either the depth of the left child or the right child; the node we return is the larger one since we are trying to find the maximum depth
        if (leftDepth >= rightDepth) 
            return leftDepth;
        
        return rightDepth;
    }
};
```

---

### 13. Binary Tree Level Order Traversal
**Link:** https://leetcode.com/problems/binary-tree-level-order-traversal/

**Solution:**
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //variables for storing the vector to be returned, a queue to implement this task, and a size variable to store the queue's size, a TreeNode pointer to point to the current element in the node, and a storage vector to store each level of node values derived from BFS
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode *> queue;
        TreeNode *node;
        int size;

        //checking to make sure we are given a tree that is not empty
        if (root == nullptr)
            return result;
        
        //adding the root of the tree to the queue
        queue.push(root);
        
        //looping through the queue until it is empty
        while (!queue.empty())
        {
            //storing the number of nodes in the queue at the moment
            size = queue.size();

            //looping through the number of current elements in the queue
            for (int i = 0; i < size; i++)
            {
                //copying the node at the front of queue to be added to our vector
                node = q.front();
                //popping the front element from the queue, hence why we just copied it above
                q.pop();

                //adding the front prior front node in the queue to the temporary vector, index i[j] of the final vector
                level.push_back(node->val);

                //if the current node has a left or right child, we are going to add that to the queue; it will be evaluated once the elements added first are evaluated
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            //adding index i of the result vector, the current BFS level, to our final
            result.push_back(level);
            //clearing our temporary storage vector since it was declared outside of the loop's scope
            level.clear();
        }

        return result;
    }
};
```

---

### 14. Lowest Common Ancestor of a Binary Search Tree
**Link:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

**Solution:**
```cpp
// Add your solution here
```

---

### 15. Path Sum
**Link:** https://leetcode.com/problems/path-sum/

**Solution:**
```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //checking if the tree is empty; if so, target will never be met
        if (root == nullptr)
            return false;

        //we need to update the target that we are looking for because now we are looking for a target underneath the root subtree
        targetSum -= root->val;

        //we need to check to see if the leaf node has a target value of zero; if this is true, then this root to leaf path's total is equal to the initial targetSum parameter
        if (root->left == nullptr && root->right == nullptr)
            return (targetSum == 0);

        //we now need to evaluate if the left child's node gets us to our target, so we will recursively call the method moving down in the tree; then we do the same with the root's right child node
        if (hasPathSum(root->left, targetSum))
            return true;

        return hasPathSum(root->right, targetSum);
    }
};
```

---

## Graphs (2 problems)

### 16. Number of Islands
**Link:** https://leetcode.com/problems/number-of-islands/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 17. Clone Graph
**Link:** https://leetcode.com/problems/clone-graph/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

## Hash Tables (2 problems)

### 18. Contains Duplicate
**Link:** https://leetcode.com/problems/contains-duplicate/

**Solution:**
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> results;

        for (int i = 0; i < nums.size(); i++)
            results[nums[i]]++;
        
        auto it = results.begin();

        for (; it != results.end(); it++)
            if (it->second > 1)
                return true;
        
        return false;
    }
};
```

---

### 19. Group Anagrams
**Link:** https://leetcode.com/problems/group-anagrams/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

## Dynamic Programming (2 problems)

### 20. Climbing Stairs
**Link:** https://leetcode.com/problems/climbing-stairs/

**Solution:**
```cpp
class Solution {
public:
    int climbStairs(int n) {
        //prev2 is the number of ways to reach stair 1, prev2 is the number of ways to reach stair 2, and current is the number of ways to reach stair x where x > 2
        int prev2 = 1, prev2 = 2, current;
        
        //base checks where if n is equal to one or two, we can simply just return the number of steps to reach either one of those steps
        if (n == 1) return 1;
        if (n == 2) return 2;

        //counting the number of different ways to climb n stairs in this loop where n is greater than 2
        for (int i = 3; i <= n; i++)
        {
            //the number of ways to climb i number of steps is found by adding the total number of ways to climb i - 1 and i - 2 steps
            current = prev1 + prev2;
            //we now update i - 2 steps to be i - 1
            prev2 = prev1;
            //we also need to update i - 1 steps to be i for our next iteration of the loop
            prev1 = current;
        }

        return prev1;
    }
};
```

---

### 21. House Robber
**Link:** https://leetcode.com/problems/house-robber/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---
