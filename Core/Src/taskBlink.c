// taskBlink.c

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stdbool.h"

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
	for(;;) {
		if ButtonPush {
		HAL_GPIO_WritePin(
				GPIOC,
				GPIO_PIN_13,
				ps ? GPIO_PIN_SET : GPIO_PIN_RESET);
		ps = !ps;
		vTaskDelay( 1000 );
	}
	}
}
