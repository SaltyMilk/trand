#include "trand.h"

int g_rfound;

void *thread(void *ma)
{
	static pthread_mutex_t mutex;
	pthread_mutex_t *m = &mutex;
	int r;
	for (unsigned long long i = 0; i < *(unsigned long long*)ma + 1; i++)
		r  = rand();
	pthread_mutex_lock((pthread_mutex_t *)m);
	if (g_rfound == -1)
		g_rfound = r;
	pthread_mutex_unlock((pthread_mutex_t *)m);
	return (NULL);
}

/*
** Control how many threads to create,
** the more threads the more secure ntrand wil be
*/

int ntrand(unsigned long long n)
{
	g_rfound = -1;
	pthread_t threads[n];
	for (unsigned long long i = 0; i < n; i++)
		pthread_create(&(threads[i]), NULL, thread, (void *)(&i));
	for (unsigned long long i = 0; i < n; i++)
		pthread_join(threads[i], NULL);
	return (g_rfound);
}

/*
** Basically rand but we seed with time for you, user-friendly
*/

int strand()
{
	g_rfound = -1;
	srand(time(NULL));
	pthread_mutex_t mutex;
	pthread_t threads[DEF_NTHREAD];
	for (unsigned long long i = 0; i < DEF_NTHREAD; i++)
		pthread_create(&(threads[i]), NULL, thread, (void *)(&i));
	for (unsigned long long i = 0; i < DEF_NTHREAD; i++)
		pthread_join(threads[i], NULL);
	return (g_rfound);
}


/*
* In this version you are responsable for seeding rand()
*/

int trand()
{
	g_rfound = -1;
	pthread_mutex_t mutex;
	pthread_t threads[DEF_NTHREAD];
	for (unsigned long long i = 0; i < DEF_NTHREAD; i++)
		pthread_create(&(threads[i]), NULL, thread, (void *)(&i));
	for (unsigned long long i = 0; i < DEF_NTHREAD; i++)
		pthread_join(threads[i], NULL);
	return (g_rfound);
}
