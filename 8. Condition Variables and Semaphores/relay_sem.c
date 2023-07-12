// Compile:     gcc relay_sem.c -o relay_sem
// Run:         ./relay_sem
//
// or `make relay_sem` and `make run_sem`
// 
// Fix the broken relay race
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <semaphore.h>

#include <pthread.h>

// TODO: Declare semaphores for your runners

// A function to simulate a thread doing some work
// In our example, we simply sleep our thread.
void make_runner_run(const char *name, int finish) { 
  if (!finish) {
    printf("%s has taken off!\n", name);
  }
  else {
    printf("%s runs the anchor leg to the finish line!\n", name);
  }
  sleep(2);
}

// TODO: Modify runner1 through runner4
// so that runner1 always executes first,
// then runner2, then runner3, then runner4 last.
void *runner1(void *vargp) {
  make_runner_run("Sha'Carri Richardson", 0);
  return NULL;
}

void *runner2(void *vargp) {
  make_runner_run("Allyson Felix", 0);
  return NULL;
}

void *runner3(void *vargp) {
  make_runner_run("Dina Asher-Smith", 0);
  return NULL;
}

void *runner4(void *vargp) {
  make_runner_run("Shelly-Ann Fraser-Pryce", 1);
  return NULL;
}

int main() {

  // Collect all the runners on the starting line
  void *(*runners[4])(void *) = {runner1, runner2, runner3, runner4};
  
  // Store our thread ids
  pthread_t tids[4];

  // Turn off buffering for stdout so we get accurate output
  setvbuf(stdout, NULL, _IONBF, 0);

  // TODO: Initialize semaphores for runners using sem_init

  // Start the race!

  // Create our threads - do not change this for loop
  for (int i = 0; i < 4; i++) {
    pthread_create(&tids[i], NULL, runners[i], NULL);
  }

  // Join threads - do not change this for loop
  for (int i = 0; i < 4; i++) {
    pthread_join(tids[i], NULL);
  }

  // TODO: Destroy our semaphores sem_destroy

  return 0;
}
