// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     7th April 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <algorithm>
#include <iostream>
#include <fstream>
#include "LineManager.h"
#include "Workstation.h"

namespace seneca {
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      std::fstream FileObj(file);

      if (FileObj.is_open()) {
         std::string str;

         while (std::getline(FileObj, str)) {
            if (str.find('|') != std::string::npos) {
               std::string nameOfStation, nextNameOfStation;

               size_t delimitor = str.find('|');

               nameOfStation = str.substr(0, delimitor);
               nextNameOfStation = str.substr(delimitor + 1);

               auto currentLine = std::find_if(stations.begin(), stations.end(), [&](const Workstation* wStation) {
                  return wStation->getItemName() == nameOfStation;
                  });

               if (currentLine != stations.end())
                  m_activeLine.push_back(*currentLine);

               auto nextworkStation = std::find_if(stations.begin(), stations.end(), [&](const Workstation* wStation) {
                  return wStation->getItemName() == nextNameOfStation;
                  });

               if (currentLine != stations.end())
                  m_activeLine.back()->setNextStation(*nextworkStation);
            }
            else {
               auto currentLine = std::find_if(stations.begin(), stations.end(), [&](const Workstation* wStation) {
                  return wStation->getItemName() == str;
                  });

               if (currentLine != stations.end())
                  m_activeLine.push_back(*currentLine);

            }

            auto findFirstStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* wStation) {
               return std::none_of(stations.begin(), stations.end(), [&](Workstation* other) {
                  return other != wStation && other->getNextStation() == wStation;
                  });
               });

            if (findFirstStation != stations.end())
               m_firstStation = *findFirstStation;

            m_cntCustomerOrder = g_pending.size();

         }
      }
   }
   bool LineManager::run(std::ostream& os) {
      static size_t counter = 0;
      ++counter;

      os << "Line Manager Iteration: " << counter << std::endl;

      if (g_pending.size() > 0) {
         *m_firstStation += std::move(g_pending.front());
         g_pending.pop_front();
      }

      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* wStation) {
         wStation->fill(os);
         });

      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* wStation) {
         wStation->attemptToMoveOrder();
         });

      return (g_completed.size() + g_incomplete.size()) == m_cntCustomerOrder;
   }


   void LineManager::reorderStations()
   {
      std::sort(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* firstWS, Workstation* secondWS) {
         // Lambda function to find the position of a workstation in the line
         auto getPosition = [&](Workstation* ws) {
            unsigned int pos = 0;
            Workstation* currentStation = m_firstStation;
            while (currentStation != ws) {
               currentStation = currentStation->getNextStation();
               ++pos;
            }
            return pos;
            };

         // Get positions of the workstations
         unsigned int pos1 = getPosition(firstWS);
         unsigned int pos2 = getPosition(secondWS);

         return pos1 < pos2; // Compare positions
         });

   }


   void LineManager::display(std::ostream& os) const {
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* wStation) {
         wStation->display(os);
         });
   }
}