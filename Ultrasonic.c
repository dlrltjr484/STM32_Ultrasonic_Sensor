
uint16_t Value1, Value2, Time, State, Distance = 0;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim2)											   // Input Capture Mode
{
		if (State == 0)																				   
		{
			Value1 = HAL_TIM_ReadCapturedValue(htim2, TIM_CHANNEL_1); 								   // Save First Value at Value1 ( RISING EDGE )
			State = 1;																				   

			__HAL_TIM_SET_CAPTUREPOLARITY(htim2, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);	   // Change Capture Polarity to FALLING EDGE
		}

		else if (State == 1)
		{
			Value2 = HAL_TIM_ReadCapturedValue(htim2, TIM_CHANNEL_1);  								   // Save Second Value at Value2 ( FALLING EDGE )

			if (Value2 > Value1)																	   
			{
				Time = Value2-Value1;
			}

			else if (Value1 > Value2)																   
			{																						   
				Time = (65536 - Value1) + Value2;
			}

			Distance = Time * 0.034 / 2;															   
			State = 0;																				   

			__HAL_TIM_SET_CAPTUREPOLARITY(htim2, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);	   // Change Capture Polarity to RISING EDGE
		}
}


void Send_Trigger_Signal (void)																		   // For Brust Trig Signal
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);                                               
	HAL_Delay(0);  																					   
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET); 											   
}



HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);												  // Start Input Capture Interrupt 