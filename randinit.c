#include "types.h"
#include "user.h"
#include "spinlock.h"
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

void
seedinit()
{
	int fd, n, s = 1, i;
	char buf[32];

	if ((fd = openseedfile(O_RDONLY)) < 0) {
		printf(1, "seedinit: init failed\n");
		exit();
	} else {
		n = read(fd, buf, sizeof(buf));
		if (n)
			s = 0;
		for (i = 0; i < n; i++)
			if (buf[i])
				s = (s * 10) + buf[i] - '0';

		printf(1, "seed %d\n", s);
		close(fd);
		s--;
	}
	setseed(s);
	exit();
}

int
main(void)
{
	seedinit();
	exit();
}
