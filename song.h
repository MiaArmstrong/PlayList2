//Mia Armstrong CS163
//Assignment 4
//File: song.h
/*This is the header file for the song class. */

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

class song_item
{
   public:
         song_item();
         ~song_item();
         int create_song(char * new_title, char * new_artist, char * new_album, float new_minutes, int new_plays);
         int copy_entry(song_item & a_new_song);
         int retrieve(char * title_to_find, song_item & found)const;
         int compare(song_item compare, song_item song_to_add);
         int display() const;
         int remove();
         int play();      
   private:
         char * title;
         char * artist;
         char * album;
         float minutes;
         int plays;
};
