#ifndef CHARBINARYTREE_H
#define CHARBINARYTREE_H

class CharBinaryTree
{
private:
      class TreeNode
      {      
             friend class CharBinaryTree;
             char value[];
             TreeNode *left;
             TreeNode *right;
             TreeNode(char value1[], TreeNode *left1=NULL,
                                     TreeNode *right1=NULL)
             {    strcpy(value,value1);   left=left1;   right=right1;    }
      };
      
      TreeNode *root;
      void insert(TreeNode *&, char []);
      //void destroySubtree(TreeNode *);
      
public:
      CharBinaryTree()      //Constructor
          {  root = NULL; }
      //~CharBinaryTree()     //Destructor
        //   {  destroySubtree(root);  }
      void insert(char word[])
          {  insert(root,word);     }
      bool search(char []);
       
};     
#endif
