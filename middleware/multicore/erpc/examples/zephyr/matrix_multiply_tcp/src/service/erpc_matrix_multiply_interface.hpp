/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * Generated by erpcgen 1.13.0 on Thu Apr 18 09:59:40 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_erpc_matrix_multiply_interface_hpp_)
#define _erpc_matrix_multiply_interface_hpp_

#include "erpc_matrix_multiply_common.hpp"

namespace erpcShim
{


// Abstract base class for MatrixMultiplyService
class MatrixMultiplyService_interface
{
    public:
        static const uint8_t m_serviceId = 1;
        static const uint8_t m_erpcMatrixMultiplyId = 1;

        virtual ~MatrixMultiplyService_interface(void);

        virtual void erpcMatrixMultiply(Matrix matrix1, Matrix matrix2, Matrix result_matrix) = 0;
private:
};
} // erpcShim


#endif // _erpc_matrix_multiply_interface_hpp_
