/*
 * flash_writer.h
 *
 *  Created on: Apr 12, 2020
 *      Author: Ben
 */

#ifndef INC_FLASH_WRITER_H_
#define INC_FLASH_WRITER_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx.h"
#include "stm32g4xx_hal_flash.h"
#include "stdbool.h"

/* Base address of the Flash sectors */
//#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbytes */
//#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
//#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
//#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbytes */
//#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbytes */

//static uint32_t __SECTOR_ADDRS[] = {ADDR_FLASH_SECTOR_0, ADDR_FLASH_SECTOR_1, ADDR_FLASH_SECTOR_2, ADDR_FLASH_SECTOR_3,
//                             ADDR_FLASH_SECTOR_4, ADDR_FLASH_SECTOR_5, ADDR_FLASH_SECTOR_6, ADDR_FLASH_SECTOR_7};
//static uint32_t __SECTORS[] = {FLASH_Sector_0, FLASH_Sector_1, FLASH_Sector_2, FLASH_Sector_3,
//                             FLASH_Sector_4, FLASH_Sector_6, FLASH_Sector_6, FLASH_Sector_7};

// Taken from the example FLAHS_FastProgram
#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base @ of Page 0, 2 Kbytes */
#define ADDR_FLASH_PAGE_63    ((uint32_t)0x0801F800) /* Base @ of Page 63, 2 Kbytes */
#define FLASH_USER_START_ADDR   ADDR_FLASH_PAGE_0   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     (ADDR_FLASH_PAGE_63 + FLASH_PAGE_SIZE - 1)   /* End @ of user Flash area */

typedef struct {
	bool ready;
	uint32_t base;
}FlashWriter;

/* Variable used for Erase procedure*/
FLASH_EraseInitTypeDef EraseInitStruct;

//uint32_t BankNumber = 0;
//uint32_t Address = 0, unt32_t PAGEError = 0;

void flash_writer_init(FlashWriter *fw, uint32_t sector);
bool flash_writer_ready(FlashWriter fw);
void flash_writer_open(FlashWriter *fw);
void flash_writer_write_int(FlashWriter fw, uint32_t index, int x);
void flash_writer_write_uint(FlashWriter fw, uint32_t index, unsigned int x);
void flash_writer_write_float(FlashWriter fw, uint32_t index, float x);
void flash_writer_close(FlashWriter *fw);
int flash_read_int(FlashWriter fw, uint32_t index);
uint32_t flash_read_uint(FlashWriter fw, uint32_t index);
float flash_read_float(FlashWriter fw, uint32_t index);
uint32_t GetBank(uint32_t Addr);
void flash_error();

#ifdef __cplusplus
}
#endif

#endif /* INC_FLASH_WRITER_H_ */
