/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "app.h"
#include "fsl_flexspi.h"
#include "fsl_spi_nor.h"
#include "flexspi_octal_flash_ops.h"

const uint32_t defaultLUTOctalMode_ADESTO[CUSTOM_LUT_LENGTH] = {

    /*  OPI DDR fast read */
    [4 * NOR_CMD_LUT_SEQ_IDX_READ + 0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                         kFLEXSPI_8PAD,
                                                         SPINOR_OP_READ_FAST,
                                                         kFLEXSPI_Command_RADDR_DDR,
                                                         kFLEXSPI_8PAD,
                                                         SPINOR_ADDRESS_32_BITS),
    [4 * NOR_CMD_LUT_SEQ_IDX_READ + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_DUMMY_DDR,
                                                         kFLEXSPI_8PAD,
                                                         SPINOR_DUMMY_CYCLE_NUMBER_8,
                                                         kFLEXSPI_Command_READ_DDR,
                                                         kFLEXSPI_8PAD,
                                                         SPINOR_DATA_SIZE_4_BYTES),

    /* Read status register - SDR SPI Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                           kFLEXSPI_1PAD,
                                                           SPINOR_OP_RDSR,
                                                           kFLEXSPI_Command_READ_SDR,
                                                           kFLEXSPI_1PAD,
                                                           SPINOR_DATA_SIZE_4_BYTES),

    /* Default config is for global unprotect entire memory - SDR SPI Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_CONFIG] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                       kFLEXSPI_1PAD,
                                                       SPINOR_OP_WRSR,
                                                       kFLEXSPI_Command_WRITE_SDR,
                                                       kFLEXSPI_1PAD,
                                                       SPINOR_DATA_SIZE_4_BYTES),

    /* Write Enable - SDR SPI Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_WRITEENABLE] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, SPINOR_OP_WREN, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

    /* Read ID with SDR SPI Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_READID_SPI] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                           kFLEXSPI_1PAD,
                                                           SPINOR_OP_RDID,
                                                           kFLEXSPI_Command_READ_SDR,
                                                           kFLEXSPI_1PAD,
                                                           SPINOR_DATA_SIZE_4_BYTES),

    /*  Write Enable - OPI Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_WRITEENABLE_OPI] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_WREN, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

    /*  Erase Sector - OPI DDR Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_ERASESECTOR] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                            kFLEXSPI_8PAD,
                                                            SPINOR_OP_BE_4K,
                                                            kFLEXSPI_Command_RADDR_DDR,
                                                            kFLEXSPI_8PAD,
                                                            SPINOR_ADDRESS_32_BITS),

    /*  Erase Chip - OPI Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_CHIPERASE] = FLEXSPI_LUT_SEQ(
        kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_CHIP_ERASE, kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0),

    /*  Program - OPI DDR Mode */
    [4 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM]     = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                            kFLEXSPI_8PAD,
                                                            SPINOR_OP_PP,
                                                            kFLEXSPI_Command_RADDR_DDR,
                                                            kFLEXSPI_8PAD,
                                                            SPINOR_ADDRESS_32_BITS),
    [4 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM + 1] = FLEXSPI_LUT_SEQ(
        kFLEXSPI_Command_WRITE_DDR, kFLEXSPI_8PAD, SPINOR_DATA_SIZE_4_BYTES, kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0),

    /* Enter OPI mode(Octal Mode) - SPI */
    [4 * NOR_CMD_LUT_SEQ_IDX_ENTEROPI] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                         kFLEXSPI_1PAD,
                                                         SPINOR_OP_ENTER_OCTAL_MODE_ADESTO,
                                                         kFLEXSPI_Command_STOP,
                                                         kFLEXSPI_1PAD,
                                                         0),

    /*  Dummy write, do nothing when AHB write command is triggered. */
    [4 * NOR_CMD_LUT_SEQ_IDX_WRITE] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0x0, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0x0),

    /*  Read status register using Octal DDR read */
    [4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI]     = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR,
                                                               kFLEXSPI_8PAD,
                                                               SPINOR_OP_RDSR,
                                                               kFLEXSPI_Command_DUMMY_DDR,
                                                               kFLEXSPI_8PAD,
                                                               SPINOR_DUMMY_CYCLE_NUMBER_4),
    [4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI + 1] = FLEXSPI_LUT_SEQ(
        kFLEXSPI_Command_READ_DDR, kFLEXSPI_8PAD, SPINOR_DATA_SIZE_4_BYTES, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0x0),
};
