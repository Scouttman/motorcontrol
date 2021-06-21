#include "flash_writer.h"
#include "gpio.h"



void flash_writer_init(FlashWriter *fw, uint32_t sector) {
	fw->base = FLASH_USER_START_ADDR;
	fw->ready = false;
}
bool flash_writer_ready(FlashWriter fw) {
    return fw.ready;
}

void flash_writer_open(FlashWriter * fw) {
	HAL_FLASH_Unlock();
	////    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR  | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
	//    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR  | FLASH_FLAG_WRPERR  | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR);
	//
	//    FLASH_EraseSector(__SECTORS[fw->sector], VoltageRange_3);

	/* Clear OPTVERR bit set on virgin samples */
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);

	/* Get the bank */
	uint32_t BankNumber = GetBank(FLASH_USER_START_ADDR);

	/* Fill EraseInit structure*/
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_MASSERASE;
	EraseInitStruct.Banks     = BankNumber;

	uint32_t PAGEError = 0;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
	{
	}
	fw->ready = true;
}

void flash_writer_write_int(FlashWriter fw, uint32_t index, int x) {
    union UN {int a; uint32_t b;};
    union UN un;
    un.a = x;
//    FLASH_ProgramWord(fw.base + 4 * index, un.b);
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, fw.base + 4 * index, un.b) == HAL_OK)
	{
	}
}

void flash_writer_write_uint(FlashWriter fw, uint32_t index, unsigned int x) {
	//FLASH_ProgramWord(fw.base + 4 * index, x);
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, fw.base + 4 * index, x) == HAL_OK)
	{
	}
}

void flash_writer_write_float(FlashWriter fw, uint32_t index, float x) {
    union UN {float a; uint32_t b;};
    union UN un;
    un.a = x;
//    FLASH_ProgramWord(fw.base + 4 * index, un.b);
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, fw.base + 4 * index, un.b) == HAL_OK)
	{
	}
}

void flash_writer_close(FlashWriter * fw) {
    HAL_FLASH_Lock();
    fw->ready = false;
}

int flash_read_int(FlashWriter fw, uint32_t index) {
    return *(int*) (4 * index);
}

uint32_t flash_read_uint(FlashWriter fw, uint32_t index) {
    return *(uint32_t*) (4 * index);
}

float flash_read_float(FlashWriter fw, uint32_t index) {
    return *(float*) (4 * index);
}

/**
  * @brief  Gets the bank of a given address
  * @param  Addr: Address of the FLASH Memory
  * @retval The bank of a given address
  */
uint32_t GetBank(uint32_t Addr)
{
  return FLASH_BANK_1;
}

void flash_error(){
	while (1)
	{
	  /* Make LED2 blink (100ms on, 2s off) to indicate error in Erase operation */
	  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	  HAL_Delay(2000);
	}
}


