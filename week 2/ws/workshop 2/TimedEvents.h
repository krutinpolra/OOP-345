#pragma once
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

#include <chrono>
#include <string>

using namespace std;

namespace seneca {
   
   class TimedEvents
   {
      const unsigned int m_NumberOfEvent;
      unsigned int numberOfRecords;
      chrono::steady_clock::time_point startTime; 
      chrono::steady_clock::time_point endTime;

      struct Event
      {
         string EventName;
         string predefinedUnitsOfTime;
         chrono::steady_clock::duration eventDuration;
      };

   public:
      TimedEvents();
      void startClock();
      void stopClock();
      void addEvent(const char* EventOfName);

      friend ostream& operator<<(ostream& os, const TimedEvents& timedEvent);
   };

}

#endif

