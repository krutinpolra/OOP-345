#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H
#include <vector>
#include <iostream>

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
   };

   std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SENECA_SONGCOLLECTION_H


