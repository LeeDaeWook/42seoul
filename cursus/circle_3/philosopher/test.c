#include "philosopher.h"

int main()
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	printf("%ld\n", tv.tv_sec);
	printf("%d\n", tv.tv_usec);
	printf("%ld\n", tv.tv_sec + tv.tv_usec);

	return 0;
}