#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include "event.h"

using namespace std;

namespace seneca {

    rsize_t g_sysClock = 0;
    Event::Event(): startingTime(0) 
    {
        eventDescription[0] = '\0';
    }
    void Event::display()
    {
    }
    void Event::set(const char* desc)
    {
        if (desc != nullptr && desc[0] != '\0') {

            strncpy(eventDescription, desc, sizeof(eventDescription) - 1);
            eventDescription[sizeof(eventDescription) - 1] = '\0';

            startingTime = g_sysClock;
        }
    }
}