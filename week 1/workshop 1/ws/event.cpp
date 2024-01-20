#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include "event.h"

namespace seneca {

    size_t g_sysClock{};
    size_t Event::counter = 1;

    Event::Event(): startingTime(0), id(counter++)
    {
        eventDescription[0] = '\0';
    }

    void Event::display()
    {
        std::cout << std::setw(2) << id << ". ";
        if (eventDescription[0] == '\0') {
            std::cout << "| No Event |\n";
        }
        else {
            size_t hours = startingTime / 3600;
            size_t minutes = (startingTime % 3600) / 60;
            size_t seconds = startingTime % 60;
            std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                << std::setw(2) << minutes << ":"
                << std::setw(2) << seconds << " => " << eventDescription << '\n';
        }
    }

    void Event::set(const char* desc)
    {
        if (desc != nullptr && desc[0] != '\0') {

            startingTime = g_sysClock;

            strncpy(eventDescription, desc, sizeof(eventDescription) - 1);
            eventDescription[sizeof(eventDescription) - 1] = '\0';
        }
        else {
            
            eventDescription[0] = '\0';
        }
    }
}