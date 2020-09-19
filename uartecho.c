/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== uartecho.c ========
 */
/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

/* BIOS module Headers */
#include <ti/sysbios/BIOS.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/UART2.h>
#include <ti/drivers/SPI.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/PWM.h>
#include <ti/drivers/ADC.h>
/* Driver configuration */
#include "ti_drivers_config.h"

#include "LIS2HH12/lis2hh12_fun.h"
#include "TMP/TMP275.h"
#include "MLX90614/mlx90614.h"
#include "Mega.h"
#include <string.h>
#include <stdlib.h>


UART_Handle uart;
UART2_Handle uart2;

I2C_Handle i2c;
I2C_Transaction i2cTransaction;

SPI_Handle      masterSpi;
SPI_Transaction transaction;

PWM_Handle pwm1 = NULL;
PWM_Handle pwm0 = NULL;

ADC_Handle adc;
Timer_Handle timer0,timer1,timer2;

//void UART_INIT()
//{
//    UART2_Params uart2Params;
//
//    UART2_Params_init(&uart2Params);
//    uart2Params.baudRate = 9600;
//        uart2 = UART2_open(CONFIG_UART2_0, &uart2Params);
//
//           if (uart2 == NULL)
//           {
//               /* UART_open() failed */
//               while (1)
//                   ;
//           }
//
//}
void TIMER_Init()
{
    Timer_Params params;
    Timer_init();
   /*
     * Setting up the timer in continuous callback mode that calls the callback
     * function every 1,000,000 microseconds, or 1 second.
     */
    Timer_Params_init(&params);
    params.period = 1000000;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerCallback;

    timer0 = Timer_open(CONFIG_TIMER_0, &params);

    if (timer0 == NULL) {
        /* Failed to initialized timer */
        while (1) {}
    }
}
void TIMER1_Init()
{
    Timer_Params params2;
    Timer_init();
   /*
     * Setting up the timer in continuous callback mode that calls the callback
     * function every 1,000,000 microseconds, or 1 second.
     */
    Timer_Params_init(&params2);
    params2.period = 100000;
    params2.periodUnits = Timer_PERIOD_US;
    params2.timerMode = Timer_CONTINUOUS_CALLBACK;
    params2.timerCallback = timer1Callback;

    timer1 = Timer_open(CONFIG_TIMER_1, &params2);

    if (timer1 == NULL) {
        /* Failed to initialized timer */
        while (1) {}
    }
}

void TIMER2_Init()
{
    Timer_Params paramst2;
    Timer_init();
   /*
     * Setting up the timer in continuous callback mode that calls the callback
     * function every 1,000,000 microseconds, or 1 second.
     */
    Timer_Params_init(&paramst2);
    paramst2.period = 100000;
    paramst2.periodUnits = Timer_PERIOD_US;
    paramst2.timerMode = Timer_CONTINUOUS_CALLBACK;
    paramst2.timerCallback = timer2Callback;

    timer2 = Timer_open(CONFIG_TIMER_2, &paramst2);


}
void PWM_Init_Buzzer()
{
    PWM_Params pwmParams;

    /* Call driver init functions. */
    PWM_init();
    PWM_Params_init(&pwmParams);
    pwmParams.idleLevel = PWM_IDLE_LOW;    // Output low when PWM is not running
    pwmParams.periodValue = pwmPeriod;             // 1MHz
    pwmParams.dutyValue = 0;
    pwmParams.periodUnits = PWM_PERIOD_US;
    // 0% initial duty cycle
    pwmParams.dutyUnits = PWM_DUTY_US;
    pwm0 = PWM_open(CONFIG_PWM_1 , &pwmParams);
    if (pwm0 == NULL)
    {
        /* CONFIG_PWM_0 did not open */
        while (1);
    }
}

void PWM_Init()
{

    PWM_Params params;
    /* Call driver init functions. */
    PWM_init();

    PWM_Params_init(&params);
    params.dutyUnits = PWM_DUTY_US;
    params.periodUnits = PWM_PERIOD_US;
    params.dutyValue = 0;
    params.periodValue = pwmPeriod_MOTOR;
    pwm1 = PWM_open(CONFIG_PWM_Buzzer, &params);
    if (pwm1 == NULL){
        /* CONFIG_PWM_0 did not open */
        while (1) ;
    }
}

void Adc_Init()
{
    ADC_Params params;

    ADC_init();
    ADC_Params_init(&params);
    adc = ADC_open(CONFIG_ADC_0, &params);

    if (adc == NULL){
        while (1)  ;
    }

}
void I2C_Init()
{
    I2C_Params i2cParams;

    I2C_init();
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_100kHz;
    i2c = I2C_open(CONFIG_I2C_TMP, &i2cParams);
    if (i2c == NULL){
        while (1);
    }
}

void SPI_Init()
{
    SPI_Params spiParams;
    SPI_init();

    SPI_Params_init(&spiParams);
    spiParams.frameFormat = SPI_POL1_PHA1;
    spiParams.mode=SPI_MASTER;
    spiParams.dataSize=8;
    masterSpi = SPI_open(CONFIG_SPI_0, &spiParams);
    if (masterSpi == NULL){
        while (1);
    }
}

void CancelCallback(void *ptr)
{
    /* button is to clear any process running*/
    Alert_function(3,50);
    NexText_setText(&alert2,"are you sure?");
   // if(bat_flag==Temp275_fall)
    bat_flag=cancel_flag;
}

void AlertCallBack(uint_least8_t index)
{
    //alert  if pcb temp275 rise or fall
    buz_cont=0;

   if(tmp_flag==0){
        bat_flag=5;
    }
    else{
        bat_flag=4;
        shut_down=0;
    }
 }

/*
 *  ======== mainThread ========
 */
void* mainThread(void *arg0)
{
    int_fast16_t res;
    //  UART2_Params uart2Params;
    UART_Params uartParams;

    /* Call driver init functions */
    GPIO_init();

    GPIO_setConfig(Alert_GPIO, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING); ///alert pin
   // GPIO_setConfig(Alert_GPIO, GPIO_CFG_INPUT  | GPIO_CFG_IN_INT_FALLING);

    GPIO_setConfig(CONFIG_GPIO_ss, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Configure the LED pin */
     GPIO_setConfig(CONFIG_IN2, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
     GPIO_setConfig(CONFIG_GPIO_nsleep, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Install Alert callback */
    GPIO_setCallback(Alert_GPIO, AlertCallBack);
    /* Enable interrupts */
    GPIO_enableInt(Alert_GPIO);

    UART_init();
    /* Turn on user LED */
    GPIO_write(CONFIG_IN2, CONFIG_GPIO_LED_ON);   //in2 --low f  in2--high r
    GPIO_write(CONFIG_GPIO_nsleep, CONFIG_GPIO_LED_ON);

    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.readCallback = UART_readCallBack;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 9600;

    uart = UART_open(CONFIG_UART_0, &uartParams);
    if (uart == NULL)
    {
       while (1);
    }
  //  UART_INIT();
    I2C_Init();
    SPI_Init();
    PWM_Init();
    PWM_Init_Buzzer();
   Adc_Init();
    TIMER_Init();
    TIMER1_Init();
    TIMER2_Init();
    TMP_init();
    setHighTempThreshold(36);   /// TMP275   high   //.70
  //  setLowTempThreshold(35);   //  TMP275    low   //.55

     readRegister(0x00);
    whomid=readRegister(LIS2HH12_WHO_AM_I);
    setBasicConfig();
    moveing();

    CreateNexObject(tm0, pageid, 1, "tm0");
    CreateNexObject(motor, pageid,2, "motor");
    CreateNexObject(ok, pageid, 3, "ok");
    CreateNexObject(alert2, pageid, 4, "alert2");
    CreateNexObject(mode, pageid, 38, "mode");
    CreateNexObject(Load, pageid, 39, "Load");
    CreateNexObject(n1, pageid, 40, "n1");
    CreateNexObject(speed, pageid, 41, "speed");
    CreateNexObject(hour, pageid, 43, "hour");
    CreateNexObject(minute, pageid, 44, "minute");
    CreateNexObject(min, pageid, 55, "min");
    CreateNexObject(second, pageid, 47, "second");
    CreateNexObject(TempF, pageid, 54, "TempF");
    CreateNexObject(wifi, pageid, 9, "wifi");
    CreateNexObject(cancel, pageid, 12, "cancel");
    CreateNexObject(modeVar, pageid, 18, "modeVar");
    CreateNexObject(flag, pageid, 19, "flag");
    CreateNexObject(b1, pageid, 24, "b1");
    CreateNexObject(mstatus, pageid, 26, "mstatus");
    CreateNexObject(alert, pageid, 8, "alert");
    CreateNexObject(batterry, pageid,7, "batterry");
    CreateNexObject(warn, pageid,33, "warn");
    CreateNexObject(p0, pageid, 34, "p0");

    init_INA219(INA219_ADDRESS, &ina291_v);
    NEXTION_Init();

    NexTouch_attachPush(&ok, OK_Callback, 0);
   NexTouch_attachPush(&b1, PlayCallback, 0);
    NexTouch_attachPush(&cancel, CancelCallback, 0);
    NexTouch_attachPop(&mode, Mode_Callback, 0);
    NexTouch_attachPop(&n1, Second_callback, 0);
    NexTouch_attachPop(&min, Second_callback, 0);
    NexTouch_attachPop(&second, Second_callback, 0);

    Timer_start(timer0);
    Timer_start(timer2);

    PWM_start(pwm1);
    PWM_start(pwm0);
    UART_read(uart, aRXbuffer, 1);
    while (1)
    {
        nexLoop(nex_listen_list);
         if (getINT(IG1) == 1) {  // Also you can read only axis INT
              Timer_start(timer1) ;
         }
         else
          {
             Timer_stop(timer1) ;
          }
          check_flag();
               res = ADC_convert(adc, &adcValue0);
               if (res == ADC_STATUS_SUCCESS)
                   adcValue0MicroVolt = ADC_convertRawToMicroVolts(adc, adcValue0);

             //  Adc_mv = ((adcValue0MicroVolt / 1000) * 2538.46153846);
               Adc_mv=adcValue0MicroVolt/1000000;
               IR_Temp = mlx90614_readObjectTempF();
               if(counter==0)
                 T1=IR_Temp;

               T2=IR_Temp;
               if(bat_flag!=Temp275_rise && bat_flag!=Temp275_fall){
                   NexNumber_setValue(&TempF, IR_Temp);

               }
             //  Temp_275=getTemperature();

               NexVariable_getValue(&mstatus, &M_status);

               NexVariable_getValue(&modeVar, &m_val);
             //   delay_ms_new(10);

               if (M_status==1&&bat_flag!=acc_flag){
                    Set_load(Adc_mv);
                    duty = motor_mode(m_val);

                        PWM_setDuty(pwm1, duty);
                     }
                else
               {
                  PWM_setDuty(pwm1, 0);
                 if((m_val==Automode1||m_val==Automode2)){
                      NexNumber_setValue(&n1,0);
                      NexText_setText(&speed, "Stop");
                  }


                 }

             //  Bat_V = getBusVoltage_V(&ina291_v);
               Battery_Reading(Bat_V);

sleep(1);
      }
}

void timerCallback(Timer_Handle myHandle, int_fast16_t status)
{
//Req----35 rise or not temp
    counter+=1;
    if(bat_flag==acc_flag){
        motor_count+=1;
    }

    if(motor_count>6)
    {
        motor_count=0;
    }
    if(counter>10)
     {
         counter=0;
     }

}
void timer2Callback(Timer_Handle myHandle, int_fast16_t status)
{
    if(bat_flag!=0){

      buz_cont+=1;
      }
    else
    {
        buz_cont=0;

    }

}
void timer1Callback(Timer_Handle myHandle, int_fast16_t status)
{
    bat_flag=acc_flag;
   // motor_count=0;

}

void OK_Callback(void *ptr)
{
    PWM_setDuty(pwm0, 0);
    /*button is to assert requests and clear warnings.*/
   NexText_setText(&alert,"");
   NexText_setText(&alert2,"");

   if(bat_flag==cancel_flag)
   {
       bat_flag=startup_flag;
   }
   else
       bat_flag=0;
}

void Mode_Callback(void *ptr)
{
   /* change mode function */
   //NexVariable_getValue(&modeVar, &m_val);

  // NexText_setText(&Load,"mode");
   /*if(m_val==Automode1)
   {
       m_val=1;
       NexText_setText(&mode,"manual");

   }
   else if(m_val==Manual){
       m_val=3;
       NexText_setText(&mode,"automode2");

   }

   else if(m_val==Automode2){
         m_val=2;
         NexText_setText(&mode,"automode1");

     }*/
}

void Second_callback(void *ptr){

    if(m_val==Manual){
    }
    else{
     min_val=0;
     bat_flag=alertflag;
     buz_cont=0;;

    // second_val=0;
    // Alert_function();
    }
}

void PlayCallback(void *ptr)
{
    //start or stop the Countdown Timer
  //  NexVariable_getValue(&modeVar, &m_val);
  /*  NexVariable_getValue(&mstatus, &M_status);

    if(flag_val==0){
        flag_val=1;
        Nexpicture_setpic(&motor,2);
    }
    else{
    flag_val=0;
    Nexpicture_setpic(&motor,1);
    }*/
}

uint32_t Motorspeed(uint32_t n1_val)   //speed of motor
{
    uint32_t percentge;
    switch (n1_val)
    {

    case 0:
        percentge = 0;     // 0 rpm
        NexText_setText(&speed, "Stop");
        break;

    case 1:
        percentge = 40;    //8  rpm
        NexText_setText(&speed, "Very Slow");
        break;

    case 2:
        percentge = 57;    //16   rpm
        NexText_setText(&speed, "Slow");
        break;

    case 3:
        percentge = 70;   //24 //55    rpm
        NexText_setText(&speed, "Medium");
        break;

    case 4:
        percentge = 76;   //32 //74   rpm
        NexText_setText(&speed, "Fast");
        break;

    case 5:
        percentge = 83;   //35//81
        NexText_setText(&speed, "Very Fast");
        break;

    case 6:
        percentge = 95;   //40//93
        NexText_setText(&speed, "Hurricane");
        break;

    }
    return ((uint32_t) (((uint64_t) pwmPeriod_MOTOR * percentge) / 100));

}

uint32_t motor_mode(uint32_t number)
{

    uint32_t ret;
    switch (number)
    {
    case 1:  //manual mode
        NexNumber_getValue(&n1, &n1_val);

        ret = Motorspeed(n1_val);
        break;
    case 2:  //auto mode1
           if (mode_load)         //motor load detected
                 {
                   if (IR_Temp > -40 && IR_Temp <= 176)
                   {
                       NexNumber_setValue(&n1, 3);
                       ret = Motorspeed(3);
                   }
                   else if (IR_Temp >= 177 && IR_Temp <=210)
                   {
                       NexNumber_setValue(&n1, 4);
                       ret = Motorspeed(4);
                   }
                   else if (IR_Temp >= 211 && IR_Temp < 456)
                   {
                       NexNumber_setValue(&n1, 5);
                       ret = Motorspeed(5);
                   }
                   else if (IR_Temp>339 &&IR_Temp <= 455)
                   {
                                     NexNumber_setValue(&n1, 6);
                                     ret = Motorspeed(6);
                     }
                   else if (IR_Temp >= 456)
                   {
                       NexNumber_setValue(&n1, 6);
                       ret = Motorspeed(6);
                       NexText_setText(&alert2, "Overheating is Observed”");
                       bat_flag=overheat_flag;
                       Alert_warning();
                   }
                   else
                   {
                       NexNumber_setValue(&n1, 0);
                       ret = Motorspeed(0);
                   }

               }
               else    /// Auto Mode 1 No Load
                 //  NexText_setText(&Load, "No Load");

                  if (IR_Temp >= -40 && IR_Temp<87 )
                   {
                       NexNumber_setValue(&n1, 1);
                       ret = Motorspeed(1);
                   }
                   else if (IR_Temp >=87 && IR_Temp<123)
                   {
                       NexNumber_setValue(&n1, 2);
                       ret = Motorspeed(2);
                   }
                   else if (IR_Temp >= 123 && IR_Temp< 177)
                   {
                       NexNumber_setValue(&n1, 3);
                       ret = Motorspeed(3);
                   }
                   else if (IR_Temp >= 177 && IR_Temp < 213)
                   {
                       NexNumber_setValue(&n1, 4);
                       ret = Motorspeed(4);
                   }
                   else if (IR_Temp >= 213 && IR_Temp< 339)
                   {
                       NexNumber_setValue(&n1, 5);
                       ret = Motorspeed(5);
                   }
                   else if (IR_Temp>=339 && IR_Temp< 456)
                   {
                       NexNumber_setValue(&n1, 6);
                       ret = Motorspeed(6);
                    }
                   else if (IR_Temp >= 456)
                   {
                       NexNumber_setValue(&n1, 6);
                       NexText_setText(&alert2, "Overheating is Observed”");
                       bat_flag=overheat_flag;
                       Alert_warning();
                       ret = Motorspeed(6);
                   }
                   else
                   {
                       NexNumber_setValue(&n1, 0);
                       ret = Motorspeed(0);
                   }
        break;
    case 3:  //automode 2
        if (IR_Temp >= -40 && IR_Temp <177)
             {
                 NexNumber_setValue(&n1, 4);
                 ret = Motorspeed(4);
             }
             else if (IR_Temp >= 177 && IR_Temp < 339)
             {
                 NexNumber_setValue(&n1, 5);
                 ret = Motorspeed(5);
             }
             else if (IR_Temp>= 339 && IR_Temp <456)
              {
                 NexNumber_setValue(&n1, 6);
                  ret = Motorspeed(6);
               }
             else if (IR_Temp >= 456)
             {
                 NexNumber_setValue(&n1, 6);
                 NexText_setText(&alert2, "Overheating is Observed”");
                 bat_flag=overheat_flag;
                 Alert_warning();
                 ret = Motorspeed(6);
             }
             else
             {
                 NexNumber_setValue(&n1, 0);
                 ret = Motorspeed(0);
             }
    break;
    }

return ret;

}

void Set_load(float load_value)
{
    if(load_value>=0.43&&load_value<=0.59)
      {
           NexText_setText(&Load, "Very Small");
           mode_load=1;
      }
    else if(load_value>=0.60&&load_value<=0.85)
       {
           NexText_setText(&Load, "Small");
           mode_load=1;
       }
    else if(load_value>=0.86&&load_value<=1.11)
        {
            NexText_setText(&Load, "Medium");
            mode_load=1;
        }
    else if(load_value>=1.12&&load_value<=1.37)
        {
            NexText_setText(&Load, "Heavy");
            mode_load=1;
        }
    else if(load_value>=1.37&&load_value<=1.45)
        {
            NexText_setText(&Load, "Very Heavy");
            mode_load=1;
        }
    else if(load_value>=1.46)
        {
            NexText_setText(&Load, "Jam");
            mode_load=1;
        }
    else{
        mode_load=0;
        NexText_setText(&Load, "No Load");

    }

}

void Alert_function(uint8_t t_on,uint8_t t_off)   /// ms
{
    if(buz_cont>=(t_on+t_off))
        {
        buz_cont=0;
        }
      if(buz_cont<t_on)
     {
         dutyValue = ((uint32_t) (((uint64_t) pwmPeriod * 95) / 100));
         PWM_setDuty(pwm0, dutyValue);
     }
      else if(buz_cont>=t_on &&buz_cont<(t_on+t_off))
         {

        PWM_setDuty(pwm0, 0);
        }
}
/*void Alert_function()
 {
    if(buz_cont>=53){
        buz_cont=0;
    }
    if(buz_cont<3){
     dutyValue = ((uint32_t) (((uint64_t) pwmPeriod * 30) / 100));
     PWM_setDuty(pwm0, dutyValue);
    }
    else if(buz_cont>=4 &&buz_cont<53)
     {
        PWM_setDuty(pwm0, 0);
     }
 }
*/
void Alert_warning()
 {
    if(buz_cont>=37){
           buz_cont=0;
       }
       if(buz_cont<=6){
        dutyValue = ((uint32_t) (((uint64_t) pwmPeriod * 95) / 100));
        PWM_setDuty(pwm0, dutyValue);
       }
       else if(buz_cont>=7 &&buz_cont<36)
        {
           PWM_setDuty(pwm0, 0);
        }
 }

void Alert_longwarning()
 {
    if(buz_cont>=40){
           buz_cont=0;
       }
       if(buz_cont<10){
        dutyValue = ((uint32_t) (((uint64_t) pwmPeriod * 90) / 100));
        PWM_setDuty(pwm0, dutyValue);
       }
       else if(buz_cont>=10 &&buz_cont<40)
        {
           PWM_setDuty(pwm0, 0);
        }

 }

void Battery_Reading(float bat_voltage)
{

    if(check_event==1&&bat_voltage>=9.7 ){
            check_event=0;
            NexText_setText(&alert, " ");
            NexText_setText(&alert2, " ");
      }

    if(bat_voltage>=12.6)
       Nexpicture_setpic(&batterry,3);

    else if(bat_voltage>=11.5&&bat_voltage<=12.5)
        Nexpicture_setpic(&batterry,4);

   else if(bat_voltage>=10.9&&bat_voltage>=11.4)
       Nexpicture_setpic(&batterry,5);

   else if(bat_voltage>=10.3&&bat_voltage>=10.8)
       Nexpicture_setpic(&batterry,6);

   else if(bat_voltage>=9.7&&bat_voltage>=10.2)
         Nexpicture_setpic(&batterry,7);

   else if(bat_voltage<=9.6){
         Nexpicture_setpic(&batterry,8);
         if(bat_flag==0){
         check_event=1;
         NexText_setText(&alert, "ALERT");
         NexText_setText(&alert2, "Battery 0% Charged");
          Alert_function(3,50);
         }

   }

}

void check_flag()                 //check to all Interrupt  --Saftey feature  system
{
    while(shut_down)
    {
        sleep(1);
    }
    if(bat_flag==alertflag)
    {
         Alert_function(3,50);

    }

    if(bat_flag==Temp275_rise)
    {
        Nexpicture_setpic(&warn,20);
        NexText_setText(&alert,"WARNING");
        NexText_setText(&alert2,"");
        Alert_longwarning();

              if(getTemperature()>=38)
              {
                  setLowTempThreshold(30);
                  tmp_flag=1;
                  PWM_setDuty(pwm0, 0); //clear alert
                  //NexText_setText(&alert2,"It is shutting down to cool");   //change
                    Nexpicture_setpic(&p0,24);   //change

                //  disable(&nextimer);
                  shut_down=1;                   /* Go to shutdown */
              }
              else{
                   //  NexText_setText(&alert2," Current process will shut down");
                     Nexpicture_setpic(&p0,26);   //change
                     if((T2-T1)/10){
                         Nexpicture_setpic(&p0,22);
                     }
              }
    }

    else if(bat_flag==Temp275_fall)
    {
      NexText_setText(&alert,"ALERT");
      Nexpicture_setpic(&p0,21);
      Nexpicture_setpic(&warn,9);    // clear warning

      tmp_flag=0;
    // NexText_setText(&alert2,"Resume the previous process??");

      Alert_warning();
    }

    else if(bat_flag==acc_flag)
    {
      //  if (flag_val==1&&M_status==1){
        if (M_status==1){
            NexText_setText(&alert2,"Motion Detected! Motor stopped.");
                 Alert_function(3,50);
                // sleep(5);
                 while(motor_count>5)  //motor stop for 5sec
                 {
                     motor_count=0;
                     NexText_setText(&alert2,"");
                     PWM_setDuty(pwm0, 0); //clear alert
                     bat_flag=0;

                 }
        }
        if((T2-T1)/10){                    // check req-35
             bat_flag=0;
             NexText_setText(&alert2,"");
             PWM_setDuty(pwm0, 0); //clear alert

        }
    }

    else if(bat_flag==startup_flag)
    {
        bat_flag=0;
        m_val = 2;  // automode  mode 1
        flag_val=0;
        M_status=0;
        Nexpicture_setpic(&motor,1);   // motor pause state
        NexNumber_setValue(&hour,0);
        NexNumber_setValue(&minute, 30);
        NexNumber_setValue(&min,0);
        NexNumber_setValue(&second,0);
        NexNumber_setValue(&n1,0);
        NexVariable_setValue(&modeVar,m_val);
        NexVariable_setValue(&mstatus,0);
        disable(&nextimer);
        NexText_setText(&mode,"Auto Mode1");

        NexText_setText(&speed,"stop");
    }
}
