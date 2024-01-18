#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#define maxSize 128
namespace seneca {

	class Event
	{
		char eventDescription[maxSize] = "";
		size_t startingTime{};

	public:
		Event();
		void set(const char* desc = nullptr);
		void display();
	};

	extern size_t g_sysClock;
}

#endif // !SENECA_EVENT_H

