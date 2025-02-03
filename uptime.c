#include "types.h"
#include "user.h"
#include "param.h"

int
main(int argc, char **argv)
{
	uint ticks = uptime();
	uint d = 1000000000 / TICK_TIME;
	float s = (float)ticks / d;
	uint sf = ((int)(s * 10000) - ((int)s * 10000)) / 100;
	printf(1, "uptime\ntick\t%d\nsecond\t%d.%ds\n", ticks, (int)s, sf);
	exit();
}
