      
//Mia Armstrong CS163
//Assignment 4
//File: bst.cpp
/*This file has all the functions for the BST table class. */

#include "bst.h"

//This is the constructor for the table class
table::table()
{
   root = NULL;
}
      
//This is the destructor for the table class.
table::~table()
{
   remove_all();
   root = NULL;
}

     
//This function builds the tree adt `by adding nodes starting at the root.
//This is a wrapper function for the recursive function. 
//This function takes in a song item and returns an int, 0 for failure, 1 for success
int table::build(song_item & new_song)
{
   if (!root)
   {
      root = new node;
      root->song.copy_entry(new_song);
      root->left = NULL;
      root->right = NULL;
      return 1;
   }
   else
      return build(root, new_song);
}
      
int table::retrieve(char * title_to_find, song_item & found_songs) const
{
  return retrieve(title_to_find, found_songs, root);
}
      
int table::remove(char * title_to_remove)
{
   return remove(title_to_remove, root);
}
      
int table::display() const
{
   return display(root);
}

int table::remove_all()
{
   return remove_all(root);
}
  
     
      
int table::build(node * root, song_item & to_add)
{

   if (!root)
   {
      root = new node;
      root->left = NULL;
      root->right = NULL;
      root->song.copy_entry(to_add);
      cout << "Adding song to leaf" << endl;
      root->song.display();
      return 1;
   }

   int result = to_add.compare(root->song, to_add);

   if (result == -1)
   {  
      cout << "Root->left" << endl; 
      build(root->left, to_add);
      
      
   }
   else if (result == 1)
   {
      cout << "root->right" << endl;
      build(root->right, to_add);
      
   }
 
   
}
      
int table::retrieve(char * found_title, song_item found_song, node * root) const
{
  /* if (found_song.compare(found_title, root->song.title) == 0)
       root->song.copy_entry(found_song);
   if (found_song.compare(found_title, root->song.title)== -1)
      retrieve( found_title, found_song, root->left);
   else 
      retrieve(found_title, found_song, root->right);
   */
}
      
int table::display(node * root) const
{
   if (root)
   {
      display(root->left);
      root->song.display();
      display(root->right);
      return 1;
   }
   
}
      
int table::remove(char * song_title, node * & root)
{
  /* if (root->song.compare(root->song.title, song_title)
   {
   delete root;
   root = NULL;
   return 1;
   }
   remove(song_title, root->left);
   remove(song_title, root->right);
   */
}
      
int table::remove_all(node * & root)
{
   if (!root)
      return 0;

   remove_all(root->left);
   remove_all(root->right);
   delete root;
   root = NULL;
   return 1;

}

