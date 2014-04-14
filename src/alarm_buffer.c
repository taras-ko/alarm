#include <stdio.h>
#include <string.h>

#include <alarm_buffer.h>

static Alarm buf[BUF_SZ];
static int buf_idx = 0;

static AlarmBuf alarm_buf = {
	.reset = reset_alarm_buffer,
	.push = push_alarm,
	.get = get_alarm,
	.delete = delete_alarm,
};

AlarmBuf *get_alarm_buf()
{
	return &alarm_buf;
}

static void reset_alarm_buffer()
{
	memset(buf, 0, sizeof(Alarm) * BUF_SZ);
}

static Alarm *put_alarm(Alarm *alarm)
{
	if (buf_idx >= BUF_SZ)
		return NULL;
	else {
		Alarm *new_alarm = &buf[buf_idx++];
		memcpy(new_alarm, alarm, sizeof(Alarm));
		return new_alarm;
	}
}

static void delete_alarm()
{
	buf_idx--;
}

static void get_alarm () {}
