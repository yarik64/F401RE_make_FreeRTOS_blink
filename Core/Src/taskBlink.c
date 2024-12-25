// taskBlink.c

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

void vGreenBlinkTask( void *pvParametrs ) {
	for( ;; ) {
		// P8OUT ^= BIT7;
		// HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		HAL_GPIO_WritePin(
				GPIOE,
				GPIO_PIN_8,
				GPIO_PIN_RESET);

		// Выполнить задержку в 700 FreeRTOS тиков. Величина одного тика задана в FreeRTOSConfig.h и как правило составляет 1мс.
		vTaskDelay( 700 );
	}
}

void vRedBlinkTask( void *pvParametrs ) {
	for( ;; ) {
		// P8OUT ^= BIT6;
		// HAL_GPIO_TogglePin(LD2_GPIO_Port, LD3_Pin);
		HAL_GPIO_WritePin(
				GPIOE,
				GPIO_PIN_9,
				GPIO_PIN_RESET);

		// Выполнить задержку в 1000 FreeRTOS тиков. Величина одного тика задана в FreeRTOSConfig.h и как правило составляет 1мс.
		vTaskDelay( 1000 );
	}
}
