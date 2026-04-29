/*
 * 二叉搜索树 (BST) 模板
 * 
 * 支持操作：
 * - 插入节点
 * - 搜索节点
 * - 删除节点
 * - 中序遍历
 */

#include <iostream>
#include <vector>

using namespace std;

// 树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * 插入节点
 * 参数：
 *   - root: 根节点
 *   - val: 要插入的值
 * 返回值：新的根节点
 */
TreeNode* insertIntoBST(TreeNode* root, int val) {
    // 空树，创建新节点
    if (root == nullptr) {
        return new TreeNode(val);
    }
    
    // 根据 BST 性质决定插入位置
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}

/**
 * 搜索节点
 * 参数：
 *   - root: 根节点
 *   - val: 要搜索的值
 * 返回值：找到的节点，未找到返回 nullptr
 */
TreeNode* searchBST(TreeNode* root, int val) {
    // 空树或找到
    if (root == nullptr || root->val == val) {
        return root;
    }
    
    // 根据 BST 性质决定搜索方向
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

/**
 * 删除节点
 * 参数：
 *   - root: 根节点
 *   - val: 要删除的值
 * 返回值：新的根节点
 */
TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // 找到要删除的节点
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        // 找到要删除的节点
        
        // 情况 1：叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        
        // 情况 2：只有右子树
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        
        // 情况 3：只有左子树
        if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        // 情况 4：有两个子树
        // 找到右子树中的最小节点（中序后继）
        TreeNode* minNode = root->right;
        while (minNode->left != nullptr) {
            minNode = minNode->left;
        }
        
        // 用最小节点的值替换当前节点
        root->val = minNode->val;
        // 删除右子树中的最小节点
        root->right = deleteNode(root->right, minNode->val);
    }
    
    return root;
}

/**
 * 中序遍历（输出有序序列）
 * 参数：
 *   - root: 根节点
 *   - result: 存储结果的向量
 */
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    TreeNode* root = nullptr;
    
    // 构建 BST
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertIntoBST(root, val);
    }
    
    // 中序遍历
    vector<int> result;
    inorderTraversal(root, result);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
