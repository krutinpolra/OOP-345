// Student Nmae: Krutin Bharatbhai Polra
// Student ID:   135416220
// E-mail:       kbpolra@myseneca.ca
// Date-Of-Compeletion: 27th January 2024
// Course: OOP345 NAA
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.

#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

#include <iostream>
#include <chrono>


namespace seneca {
   
   struct Event
   {
      std::string EventName{};
      std::string predefinedUnitsOfTime{};
      std::chrono::steady_clock::duration eventDuration;
   };


   class TimedEvents
   {
      static constexpr int m_NumberOfEvent = 10;
      unsigned int m_numberOfRecords{};
      std::chrono::steady_clock::time_point m_startTime{};
      std::chrono::steady_clock::time_point m_endTime{};
      Event m_events[m_NumberOfEvent]{};

   public:
      TimedEvents();
      TimedEvents& startClock();
      TimedEvents& stopClock();
      TimedEvents& addEvent(const char* nameOfEvent);
      friend std::ostream& operator<<(std::ostream& os, const TimedEvents& timedEvent);
      ~TimedEvents();
   };

}

#endif

