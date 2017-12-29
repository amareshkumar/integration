#include "MyThread.hpp"


/* To demonstrate mutex variable while dealing with threads.  */
static int balance = 10000;
#define NTHREAD 8
pthread_mutex_t mx_balance_update;

void* showUpdatedBalance (void *null){
    //Apply mutex variable before changing the value of 
    
    pthread_mutex_lock(&mx_balance_update);
    cout << "Balance now is: " << balance <<"\n";
    balance = balance + 5000;
    pthread_mutex_unlock(&mx_balance_update);
    
    pthread_exit(NULL);
	return NULL;
}

void thread_func_mutex (){
//Array of 5 threads
    int rc; 
    pthread_t mythreads[NTHREAD];
    pthread_attr_t attr;
    
    pthread_mutex_init(&mx_balance_update, NULL);
         
   /* Create threads to perform balance update */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    for (int i = 0; i < NTHREAD; i++){
        rc = pthread_create(&mythreads[i], &attr, showUpdatedBalance, NULL);
        
        if (rc) {
            cout << "Error, pthread_create returned code: " << rc << endl;
        }
    }
   
    //wait on other threads
    for (int i = 0; i < NTHREAD; i++){
        pthread_join(mythreads[i], NULL);
    }
  
   pthread_attr_destroy(&attr);
    
    pthread_mutex_destroy(&mx_balance_update);
    pthread_exit (NULL);
}

/* condition variables */
#define balance_thr 80000
#define balance_now 50000
int balance_count = 0;
int threads[10];
//create variables for mutex and condtions
pthread_mutex_t balance_mutex; 
pthread_cond_t balance_thre_cv; 

void* watch_balance (void* null){
    long my_id = (long)null;
    
    cout << "\nStarting watch_balance()... thread id: " << my_id << endl;
    /*
  Lock mutex and wait for signal.  Note that the pthread_cond_wait 
  routine will automatically and atomically unlock mutex while it waits. 
  Also, note that if COUNT_LIMIT is reached before this routine is run by
  the waiting thread, the loop will be skipped to prevent pthread_cond_wait
  from never returning. 
  */
    pthread_mutex_lock (&balance_mutex);
    
    while (balance_count < balance_thr) {
        pthread_cond_wait(&balance_thre_cv, &balance_mutex);
        cout << "watch_balance(): Condition signal received. my_id: " << my_id;
        balance_count = balance_now + 10000;
        cout << "watch_balance(): count now = " << balance_count << " my_id: " << my_id << "\n";
    }
    
    pthread_mutex_unlock(&balance_mutex);
    pthread_exit (NULL);
	return NULL;
}

void* update_balance_cv (void* null){
    
    long my_id = (long)null;
    
    for (int balance  = 0; balance < balance_now; balance = balance + 10000){
        pthread_mutex_lock (&balance_mutex);
        balance = balance + 10000;
        
        if (balance == balance_thr){
            pthread_cond_signal(&balance_thre_cv);
            cout << "update_balance_cv(): balance = " << balance << " Threshold reached. my_id " << my_id <<"\n" ;
        }
        cout << "update_balance_cv(): balance = " << balance << " unlocking mutex my_id: " << my_id <<"\n";
        pthread_mutex_unlock(&balance_mutex);

        /* Do some "work" so threads can alternate on mutex lock */
//        sleep(1);
    }
    pthread_exit (NULL);
	return NULL;
}

void thread_func_cond(){
    pthread_t cv_threads[10];
    pthread_attr_t attr; 
    
    
    //Initialize mutex and condition variable object
    pthread_mutex_init (&balance_mutex, NULL);
    pthread_cond_init(&balance_thre_cv, NULL);
    
    //create 10 threads in joinable states explicitly
    pthread_attr_init (&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    pthread_create (&cv_threads[0], &attr, watch_balance, (void *)0);
    for (int i = 1; i < 10; i++){
        pthread_create (&cv_threads[i], &attr, update_balance_cv, (void *)i);
    }
    
    /* Wait for other threads to complete */
    for (int i = 1; i < 10; i++){
        pthread_join (cv_threads[i], NULL);
    }
}


//write function so that each thread prints different area of input string of int
void* print_number(void *arg) {
	int *value = (int*)arg;

	for (int i = 0; i < 20; i++) {
		if (value[i] == 0) {
			cout << "Thread with id " << " is printing " << value[i] << endl;
		}
		else {
			continue;
		}
	}
	pthread_exit(NULL);
	return NULL;
}


/*
To do
// this is to be done may be using boost thread
//	Implement thread utility so that given a string like 0012555428779,
// one thread print 0 other only even and another only odd number

// Copy and paste in client program/main program
//common pthread code snippet

cout << "Threading practises..." << endl;
//intialize memory for an array of integers
int *array = new int(20);

for (int i = 0; i < 20; i++) {
array[i] = i;
}

//create a threads
pthread_t th1;
//call a function
pthread_create(&th1, NULL, print_number, (void*)array);

//allow thread(s) to join
pthread_join(th1, NULL);

delete[] array;
*/
