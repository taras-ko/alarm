#include <alarm_queue.h>

int main()
{
	Alarm a1 = { .index = 1 };
	Alarm a2 = { .index = 2 };
	Alarm a3 = { .index = 3 };

	AlarmQueue *alarm_queue = get_alarm_queue();

	alarm_queue->init();
	alarm_queue->add(&a1);
	alarm_queue->add(&a2);
	alarm_queue->add(&a3);

	while (alarm_queue->schedule_next())
		;
}
