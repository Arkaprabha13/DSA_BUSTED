/*
std::ostringstream is a class in the C++ Standard Library that represents an output stream where data can be written as formatted text.
It is part of the <sstream> header. In other words, it allows you to build a string by formatting and concatenating different types of data, 
just like you would with std::cout, but instead of outputting to the console, it outputs to a string.

std::ostringstream result;
result << t->val;
Here, a std::ostringstream named result is created to accumulate the string representation of the binary tree. 
The << operator is then used to append the value of the current node (t->val) to the stream.

return result.str();
This line converts the std::ostringstream object result to a std::string by calling the str() member function, and the resulting string is then returned.
  */
class Solution {
public:
    string tree2str(TreeNode* t) {
         if (t == nullptr) {
            return "";
        }

        ostringstream result;
        result << t->val;

        if (t->left != nullptr || t->right != nullptr) {
            result << "(" << tree2str(t->left) << ")";
        }

        if (t->right != nullptr) {
            result << "(" << tree2str(t->right) << ")";
        }

        return result.str();
    }
};
