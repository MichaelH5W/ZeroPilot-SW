/**
 * Contains helper functions specific to the stm32 target
 */

#include "Status.hpp"

#if STM32F030xC
#include "stm32f0xx_hal.h"
#elif STM32F7xx
#include "stm32f7xx_hal.h"
#endif

StatusCode get_status_code(HAL_StatusTypeDef status) {
	switch (status) {
		case HAL_OK: return STATUS_CODE_OK;
		case HAL_BUSY: return STATUS_CODE_RESOURCE_EXHAUSTED;
		case HAL_TIMEOUT: return STATUS_CODE_TIMEOUT;
		default: return STATUS_CODE_INTERNAL_ERROR;
	}
}