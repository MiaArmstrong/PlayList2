//Mia Armstrong CS163
//Assignment 4
//File: main.cpp
/* This file is the test bed for the Table ADT.
This program loads a list of songs from an external file and stores them in a binary tree adt. Each song includes a title, an artist, an album name, the number
of minutes, and how many times it has been played. The user can enter a title and retrieve all songs in the tree with that title. The user can also delete a song by title.*/

#include "bst.h"

const int SIZE = 100;

bool again();

int main()
{
   char filename[SIZE] = "data.txt";
   song_item a_song, found;
   table my_music; 
   
   char new_title[SIZE]; //temporary for song_info
   char new_artist[SIZE];
   char new_album[SIZE];
   char key_title[SIZE];
   float new_minutes = 0;
   int new_plays = 0;
   int  success;
   bool to_cap = true; //for capitolizing the first letter of the title words.

//loads song library into hash table from file.
//returns false if file cannot open or does not work.
   ifstream file_in;
   file_in.open(filename); //reads in file.
   if (!file_in)
   {
      cout << "Could not open file " << filename << " for reading." << endl;
      return 0;
   }

   //connect to the file and ready to read
   file_in.get(new_title, SIZE, ';'); file_in.ignore(SIZE, ';');
   while (!file_in.eof()) //previous read was successful.
   {
      file_in.get(new_artist, SIZE, ';'); file_in.ignore(SIZE, ';');
      file_in.get(new_album, SIZE, ';'); file_in.ignore(SIZE, ';');
      file_in >> new_minutes; file_in.ignore(SIZE, ';');
      file_in >> new_plays; file_in.ignore(SIZE, ';'); 
      a_song.create_song(new_title, new_artist, new_album, new_minutes, new_plays);
      a_song.display();
      my_music.build(a_song);
      file_in.get(new_title, SIZE, ';'); file_in.ignore(SIZE, ';');
   }
   file_in.close(); 

   success = my_music.display();
   
   if (success != 1)
      cout << "Unable to display music." << endl;

   do
   {
      cout << "Enter a title: " << endl;
      cin.get(key_title, SIZE); cin.ignore(SIZE, '\n');
      for (int i = 0; i < strlen(key_title); ++i)
      {
         if (isalpha(key_title[i]) && to_cap == true)
         {
            key_title[i] = toupper(key_title[i]);
            to_cap = false;
         }
         else if (isspace(key_title[i]))
            to_cap = true;
      }   
  
      success = my_music.retrieve(key_title, a_song);
      if (success != 0)
      {
         cout << "\n\nHere are the songs with the title " << key_title << endl;
         
         
          a_song.play();
          a_song.display();
         
      }
      else
         cout << "\n\nThere were no matches." << endl;

    }while(again());

      return 0;
}

//Asks user if the would like to search for another song.
//Returns true for yes and falser for everything else.
bool again()
{
   char responce;
   cout << "\nEnter another title(y/n)? " << endl;
   cin >> responce; cin.ignore(SIZE, '\n');

   if (responce == 'y' || responce == 'Y')
      return true;
   else
      return false;
}
