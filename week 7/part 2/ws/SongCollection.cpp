//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     17th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <numeric> 
#include <algorithm>
#include "SongCollection.h"
namespace seneca {
   
   std::string SongCollection::trim(std::string& str)
   {
      str.erase(0, str.find_first_not_of(" ")); // Remove leading spaces
      str.erase(str.find_last_not_of(" ") + 1); // Remove trailing spaces
      return str;
   }

   SongCollection::SongCollection(const char* fileName)
   {
      Song song;
      std::ifstream file(fileName);
      if (file)
      {

         std::string line{};
         
         while (!file.eof())
         {
            //Bird Set Free            Sia                      This Is Acting           2016 252  1.21 
            std::getline(file, line, '\n');
            //title
            song.m_title = line.substr(0, 25);
            trim(song.m_title);
            line = line.erase(0, 25);
            //artist
            song.m_artist = line.substr(0, 25);
            trim(song.m_artist);
            line = line.erase(0, 25);

            //album
            song.m_album = line.substr(0, 25);
            line = line.erase(0, 25);
            trim(song.m_album);

            try
            {
               song.m_releaseYear = stoi(line.substr(0, 5));
            }
            catch (...) {
               song.m_releaseYear = 0;
            }
            line = line.erase(0, 5);

            //length
            song.m_lengthOfTheSong = stoi(line.substr(0, 5));
            line = line.erase(0, 5);
            //price
            song.m_price = stod(line.substr(0, 5));
            line = line.erase(0, 5);

            m_song.push_back(song);
         }
         
      }
      
      if (!file)
      {
         throw "Invalid File!";
      }

      file.close();
   }
   
   
   void SongCollection::display(std::ostream& out) const {
      
      std::for_each(
         m_song.begin(), m_song.end(), [&out](const Song collection)
         {
            out << collection << std::endl;
         }
      );
      out << "----------------------------------------------------------------------------------------" << std::endl;

      // Calculate total playtime
      int totalPlaytime = static_cast<int>(std::accumulate(m_song.begin(), m_song.end(), static_cast<size_t>(0),
         [](size_t sum, const Song& song) {
            return sum + song.m_lengthOfTheSong;
         }
      ));


      // Convert total playtime to hours and minutes
      int hours = (totalPlaytime/60) / 60;
      int minutes = (totalPlaytime / 60) % 60;
      int seconds = totalPlaytime % 60;

      // Display total playtime
      out << "|                                                        Total Listening Time: " << hours << ":" << minutes << ":" << seconds << " |" << std::endl;
   }

   void SongCollection::sort(const std::string& str) {
      auto compare = [str](const Song& songA, const Song& songB) {
         if (str == "length") {
            return songA.m_lengthOfTheSong < songB.m_lengthOfTheSong;
         }
         else if (str == "title") {
            return songA.m_title < songB.m_title;
         }
         else if (str == "album") {
            return songA.m_album < songB.m_album;
         }
         else {
            throw std::invalid_argument(str + ": invalid field name for sorting!");
         }
         };

      try {
         std::sort(m_song.begin(), m_song.end(), compare);
      }
      catch (const std::invalid_argument& e) {
         std::cout << e.what() << std::endl;
         exit(1);
      }
   }


   void SongCollection::cleanAlbum()
   {
      std::transform(
         m_song.begin(), m_song.end(), m_song.begin(),
         [](Song& song) {
            if (song.m_album == "[None]") {
               song.m_album = ""; // Replace [None] with empty string
            }
            return song;
         }
      );
   }

   bool SongCollection::inCollection(const std::string artistName) const
   {
      return std::any_of(
         m_song.begin(), m_song.end(),
         [&artistName](const Song& song) {
            return song.m_artist == artistName;
         }
      );
   }

   std::list<Song> SongCollection::getSongsForArtist(const std::string& artistName) const
   {
      std::list<Song> songsForArtist;
      std::copy_if(
         m_song.begin(), m_song.end(),
         std::back_inserter(songsForArtist),
         [&artistName](const Song& song) {
            return song.m_artist == artistName;
         }
      );
      return songsForArtist;
   }

   std::ostream& operator<<(std::ostream& out, const Song& theSong)
   {
      out << "| " << std::left << std::setw(20) << theSong.m_title;
      out << " | " << std::left << std::setw(15) << theSong.m_artist;
      out << " | " << std::left << std::setw(20) << theSong.m_album;
      out << " | " << std::right << std::setw(6);
      if (theSong.m_releaseYear)
      {
         out << theSong.m_releaseYear;
      }
      else
      {
         out << "";
      }
      out << " | " 
         << std::to_string(theSong.m_lengthOfTheSong / 60) << ":"
         << std::setfill('0') << std::setw(2)
         << std::to_string(theSong.m_lengthOfTheSong % 60) << std::setfill(' ');
      out << " | " << std::fixed << std::setprecision(2) << theSong.m_price 
         << " |";
      return out;
   }

}

