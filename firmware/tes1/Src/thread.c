/*
 * thread.c
 *
 *  Created on: 16 thg 9, 2020
 *      Author: USER
 */
#include <stdint.h>
#include "tim.h"
#include "thread.h"

thread_t m_thread[MAX_THREAD];

thread_id_t register_thread(thread_func_t thread_func,int period_ms, thread_type_t type, void* context) {
    for (int i = 0; i < MAX_THREAD; i++) {
        if (m_thread[i].thread_func == NULL) // Check if is there any empty slot
        {
            m_thread[i].thread_func = thread_func;
            m_thread[i].period = period_ms;
            m_thread[i].cnt = period_ms;
            m_thread[i].type = type;
            m_thread[i].ctx = context;
            return i;
        }
    }
    return -1; // if there is no slot remain, return invalid id
}

uint8_t unregister_thread(thread_id_t proc_id) {
    if (m_thread[proc_id].thread_func != NULL) {
        m_thread[proc_id].thread_func = NULL;
        return 1;
    }
    else {
        return 0;
    }
}

void one_ms_timer_interrupt() {
    for (int i = 0; i < MAX_THREAD; i++) {
        if (m_thread[i].thread_func != NULL) {
            m_thread[i].cnt--;                                  // Reduce internal counter
            if (m_thread[i].cnt == 0) {                         // Check if timeout
                m_thread[i].thread_func(m_thread[i].ctx);       // Run fucntion with context
                if (m_thread[i].type == THREAD_REPEAT) {        // Check thread type
                    m_thread[i].cnt = m_thread[i].period;       // Reset counter
                }
                else if(m_thread[i].type == THREAD_SINGLESHOT)
                {
                    m_thread[i].thread_func = NULL;             // Unregister thread
                }
            }
        }
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if( htim -> Instance == htim1.Instance)
	{
		one_ms_timer_interrupt();
	}
}

void Blink_led0(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
}

void Blink_led1(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
}
void Blink_led2(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
}
void Blink_led3(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}
void Blink_led4(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
}
void Blink_led5(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
void Blink_led6(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
}
void Blink_led7(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
}
void Blink_buzz(void *ctx)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
}
