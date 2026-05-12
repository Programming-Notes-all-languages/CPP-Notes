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
// Add your solution here
```

**Explanation:**


---

### 6. Linked List Cycle
**Link:** https://leetcode.com/problems/linked-list-cycle/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 7. Remove Nth Node From End of List
**Link:** https://leetcode.com/problems/remove-nth-node-from-end-of-list/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

## Stacks & Queues (3 problems)

### 8. Valid Parentheses
**Link:** https://leetcode.com/problems/valid-parentheses/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 9. Min Stack
**Link:** https://leetcode.com/problems/min-stack/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 10. Daily Temperatures
**Link:** https://leetcode.com/problems/daily-temperatures/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

## Trees (5 problems)

### 11. Invert Binary Tree
**Link:** https://leetcode.com/problems/invert-binary-tree/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 12. Maximum Depth of Binary Tree
**Link:** https://leetcode.com/problems/maximum-depth-of-binary-tree/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 13. Binary Tree Level Order Traversal
**Link:** https://leetcode.com/problems/binary-tree-level-order-traversal/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 14. Lowest Common Ancestor of a Binary Search Tree
**Link:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

### 15. Path Sum
**Link:** https://leetcode.com/problems/path-sum/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


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
// Add your solution here
```

**Explanation:**


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
// Add your solution here
```

**Explanation:**


---

### 21. House Robber
**Link:** https://leetcode.com/problems/house-robber/

**Solution:**
```cpp
// Add your solution here
```

**Explanation:**


---

## Progress Tracker

- [ ] Two Sum
- [ ] Best Time to Buy and Sell Stock
- [ ] Valid Palindrome
- [ ] Reverse Linked List
- [ ] Merge Two Sorted Lists
- [ ] Linked List Cycle
- [ ] Remove Nth Node From End of List
- [ ] Valid Parentheses
- [ ] Min Stack
- [ ] Daily Temperatures
- [ ] Invert Binary Tree
- [ ] Maximum Depth of Binary Tree
- [ ] Binary Tree Level Order Traversal
- [ ] Lowest Common Ancestor of a Binary Search Tree
- [ ] Path Sum
- [ ] Number of Islands
- [ ] Clone Graph
- [ ] Contains Duplicate
- [ ] Group Anagrams
- [ ] Climbing Stairs
- [ ] House Robber
