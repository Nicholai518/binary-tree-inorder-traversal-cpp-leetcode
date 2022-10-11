#include <iostream>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  // recursive solution
  class Solution {
  public:
      // answer to be returned
      vector<int> answer;

      // helper function
      void traverse(TreeNode* root)
      {
          // if root is NULL, just return it
          if (root == NULL)
          {
              return;
          }

          // traverse left side
          traverse(root->left);
          answer.push_back(root->val);

          // traverse right side
          traverse(root->right);
      }
      vector<int> inorderTraversal(TreeNode* root)
      {
          answer.resize(0);
          traverse(root);
          return answer;
      }
  };

int main()
{
    Solution solution;

    TreeNode node_val_4(4);
    TreeNode node_val_5(5);
    TreeNode node_val_2(2, &node_val_4, &node_val_5);

    TreeNode node_val_6(6);
    TreeNode node_val_3(3, &node_val_6, nullptr);

    TreeNode root(1, &node_val_2, &node_val_3);

    vector<int> answer = solution.inorderTraversal(&root);

    cout << "Example One : ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

	return 0;
}
