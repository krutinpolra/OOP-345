#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
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
      else {
         throw "Invalid File!";
      }


   }
   
   
   void SongCollection::display(std::ostream& out) const {
      
      std::for_each(
         m_song.begin(), m_song.end(), [&out](const Song collection)
         {
            out << collection << std::endl;
         }
      );
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

