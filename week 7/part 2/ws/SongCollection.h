//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     16th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H
#include <vector>
#include <iostream>
#include <list>

namespace seneca {

   struct Song {
      std::string m_artist = "";
      std::string m_title = "";
      std::string m_album = "";
      double m_price = 0.0;
      size_t m_releaseYear = 0u;
      size_t m_lengthOfTheSong = 0;
   };
   class SongCollection
   {
      std::vector<Song> m_song;
      std::string trim(std::string& str);
   public:
      SongCollection(const char* fileName);
      void display(std::ostream& out) const;
      void sort(const std::string& str);
      void cleanAlbum();
      bool inCollection(const std::string artistName) const;
      std::list<Song> getSongsForArtist(const std::string& artistName) const;
   };

   std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SENECA_SONGCOLLECTION_H


