#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
};

struct SegmentTreeNode {
    int start;
    int end;
    int sum;
    int minVal;
    int maxVal;
    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int _start, int _end)
        : start(_start), end(_end), sum(0), minVal(INT_MAX), maxVal(INT_MIN) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void updateSegmentTree(SegmentTreeNode* node, int val) {
    if (!node) {
        return;
    }
    node->sum += val;
    node->minVal = min(node->minVal, val);
    node->maxVal = max(node->maxVal, val);
    if (node->start != node->end) {
        int mid = (node->start + node->end) / 2;
        if (val <= mid) {
            updateSegmentTree(node->left, val);
        } else {
            updateSegmentTree(node->right, val);
        }
    }
}

int getSumOfWLargest(SegmentTreeNode* node, int w) {
    if (!node || w <= 0) {
        return 0;
    }

    if (w >= node->sum) {
        return node->sum;
    }

    if (node->start == node->end) {
        return node->start * w;
    }

    int leftSize = node->left ? node->left->sum : 0;
    
    if (leftSize >= w) {
        return getSumOfWLargest(node->left, w);
    } else {
        return leftSize + getSumOfWLargest(node->right, w - leftSize);
    }
}

int getSumOfWSmallest(SegmentTreeNode* node, int w) {
    if (!node || w <= 0) {
        return 0;
    }

    if (w >= node->sum) {
        return node->sum;
    }

    if (node->start == node->end) {
        return node->start * w;
    }

    int leftSize = node->left ? node->left->sum : 0;
    
    if (leftSize >= w) {
        return getSumOfWSmallest(node->left, w);
    } else {
        return leftSize + getSumOfWSmallest(node->right, w - leftSize);
    }
}

// Function to build a Segment Tree from a BST
SegmentTreeNode* buildSegmentTree(TreeNode* node, int start, int end) {
    if (!node) {
        return NULL;
    }
    SegmentTreeNode* segment_node = new SegmentTreeNode(start, end);
    if (start < end) {
        int mid = (start + end) / 2;
        segment_node->left = buildSegmentTree(node->left, start, mid);
        segment_node->right = buildSegmentTree(node->right, mid + 1, end);
    }
    return segment_node;
}

int main() {
    TreeNode* rootBST = NULL;

    // Build the BST and maintain it as you insert elements
    rootBST = insertBST(rootBST, 5);
    rootBST = insertBST(rootBST, 3);
    rootBST = insertBST(rootBST, 8);
    rootBST = insertBST(rootBST, 1);
    rootBST = insertBST(rootBST, 4);

    // Build the Segment Tree on top of the BST
    SegmentTreeNode* rootSegmentTree = buildSegmentTree(rootBST, 1, 8);

    // Perform updates on the BST and the corresponding Segment Tree
    updateSegmentTree(rootSegmentTree, 6);
    updateSegmentTree(rootSegmentTree, 2);

    // Query the sum of w largest elements (e.g., w = 3)
    int sumOfWLargest = getSumOfWLargest(rootSegmentTree, 3);
    cout << "Sum of 3 largest elements: " << sumOfWLargest << endl;

    // Query the sum of w smallest elements (e.g., w = 2)
    int sumOfWSmallest = getSumOfWSmallest(rootSegmentTree, 2);
    cout << "Sum of 2 smallest elements: " << sumOfWSmallest << endl;

    return 0;
}
