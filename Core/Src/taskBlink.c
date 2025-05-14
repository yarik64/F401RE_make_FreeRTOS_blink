// taskBlink.c

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stdbool.h"
#include "FreeRTOS.h"
#include "semphr.h"


void vGreenBlinkTask( void *pvParametrs ) {
	bool ps = false;
	for(;;) {
		HAL_GPIO_WritePin(
				GPIOA,
				GPIO_PIN_8,
				ps ? GPIO_PIN_SET : GPIO_PIN_RESET);
		ps = !ps;
		vTaskDelay( 700 );
	}
}

void vRedBlinkTask( void *pvParametrs ) {
	bool ps = false;
	bool as = false;

	SemaphoreHandle_t ButtonPush;
	ButtonPush = xSemaphoreCreateBinary();

	for(;;) {
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0))
	{
		xSemaphoreGive(ButtonPush);
	}
	vTaskDelay(200);

		if (ButtonPush) { bool as = !as; } 
		HAL_GPIO_WritePin(
				GPIOC,
				GPIO_PIN_13,
				ps ? GPIO_PIN_SET : GPIO_PIN_RESET);
		ps = as ? ps : !ps;
		vTaskDelay( 1000 );
	}
}
