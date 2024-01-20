#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca {

	extern size_t g_sysClock;

	class Event
	{
		char* eventDescription;
		size_t startingTime{};
		static size_t counter;
		size_t id;

	public:
		Event();
		void set(const char* desc = nullptr);
		void display();
		~Event();
	};

}

#endif // !SENECA_EVENT_H

