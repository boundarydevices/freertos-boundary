/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FLEXSPI_OCTAL_FLASH_OPS_H_
#define _FLEXSPI_OCTAL_FLASH_OPS_H_
#include "app.h"

#ifndef CUSTOM_LUT_LENGTH
#define CUSTOM_LUT_LENGTH 64
#endif

#ifndef NOR_CMD_LUT_SEQ_IDX_READ
#define NOR_CMD_LUT_SEQ_IDX_READ 0
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_READSTATUS
#define NOR_CMD_LUT_SEQ_IDX_READSTATUS 1
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_WRITEENABLE
#define NOR_CMD_LUT_SEQ_IDX_WRITEENABLE 2
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_READID_SPI
#define NOR_CMD_LUT_SEQ_IDX_READID_SPI 3
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_WRITEENABLE_OPI
#define NOR_CMD_LUT_SEQ_IDX_WRITEENABLE_OPI 4
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_ERASESECTOR
#define NOR_CMD_LUT_SEQ_IDX_ERASESECTOR 5
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_CONFIG
#define NOR_CMD_LUT_SEQ_IDX_CONFIG 6
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM
#define NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM 7
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_ENTEROPI
#define NOR_CMD_LUT_SEQ_IDX_ENTEROPI 8
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_WRITE
#define NOR_CMD_LUT_SEQ_IDX_WRITE 9
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI
#define NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI 10
#endif
#ifndef NOR_CMD_LUT_SEQ_IDX_CHIPERASE
#define NOR_CMD_LUT_SEQ_IDX_CHIPERASE 11
#endif

status_t flexspi_nor_flash_erase_sector(FLEXSPI_Type *base, uint32_t address);
status_t flexspi_nor_flash_page_program(FLEXSPI_Type *base, uint32_t dstAddr, const uint32_t *src);
status_t flexspi_nor_get_id(FLEXSPI_Type *base, uint8_t *vendorId);
status_t flexspi_nor_enable_octal_mode(FLEXSPI_Type *base);
status_t flexspi_nor_flash_init(FLEXSPI_Type *base, uint8_t *id);
status_t flexspi_nor_exec_op(FLEXSPI_Type *base,
                             uint32_t deviceAddr,
                             flexspi_port_t port,
                             flexspi_command_type_t cmdType,
                             uint8_t seqIndex,
                             uint8_t seqNumber,
                             uint32_t *data,
                             size_t dataSize);
status_t flexspi_nor_write_enable(FLEXSPI_Type *base, uint32_t baseAddr, bool enableOctal);
status_t flexspi_nor_wait_bus_busy(FLEXSPI_Type *base, bool enableOctal);

#endif
