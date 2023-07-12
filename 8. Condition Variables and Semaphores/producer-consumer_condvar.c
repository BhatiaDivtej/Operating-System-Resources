#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* Fix this Producer/consumer program using mutex and conditional variables */

/* Size of shared buffer */
#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];/* shared buffer */
int add=0;		/* place to add next element */
int rem=0;		/* place to remove next element */
int num=0;		/* number elements in buffer */

// TODO: Declare mutex and condition variables

//void *producer(void *param);
//void *consumer(void *param);

// TODO: Modify producer() and consumer() to
// work properly using mutex and condition variables

/* Produce value(s) */
void *producer(void *param)
{
        int i, j;
	for (i=1; i<=20; i++) {
		/* Insert into buffer */
		if (num > BUFFER_SIZE) exit(1);	/* overflow */
		while (num == BUFFER_SIZE)		/* block if buffer is full */
		  break;
		/* if executing here, buffer not full so add element */
		buffer[add] = i;
		j = add;
		add = (add+1) % BUFFER_SIZE;
		num++;
		printf ("producer: inserted item %d at %d\n", buffer[j], j);  fflush(stdout);
	}
	printf ("producer quiting\n");  fflush (stdout);
	return NULL;
}

/* Consume value(s) */
void *consumer(void *param)
{
        int i, j;

	for (j=0; j<20; j++) {

		if (num < 0) exit(1);   /* underflow */
		while (num == 0)	/* block if buffer empty */
		  break;
		/* if executing here, buffer not empty so remove element */
		i = buffer[rem];
		rem = (rem+1) % BUFFER_SIZE;
		num--;
		printf ("consumer: removed item %d at %d\n", buffer[i], i);  fflush(stdout);
	}
	printf ("consumer quiting\n");  fflush (stdout);
	return NULL;
}


// Do not modify the code that starts and joins the threads
int main (int argc, char *argv[])
{
	pthread_t tid1, tid2;		/* thread identifiers */

	/* create the threads; in general, may be any number */
	if (pthread_create(&tid1,NULL,producer,NULL) != 0) {
		fprintf (stderr, "Unable to create producer thread\n");
		exit (1);
	}

	if (pthread_create(&tid2,NULL,consumer,NULL) != 0) {
		fprintf (stderr, "Unable to create consumer thread\n");
		exit (1);
	}

	/* wait for created threads to exit */
	pthread_join(tid2,NULL);
	pthread_join(tid1,NULL);

	// Destroy mutexes
	printf ("Parent quiting\n");

	return 0;
}
