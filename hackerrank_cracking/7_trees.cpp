/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool checkBST(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }

    if ((!(maxTreeValue(root->left) < root->data)) || (!(minTreeValue(root->right) > root->data)))
    {
        return false;
    }

    return (checkBST(root->left) && checkBST(root->right));
}

int minTreeValue(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }

    return std::min(root->data, std::min(minTreeValue(root->left), minTreeValue(root->right)));
}

int maxTreeValue(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }

    return std::max(root->data, std::max(maxTreeValue(root->left), maxTreeValue(root->right)));
}
