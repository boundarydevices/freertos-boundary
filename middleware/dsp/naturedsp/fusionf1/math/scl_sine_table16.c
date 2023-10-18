/* ------------------------------------------------------------------------ */
/* Copyright (c) 2016 by Cadence Design Systems, Inc. ALL RIGHTS RESERVED.  */
/* These coded instructions, statements, and computer programs (�Cadence    */
/* Libraries�) are the copyrighted works of Cadence Design Systems Inc.	    */
/* Cadence IP is licensed for use with Cadence processor cores only and     */
/* must not be used for any other processors and platforms. Your use of the */
/* Cadence Libraries is subject to the terms of the license agreement you   */
/* have entered into with Cadence Design Systems, or a sublicense granted   */
/* to you by a direct Cadence licensee.                                     */
/* ------------------------------------------------------------------------ */
/*  IntegrIT, Ltd.   www.integrIT.com, info@integrIT.com                    */
/*                                                                          */
/* DSP Library                                                              */
/*                                                                          */
/* This library contains copyrighted materials, trade secrets and other     */
/* proprietary information of IntegrIT, Ltd. This software is licensed for  */
/* use with Cadence processor cores only and must not be used for any other */
/* processors and platforms. The license to use these sources was given to  */
/* Cadence, Inc. under Terms and Condition of a Software License Agreement  */
/* between Cadence, Inc. and IntegrIT, Ltd.                                 */
/* ------------------------------------------------------------------------ */
/*          Copyright (C) 2015-2016 IntegrIT, Limited.                      */
/*                      All Rights Reserved.                                */
/* ------------------------------------------------------------------------ */
#include "scl_sine_table16.h"
#include "common.h"
#ifdef COMPILER_MSVC

/* -------------------------------------------------
	sine table: contains packed cos/sin 
	
	MATLAB CODE:
	phase=(0:512-1)/512*(2*pi);
	tbl=S_round_l(sin(phase)*32768.);
   	tbl = (max(min(tbl,32767),-32768));
	tbl=bitand((tbl+65536),65535);
	for k=1:16:length(tbl)
		fprintf(1,'0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,0x%04x,\n',tbl(k:k+16));
	end

------------------------------------------------ */
const uint16_t _declspec(align(16)) sine_table16[] =
#else
const uint16_t                     sine_table16[] __attribute__((aligned(16))) =
#endif
{
0x0   ,0x192 ,0x324 ,0x4b6 ,0x648 ,0x7d9 ,0x96b ,0xafb ,0xc8c ,0xe1c ,0xfab ,0x113a,0x12c8,0x1455,0x15e2,0x176e,
0x18f9,0x1a83,0x1c0c,0x1d93,0x1f1a,0x209f,0x2224,0x23a7,0x2528,0x26a8,0x2827,0x29a4,0x2b1f,0x2c99,0x2e11,0x2f87,
0x30fc,0x326e,0x33df,0x354e,0x36ba,0x3825,0x398d,0x3af3,0x3c57,0x3db8,0x3f17,0x4074,0x41ce,0x4326,0x447b,0x45cd,
0x471d,0x486a,0x49b4,0x4afb,0x4c40,0x4d81,0x4ec0,0x4ffb,0x5134,0x5269,0x539b,0x54ca,0x55f6,0x571e,0x5843,0x5964,
0x5a82,0x5b9d,0x5cb4,0x5dc8,0x5ed7,0x5fe4,0x60ec,0x61f1,0x62f2,0x63ef,0x64e9,0x65de,0x66d0,0x67bd,0x68a7,0x698c,
0x6a6e,0x6b4b,0x6c24,0x6cf9,0x6dca,0x6e97,0x6f5f,0x7023,0x70e3,0x719e,0x7255,0x7308,0x73b6,0x7460,0x7505,0x75a6,
0x7642,0x76d9,0x776c,0x77fb,0x7885,0x790a,0x798a,0x7a06,0x7a7d,0x7aef,0x7b5d,0x7bc6,0x7c2a,0x7c89,0x7ce4,0x7d3a,
0x7d8a,0x7dd6,0x7e1e,0x7e60,0x7e9d,0x7ed6,0x7f0a,0x7f38,0x7f62,0x7f87,0x7fa7,0x7fc2,0x7fd9,0x7fea,0x7ff6,0x7ffe,
0x7fff,0x7ffe,0x7ff6,0x7fea,0x7fd9,0x7fc2,0x7fa7,0x7f87,0x7f62,0x7f38,0x7f0a,0x7ed6,0x7e9d,0x7e60,0x7e1e,0x7dd6,
0x7d8a,0x7d3a,0x7ce4,0x7c89,0x7c2a,0x7bc6,0x7b5d,0x7aef,0x7a7d,0x7a06,0x798a,0x790a,0x7885,0x77fb,0x776c,0x76d9,
0x7642,0x75a6,0x7505,0x7460,0x73b6,0x7308,0x7255,0x719e,0x70e3,0x7023,0x6f5f,0x6e97,0x6dca,0x6cf9,0x6c24,0x6b4b,
0x6a6e,0x698c,0x68a7,0x67bd,0x66d0,0x65de,0x64e9,0x63ef,0x62f2,0x61f1,0x60ec,0x5fe4,0x5ed7,0x5dc8,0x5cb4,0x5b9d,
0x5a82,0x5964,0x5843,0x571e,0x55f6,0x54ca,0x539b,0x5269,0x5134,0x4ffb,0x4ec0,0x4d81,0x4c40,0x4afb,0x49b4,0x486a,
0x471d,0x45cd,0x447b,0x4326,0x41ce,0x4074,0x3f17,0x3db8,0x3c57,0x3af3,0x398d,0x3825,0x36ba,0x354e,0x33df,0x326e,
0x30fc,0x2f87,0x2e11,0x2c99,0x2b1f,0x29a4,0x2827,0x26a8,0x2528,0x23a7,0x2224,0x209f,0x1f1a,0x1d93,0x1c0c,0x1a83,
0x18f9,0x176e,0x15e2,0x1455,0x12c8,0x113a,0xfab ,0xe1c ,0xc8c ,0xafb ,0x96b ,0x7d9 ,0x648 ,0x4b6 ,0x324 ,0x192 ,
0x0   ,0xfe6e,0xfcdc,0xfb4a,0xf9b8,0xf827,0xf695,0xf505,0xf374,0xf1e4,0xf055,0xeec6,0xed38,0xebab,0xea1e,0xe892,
0xe707,0xe57d,0xe3f4,0xe26d,0xe0e6,0xdf61,0xdddc,0xdc59,0xdad8,0xd958,0xd7d9,0xd65c,0xd4e1,0xd367,0xd1ef,0xd079,
0xcf04,0xcd92,0xcc21,0xcab2,0xc946,0xc7db,0xc673,0xc50d,0xc3a9,0xc248,0xc0e9,0xbf8c,0xbe32,0xbcda,0xbb85,0xba33,
0xb8e3,0xb796,0xb64c,0xb505,0xb3c0,0xb27f,0xb140,0xb005,0xaecc,0xad97,0xac65,0xab36,0xaa0a,0xa8e2,0xa7bd,0xa69c,
0xa57e,0xa463,0xa34c,0xa238,0xa129,0xa01c,0x9f14,0x9e0f,0x9d0e,0x9c11,0x9b17,0x9a22,0x9930,0x9843,0x9759,0x9674,
0x9592,0x94b5,0x93dc,0x9307,0x9236,0x9169,0x90a1,0x8fdd,0x8f1d,0x8e62,0x8dab,0x8cf8,0x8c4a,0x8ba0,0x8afb,0x8a5a,
0x89be,0x8927,0x8894,0x8805,0x877b,0x86f6,0x8676,0x85fa,0x8583,0x8511,0x84a3,0x843a,0x83d6,0x8377,0x831c,0x82c6,
0x8276,0x822a,0x81e2,0x81a0,0x8163,0x812a,0x80f6,0x80c8,0x809e,0x8079,0x8059,0x803e,0x8027,0x8016,0x800a,0x8002,
0x8000,0x8002,0x800a,0x8016,0x8027,0x803e,0x8059,0x8079,0x809e,0x80c8,0x80f6,0x812a,0x8163,0x81a0,0x81e2,0x822a,
0x8276,0x82c6,0x831c,0x8377,0x83d6,0x843a,0x84a3,0x8511,0x8583,0x85fa,0x8676,0x86f6,0x877b,0x8805,0x8894,0x8927,
0x89be,0x8a5a,0x8afb,0x8ba0,0x8c4a,0x8cf8,0x8dab,0x8e62,0x8f1d,0x8fdd,0x90a1,0x9169,0x9236,0x9307,0x93dc,0x94b5,
0x9592,0x9674,0x9759,0x9843,0x9930,0x9a22,0x9b17,0x9c11,0x9d0e,0x9e0f,0x9f14,0xa01c,0xa129,0xa238,0xa34c,0xa463,
0xa57e,0xa69c,0xa7bd,0xa8e2,0xaa0a,0xab36,0xac65,0xad97,0xaecc,0xb005,0xb140,0xb27f,0xb3c0,0xb505,0xb64c,0xb796,
0xb8e3,0xba33,0xbb85,0xbcda,0xbe32,0xbf8c,0xc0e9,0xc248,0xc3a9,0xc50d,0xc673,0xc7db,0xc946,0xcab2,0xcc21,0xcd92,
0xcf04,0xd079,0xd1ef,0xd367,0xd4e1,0xd65c,0xd7d9,0xd958,0xdad8,0xdc59,0xdddc,0xdf61,0xe0e6,0xe26d,0xe3f4,0xe57d,
0xe707,0xe892,0xea1e,0xebab,0xed38,0xeec6,0xf055,0xf1e4,0xf374,0xf505,0xf695,0xf827,0xf9b8,0xfb4a,0xfcdc,0xfe6e,
0x0   ,0x192
};
