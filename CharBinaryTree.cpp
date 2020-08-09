#include <iostream>
#include <cstring>
#include "CharBinaryTree.h"
using namespace std;


void CharBinaryTree::insert(TreeNode * &tree, char word[])
{
     //If tree is empty, make a new node and make it the root
     if(!tree)
     {
              tree = new TreeNode(word);
              return;
     }
     
     //if word is already in the tree: return
     if(strcmp(tree->value,word)==0)
        return;
                  
     //Tree is not empty. Insert the node to the left/right
     if(strcmp(word,tree->value)<0)
         insert(tree->left,word);
     else
         insert(tree->right,word);
}

/*
void CharBinaryTree::destroySubtree(TreeNode *tree)
{
     if(!tree) return;
     destroySubtree(tree->left);
     destroySubtree(tree->right);
     //Delete the node at the node
     delete tree;    
}
*/



bool CharBinaryTree::search(char word[])
{
     TreeNode *tree = root;
     
     while(tree)
     {
                if(strcmp(tree->value,word)==0)
                    return true;
                else if(strcmp(word,tree->value)<0)
                    tree = tree->left;
                else
                    tree = tree->right;
     }
     return false;     
}
