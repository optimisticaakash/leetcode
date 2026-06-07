# LeetCode 2196 - Create Binary Tree From Descriptions

## Problem Statement

Given an array `descriptions` where each element is:

```cpp
[parent, child, isLeft]
```

* `parent` → Parent node value
* `child` → Child node value
* `isLeft = 1` → Child is the left child
* `isLeft = 0` → Child is the right child

Construct the binary tree and return its root.

---

## Intuition

The root node is the **only node that never appears as a child**.

So:

1. Build all nodes and connect them according to the descriptions.
2. Store every child node in a set.
3. The node that never appears in the child set must be the root.

---

## Data Structures Used

```cpp
unordered_map<int, TreeNode*> mp;
unordered_set<int> childSet;
```

### HashMap (`mp`)

Stores:

```cpp
node value -> TreeNode*
```

Used to:

* Avoid duplicate node creation.
* Access nodes in O(1) time.

### HashSet (`childSet`)

Stores all nodes that appear as children.

Used to:

* Identify the root node.

---

## Approach

### Step 1: Create Nodes

For every description:

```cpp
[parent, child, isLeft]
```

Create parent and child nodes if they do not already exist.

```cpp
if(mp.find(parent) == mp.end())
    mp[parent] = new TreeNode(parent);

if(mp.find(child) == mp.end())
    mp[child] = new TreeNode(child);
```

---

### Step 2: Connect Nodes

If `isLeft == 1`

```cpp
mp[parent]->left = mp[child];
```

Else

```cpp
mp[parent]->right = mp[child];
```

---

### Step 3: Track Children

Every child is inserted into the set.

```cpp
childSet.insert(child);
```

A child node can never be the root.

---

### Step 4: Find Root

Traverse all descriptions again.

If a parent is not present inside `childSet`, then it never appeared as a child.

```cpp
if(childSet.find(parent) == childSet.end())
    return mp[parent];
```

That node is the root.

---

## Algorithm

1. Initialize:

   * HashMap for storing nodes.
   * HashSet for storing child nodes.

2. Traverse descriptions:

   * Create parent node if needed.
   * Create child node if needed.
   * Connect parent and child.
   * Insert child into the set.

3. Traverse descriptions again:

   * Find the parent that is not present in the child set.
   * Return its node.

---

## Complexity Analysis

### Time Complexity

```cpp
O(N)
```

* First pass → Build Tree
* Second pass → Find Root

Total = **O(N)**

### Space Complexity

```cpp
O(N)
```

* HashMap stores all nodes.
* HashSet stores all child nodes.

---

## Key Observation

> Root is the only node that never appears as a child.

This observation eliminates the need for DFS, BFS, or graph traversal to find the root.

---

## Pattern

**Binary Tree Construction + Root Identification**

Whenever:

* Parent-child relationships are given.
* Nodes have unique values.

A common approach is:

1. Build nodes using a hashmap.
2. Track incoming edges (children).
3. Node with no incoming edge becomes the root.

4. ## Code
5. /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;

        unordered_set<int> childSet;//they can never be root of the tree

        for(vector<int>& vec: descriptions){
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1){//left child
                mp[parent]->left = mp[child];
            }else{
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }

        //find the root
        for(vector<int>& vec: descriptions){
            int parent= vec[0];

            if(childSet.find(parent)  == childSet.end()){
                return mp[parent];
            }
        }

        return NULL;//we will never reach here
    }
};
