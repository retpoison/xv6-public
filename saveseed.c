#include "types.h"
#include "user.h"
#include "fcntl.h"

static int
openseedfile(int omode)
{
	int fd;

	if ((fd = open(SFILE, omode)) < 0) {
		if ((fd = open(SFILE, O_CREATE)) < 0) {
			return -1;
		}
	}
	return fd;
}

static int
savetofile(long int s)
{
	int fd, i, j;
	char buf[32] = { 0 };

	if ((fd = openseedfile(O_WRONLY)) < 0) {
		printf(1, "saveseed: init failed\n");
		return -1;
	}

	for (i = s, j = 0; i > 0; i /= 10, j++) ;
	itoa(s, buf, j);
//      printf(1, "buf: %s\nseed: %d\nj: %d\n", buf, s, j);
	write(fd, buf, j);
	close(fd);
	return 0;
}

void
saveseed(void)
{
	int u = uptime();
	int c = uartchars();
	long int seed = u + c;
	if (savetofile(seed) == 0)
		printf(1, "seed saved seccessfully\n");
	else
		printf(1, "saving seed failed\n");
	exit();
}

int
main()
{
	saveseed();
	exit();
}
