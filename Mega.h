/*
 * Mega.h
 *
 *  Created on: Jun 22, 2020
 *      Author: dnk125
 */

#ifndef MEGA_H_
#define MEGA_H_

#include <ti/drivers/Timer.h>
#include <ti/drivers/UART2.h>

#include "Nextion-Library/nextion/Nextion.h"
#include "Nextion-Library/util/Utilities.h"

#include "INA219.h"
/* POSIX Header files */
#include <pthread.h>
#include <semaphore.h>

#define pageid 0


struct NexObject alert2, alert, motor, wifi, batterry, hour, minute, min,
        second, ok, cancel, b1, slider, n1, speed, mode, Load, tm0, TempF,
        modeVar, va0, flag, ALERT, mstatus, warn, n3,va1,batterry,p0,nextimer;

struct NexObject *nex_listen_list[] = { &b1, &ok, &cancel,&n1,&mode,NULL};


uint32_t dutyCycle;
uint64_t pwmPeriod = 200;//80000;
uint64_t pwmPeriod_MOTOR =5000;
//uint64_t pwmPeriod_buzz =1e6;
uint64_t duty = 0;
uint32_t dutyValue = 0; /* 0us (0%) initial duty cycle */

float IR_Temp, Temp_275, Bat_V, Bat_mV;
uint8_t shut_down=0,getval,buz_cont=0;
uint8_t mode_load=0 ,counter=0,alert_counter=0,tinterval=0,mode_change,whomid,motor_count=0;
uint16_t adcValue0, T2, T1;
uint32_t adcValue0MicroVolt;
uint32_t Adc_mv=0;
 uint32_t flag_val = 0,bat_flag=0,tmp_flag=0,check_event;
uint32_t n1_val = 0, m_val =2, M_status =0, alert_val = 0,second_val=0,min_val=0,total_time=0,counter2;
INA219 ina291_v;


typedef enum{

    Manual=1,
    Automode1=2,
    Automode2=3

} Mega_Mode;


typedef enum{

    Alert_sound=4,
    Warning_sound=5,
    longwarninng_sound=6,
    Low_battry=7

} Mega_sound;



typedef enum{

   warnflag=1,
   alertflag,
   IRTemp_rise,
   Temp275_fall,
   Temp275_rise,
   batteryflag,
   acc_flag,
   overheat_flag,
   startup_flag,
   cancel_flag
} Mega_flag;

void timerCallback(Timer_Handle myHandle, int_fast16_t status);
void timer1Callback(Timer_Handle myHandle, int_fast16_t status);
void timer2Callback(Timer_Handle myHandle, int_fast16_t status);

void OK_Callback(void *ptr);
void Mode_Callback(void *ptr);
void speed_callback(void *ptr);
void Min_callback(void *ptr);
void Second_callback(void *ptr);

void PlayCallback(void *ptr);
uint32_t motor_mode(uint32_t number);
uint32_t Motorspeed(uint32_t n1_val);
void Set_load(float load_value);
//void Alert_function(void);
void Alert_function(uint8_t t_on,uint8_t t_off) ;  /// ms

void Alert_warning(void);
void Alert_longwarning(void);
void Battery_Reading(float bat_voltage);
void check_flag();
#endif /* MEGA_H_ */
