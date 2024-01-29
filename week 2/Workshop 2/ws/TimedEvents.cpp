// Student Nmae: Krutin Bharatbhai Polra
// Student ID:   135416220
// E-mail:       kbpolra@myseneca.ca
// Date-Of-Compeletion: 27th January 2024
// Course: OOP345 NAA
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace seneca {
  
   TimedEvents::TimedEvents() {}

   TimedEvents& TimedEvents::startClock()
   {
      m_startTime = std::chrono::steady_clock::now();
      return *this;
   }

   TimedEvents& TimedEvents::stopClock()
   {
      m_endTime = std::chrono::steady_clock::now();
      return *this;
   }

   TimedEvents& TimedEvents::addEvent(const char* EventName)
   {
      if (EventName)
      {
         m_events[m_numberOfRecords].EventName = EventName;
         m_events[m_numberOfRecords].predefinedUnitsOfTime = "nanoseconds";
         m_events[m_numberOfRecords].eventDuration = chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);
         m_numberOfRecords++;
      }

      return *this;
   }


   ostream& operator<<(std::ostream& os, const TimedEvents& timedEvent)
   {
      os << "--------------------------\nExecution Times:\n--------------------------" << std::endl;

      for (size_t i = 0; i < timedEvent.m_numberOfRecords; ++i)
      {
         os << std::left << std::setw(21) << timedEvent.m_events[i].EventName
            << std::right << std::setw(13) << timedEvent.m_events[i].eventDuration.count()
            << " " << timedEvent.m_events[i].predefinedUnitsOfTime << std::endl;
      }

      os << "--------------------------" << std::endl;

      return os;
   }

   TimedEvents::~TimedEvents() {}
}

