/*
 * thread.h
 *
 *  Created on: 16 thg 9, 2020
 *      Author: USER
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <stdint.h>

#define MAX_THREAD 10

typedef void (*thread_func_t)(void*);
typedef int thread_id_t;
typedef enum {
    THREAD_REPEAT,          // Function only run one time
    THREAD_SINGLESHOT       // Function run periodically
}thread_type_t;

typedef struct {
    thread_func_t thread_func;  // Pointer to function
    int period;                 // Period of function
    int cnt;                    // Internal counter
    thread_type_t type;         // Type of thread
    void* ctx;                  // Give this to function when run it
}thread_t;

thread_id_t register_thread(thread_func_t thread_func,int period_ms, thread_type_t type, void* context);
uint8_t unregister_thread(thread_id_t proc_id);
void one_ms_timer_interrupt();
void Blink_led0(void *ctx);
void Blink_led1(void *ctx);
void Blink_led2(void *ctx);
void Blink_led3(void *ctx);
void Blink_led4(void *ctx);
void Blink_led5(void *ctx);
void Blink_led6(void *ctx);
void Blink_led7(void *ctx);
void Blink_buzz(void *ctx);

#endif /* THREAD_H_ */
