# STM32_Ultrasonic_Sensor

***************************************************************************

2022-01-24

Code for calculate distance using HC-SR04 module

Used STM32F103RB and STM32F411RE
TIM2_Channel1 ( 16 bit Timer )
Echo : TIM2_1
Trig : PA11 (GPIO Output)

Distance --> cm
Time     --> us

Start timer after init --> HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
Use brusting trig code in while(1) --> Send_Trigger_Signal();

***************************************************************************