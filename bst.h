
//Mia Armstrong CS163
//Assignment 4
//File: bst.h
/*This is the header file for the (BST) table class. */

#include "song.h"

struct node
{
   song_item song;
   node * left;
   node * right;
};

class table
{
   public:
      table();
      ~table();
      int build(song_item & new_song);
      int retrieve(char * title_to_find, song_item & found_songs) const;
      int remove(char * song_title);
      int display() const;
      int remove_all();
   private:
      node * root;
      int retrieve(char * found_title, song_item found_song, node * root) const;
      int build(node * root, song_item & to_add);
      int display(node * root) const;
      int remove(char * song_title, node * & root);
      int remove_all(node * & root);
};
