/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_SPI_NOR_H_
#define _FSL_SPI_NOR_H_

#define BIT(n)         (1U << (n))

#define SPI_NOR_MAX_ID_LEN (10)

#define CFI_MFR_ANY          0xFFFF
#define CFI_ID_ANY           0xFFFF
#define CFI_MFR_CONTINUATION 0x007F
#define CFI_CONTINUATION 0x7F

#define CFI_MFR_AMD      0x0001
#define CFI_MFR_AMIC     0x0037
#define CFI_MFR_ATMEL    0x001F
#define CFI_MFR_EON      0x001C
#define CFI_MFR_FUJITSU  0x0004
#define CFI_MFR_HYUNDAI  0x00AD
#define CFI_MFR_INTEL    0x0089
#define CFI_MFR_MACRONIX 0x00C2
#define CFI_MFR_NEC      0x0010
#define CFI_MFR_PMC      0x009D
#define CFI_MFR_SAMSUNG  0x00EC
#define CFI_MFR_SHARP    0x00B0
#define CFI_MFR_SST      0x00BF
#define CFI_MFR_ST       0x0020 /* STMicroelectronics */
#define CFI_MFR_MICRON   0x002C /* Micron */
#define CFI_MFR_TOSHIBA  0x0098
#define CFI_MFR_WINBOND  0x00DA

/*
 * Manufacturer IDs
 *
 * The first byte returned from the flash after sending opcode SPINOR_OP_RDID.
 * Sometimes these are the same as CFI IDs, but sometimes they aren't.
 */
#define SNOR_MFR_ATMEL      CFI_MFR_ATMEL
#define SNOR_MFR_GIGADEVICE 0xc8
#define SNOR_MFR_INTEL      CFI_MFR_INTEL
#define SNOR_MFR_ST         CFI_MFR_ST     /* ST Micro <--> Micron */
#define SNOR_MFR_MICRON     CFI_MFR_MICRON /* ST Micro <--> Micron */
#define SNOR_MFR_ISSI       CFI_MFR_PMC
#define SNOR_MFR_MACRONIX   CFI_MFR_MACRONIX
#define SNOR_MFR_SPANSION   CFI_MFR_AMD
#define SNOR_MFR_SST        CFI_MFR_SST
#define SNOR_MFR_WINBOND    0xef /* Also used by some Spansion */
#define SNOR_MFR_CYPRESS    0x34
#define SNOR_MFR_ADESTO     0x43

/*
 * Note on opcode nomenclature: some opcodes have a format like
 * SPINOR_OP_FUNCTION{4,}_x_y_z. The numbers x, y, and z stand for the number
 * of I/O lines used for the opcode, address, and data (respectively). The
 * FUNCTION has an optional suffix of '4', to represent an opcode which
 * requires a 4-byte (32-bit) address.
 */

/* Flash opcodes. */
#define SPINOR_OP_WREN         0x06 /* Write enable */
#define SPINOR_OP_RDSR         0x05 /* Read status register */
#define SPINOR_OP_RDSR1        0x05 /* Read status register byte 1 */
#define SPINOR_OP_WRSR         0x01 /* Write status register */
#define SPINOR_OP_WRSR1        0x01 /* Write status register byte 1 */
#define SPINOR_OP_RDSR2        0x3f /* Read status register byte 2 */
#define SPINOR_OP_WRSR2        0x3e /* Write status register byte 2 */
#define SPINOR_OP_READ         0x03 /* Read data bytes (low frequency) */
#define SPINOR_OP_READ_FAST    0x0b /* Read data bytes (high frequency) */
#define SPINOR_OP_READ_1_1_2   0x3b /* Read data bytes (Dual Output SPI) */
#define SPINOR_OP_READ_1_2_2   0xbb /* Read data bytes (Dual I/O SPI) */
#define SPINOR_OP_READ_1_1_4   0x6b /* Read data bytes (Quad Output SPI) */
#define SPINOR_OP_READ_1_4_4   0xeb /* Read data bytes (Quad I/O SPI) */
#define SPINOR_OP_READ_1_1_8   0x8b /* Read data bytes (Octal Output SPI) */
#define SPINOR_OP_READ_1_8_8   0xcb /* Read data bytes (Octal I/O SPI) */
#define SPINOR_OP_PP           0x02 /* Page program (up to 256 bytes) */
#define SPINOR_OP_PP_1_1_4     0x32 /* Quad page program */
#define SPINOR_OP_PP_1_4_4     0x38 /* Quad page program */
#define SPINOR_OP_PP_1_1_8     0x82 /* Octal page program */
#define SPINOR_OP_PP_1_8_8     0xc2 /* Octal page program */
#define SPINOR_OP_BE_4K        0x20 /* Erase 4KiB block */
#define SPINOR_OP_BE_4K_PMC    0xd7 /* Erase 4KiB block on PMC chips */
#define SPINOR_OP_BE_32K       0x52 /* Erase 32KiB block */
#define SPINOR_OP_CHIP_ERASE   0xc7 /* Erase whole flash chip, 0xc7 or 0x60 */
#define SPINOR_OP_SE           0xd8 /* Sector erase (usually 64KiB) */
#define SPINOR_OP_RDID         0x9f /* Read JEDEC ID */
#define SPINOR_OP_RDSFDP       0x5a /* Read SFDP */
#define SPINOR_OP_RDCR         0x35 /* Read configuration register */
#define SPINOR_OP_RDFSR        0x70 /* Read flag status register */
#define SPINOR_OP_CLFSR        0x50 /* Clear flag status register */
#define SPINOR_OP_RDEAR        0xc8 /* Read Extended Address Register */
#define SPINOR_OP_WREAR        0xc5 /* Write Extended Address Register */
#define SPINOR_OP_SRSTEN       0x66 /* Software Reset Enable */
#define SPINOR_OP_SRST         0x99 /* Software Reset */

/* ADESTO flash opcode */
#define SPINOR_OP_WRSR2_ADESTO 0x31 /* Write status register byte 2 for ADES octal nor flash(such as: ATXP032) */
#define SPINOR_OP_ENTER_OCTAL_MODE_ADESTO 0xe8 /* Enter Octal Mode */
#define SPINOR_OP_RETURN_TO_SPI_FROM_OCTAL_ADESTO \
    0xff /* Return to Standard SPI Mode from Octal Mode(ADESTO support the command) */

/* GigaDevice flash opcode */
#define SPINOR_OP_RD_NONVOLATILE_CFG_GIGADEVICE 0xb5 /* Read Nonvolatile Configuration Register (from GigaDevice GD25LX256E) */
#define SPINOR_OP_RD_VOLATILE_CFG_GIGADEVICE 0x85 /* Read volatile Configuration Register (from GigaDevice GD25LX256E) */
#define SPINOR_OP_WR_NONVOLATILE_CFG_GIGADEVICE 0xb1 /* Write Nonvolatile Configuration Register (from GigaDevice GD25LX256E) */
#define SPINOR_OP_WR_VOLATILE_CFG_GIGADEVICE 0x81 /* Write volatile Configuration Register (from GigaDevice GD25LX256E) */
#define SPINOR_OP_ENABLE_4_BYTE_ADDR_MODE_GIGADEVICE 0xb7 /* Enable 4-Byte Address Mode (from GigaDevice GD25LX256E) */
#undef SPINOR_OP_DISABLE_4_BYTE_ADDR_MODE_GIGADEVICE
#define SPINOR_OP_DISABLE_4_BYTE_ADDR_MODE_GIGADEVICE 0xe9 /* Disable 4-Byte Address Mode (from GigaDevice GD25LX256E) */
#define SPINOR_OP_SE_20_GIGADEVICE 0x20 /* SECTOR ERASE (from GigaDevice GD25LX256E) */
#define SPINOR_OP_SE_21_GIGADEVICE 0x21 /* SECTOR ERASE (from GigaDevice GD25LX256E) */

/* 4-byte address opcodes - used on Spansion and some Macronix flashes. */
#define SPINOR_OP_READ_4B       0x13 /* Read data bytes (low frequency) */
#define SPINOR_OP_READ_FAST_4B  0x0c /* Read data bytes (high frequency) */
#define SPINOR_OP_READ_1_1_2_4B 0x3c /* Read data bytes (Dual Output SPI) */
#define SPINOR_OP_READ_1_2_2_4B 0xbc /* Read data bytes (Dual I/O SPI) */
#define SPINOR_OP_READ_1_1_4_4B 0x6c /* Read data bytes (Quad Output SPI) */
#define SPINOR_OP_READ_1_4_4_4B 0xec /* Read data bytes (Quad I/O SPI) */
#define SPINOR_OP_READ_1_1_8_4B 0x7c /* Read data bytes (Octal Output SPI) */
#define SPINOR_OP_READ_1_8_8_4B 0xcc /* Read data bytes (Octal I/O SPI) */
#define SPINOR_OP_PP_4B         0x12 /* Page program (up to 256 bytes) */
#define SPINOR_OP_PP_1_1_4_4B   0x34 /* Quad page program */
#define SPINOR_OP_PP_1_4_4_4B   0x3e /* Quad page program */
#define SPINOR_OP_PP_1_1_8_4B   0x84 /* Octal page program */
#define SPINOR_OP_PP_1_8_8_4B   0x8e /* Octal page program */
#define SPINOR_OP_BE_4K_4B      0x21 /* Erase 4KiB block */
#define SPINOR_OP_BE_32K_4B     0x5c /* Erase 32KiB block */
#define SPINOR_OP_SE_4B         0xdc /* Sector erase (usually 64KiB) */

#define SPINOR_ADDRESS_32_BITS (0x20) /* 4 byte address */
#define SPINOR_ADDRESS_24_BITS (0x18) /* 3 byte address */

#define SPINOR_DUMMY_CYCLE_NUMBER_1 (0x1) /* 1 dummy clock cycle */
#define SPINOR_DUMMY_CYCLE_NUMBER_2 (0x2) /* 2 dummy clock cycle */
#define SPINOR_DUMMY_CYCLE_NUMBER_4 (0x4) /* 4 dummy clock cycle */
#define SPINOR_DUMMY_CYCLE_NUMBER_8 (0x8) /* 8 dummy clock cycle */
#define SPINOR_DUMMY_CYCLE_NUMBER_16 (0x16) /* 16 dummy clock cycle */

#define SPINOR_DATA_SIZE_1_BYTES (0x1) /* data size is 1 bytes */
#define SPINOR_DATA_SIZE_4_BYTES (0x4) /* data size is 4 bytes */

/* Status Register bits. */
#define SR_WIP BIT(0) /* Write in progress */
#define SR_WEL BIT(1) /* Write enable latch */
/* meaning of other SR_* bits may differ between vendors */
#define SR_BP0  BIT(2) /* Block protect 0 */
#define SR_BP1  BIT(3) /* Block protect 1 */
#define SR_BP2  BIT(4) /* Block protect 2 */
#define SR_TB   BIT(5) /* Top/Bottom protect */
#define SR_SRWD BIT(7) /* SR write protect */
/* Spansion/Cypress specific status bits */
#define SR_E_ERR BIT(5)
#define SR_P_ERR BIT(6)

/*
 * Adesto specific Status/Control Register Byte 1 bits
 * 0: Sector Protection Registers are unlocked(default)
 * 1: Sector Protection Registers are locked.
 */
#define SR_SPRL_ADESTO BIT(7)
/*
 * DPDS: Deep Power-Down Status
 * 0: Device is in Active or Standby Mode
 * 1: Device is in Deep Power-Down Mode
 */
#define SR_DPDS_ADESTO BIT(6)
/*
 * EPE: Program/Erase Error
 * 0: Erase or Program operation was successful
 * 1: Erase or Program error detected
 */
#define SR_EPE_ADESTO BIT(5)
/*
 * UDPDS: Ultra-Deep Power-Down Status
 * 0: Device is in Active, Standby or DPD Mode
 * 1: Device is in Ultra-Deep Power-Down Mode
 */
#define SR_UDPDS_ADESTO BIT(4)
/*
 * SWP: Software Protection Status
 * 00: All sectors are software unprotected(all Sector Protection Registers are 0)
 * 01: Some sectors are software protected. Read individual Sector Protection Registers to determine which sectors are protected.
 * 10: Reserved are protected
 * 11: All sectors are software protected(all Sector Protection Regaters are 1 - default)
 */
#define SR_SWP1_ADESTO BIT(3)
#define SR_SWP0_ADESTO BIT(2)
#define SR_SWP_ALL_SECTORS_UNPROTECTED (0)
#define SR_SWP_SOME_SECTORS_PROTECTED (SR_SWP0_ADESTO)
#define SR_SWP_ALL_SECTORS_PROTECTED (SR_SWP1_ADESTO | SR_SWP0_ADESTO)

#define SR_QUAD_EN_MX BIT(6) /* Macronix Quad I/O */

/* Enhanced Volatile Configuration Register bits */
#define EVCR_QUAD_EN_MICRON BIT(7) /* Micron Quad I/O */

/* Flag Status Register bits */
#define FSR_READY  BIT(7) /* Device status, 0 = Busy, 1 = Ready */
#define FSR_E_ERR  BIT(5) /* Erase operation status */
#define FSR_P_ERR  BIT(4) /* Program operation status */
#define FSR_PT_ERR BIT(1) /* Protection error bit */

/* Flag Status Register bits of GigaDevice */
#define FSR_ADS_GIGADEVICE BIT(0) /* Flash is in 3-Byte address mode when ADS=0(default), and in 4-Byte address mode when ADS=1 */

/* Configuration Register bits. */
#define CR_QUAD_EN_SPAN BIT(1) /* Spansion Quad I/O */

/*
 * Configuration Register 2 of MACRONIX
 * DOPI: DTR(Double Transfer Rate) OPI Enable
 * SOPI: STR(Single Transfer Rate) OPI Enable
 * 00 - SPI
 * 01 - STR OPI enable
 * 10 - DTR OPI enable
 * 11 - inhibit
 */
#define CR2_DOPI_MACRONIX BIT(1)
#define CR2_SOPI_MACRONIX BIT(0)
#define CR2_DTR_OPI_ENABLE_MACRONIX (CR2_DOPI_MACRONIX)
#define CR2_STR_OPI_ENABLE_MACRONIX (CR2_SOPI_MACRONIX)


/* Status Register 2 bits. */
#define SR2_QUAD_EN_BIT7 BIT(7)

/*
 * Adesto Status/Control Register Byte 2 bits
 * SDR/DDR: Select SDR or DDR mode
 * 0: SDR - Single data rate mode(Default)
 * 1: DDR - Dual data rate mode
 */
#define SR2_SDR_DDR_ADESTO BIT(7)
/*
 * AUDPD: Audo Ultra-Deep Power-Down enable
 * ADPD: Auto Deep Power-Down enable
 * 00: Normal mode - Go to Standby after Program/Erase
 * 01: ADPD Set: Go to DPD after Program/Erase
 * 10: AUDPD Set: Go to UDPD after Program/Erase
 * 11: Illegal combination - Reserved for future use
 */
#define SR2_AUDPD_ADESTO BIT(6)
#define SR2_ADPD_ADESTO BIT(5)
/*
 * OME: Octal mode enable
 * 0: SPI mode enabled
 * 1: Octal mode enabled
 */
#define SR2_OME_ADESTO BIT(3)

/* Address of Nonvolatile/Volatile Configuration Register of GigaDevice(GD25LX256E) */
#define SPINOR_VOLATILE_CFG_REG_ADDR_IO_MODE_GIGADEVICE 0x0
#define SPINOR_VOLATILE_CFG_REG_ADDR_DUMMY_CYCLE_CFG_GIGADEVICE 0x1

#define SPINOR_IO_MODE_SPI_WITH_DQS_GIGADEVICE (0xff) /* SPI with DQS(Default) */
#define SPINOR_IO_MODE_SPI_WITHOUT_DQS_GIGADEVICE (0xdf) /* SPI without DQS */
#define SPINOR_IO_MODE_OCTAL_DTR_WITH_DQS_GIGADEVICE (0xe7) /* OCTAL DTR with DQS */
#define SPINOR_IO_MODE_OCTAL_DTR_WITHOUT_DQS_GIGADEVICE (0xc7) /* OCTAL DTR without DQS */
#define SPINOR_IO_MODE_OCTAL_STR_WITH_DQS_GIGADEVICE (0xb7) /* OCTAL STR with DQS */
#define SPINOR_IO_MODE_OCTAL_STR_WITHOUT_DQS_GIGADEVICE (0x97) /* OCTAL STR without DQS */

/* Device Operation Mode */
typedef enum
{
    SPINOR_SPI_MODE = 0, /* Include Standard SPI Mode, Octal SPI Mode, Octal DTR SPI Mode */
    SPINOR_OCTAL_SPI_MODE = 1, /* Octal SPI Mode */
    SPINOR_OCTAL_DTR_SPI_MODE = 2, /* Octal DTR SPI Mode */
    SPINOR_OPI_MODE = 3, /* Include Standard OPI Mode, DTR OPI Mode */
    SPINOR_DTR_OPI_MODE = 4, /* DTR OPI Mode */
} spi_mode;

typedef struct
{
    uint16_t manufacturerId; /* Manufacturer ID */
    spi_mode spiMode; /* nor flash operation Mode */
    bool addrMode; /* Flash is in 3-Byte Address Mode when addrMode=0(FALSE), Flash is in 4-Byte Address Mode when addrMode=1(TRUE) */
} spi_nor_flash_state;
#endif
