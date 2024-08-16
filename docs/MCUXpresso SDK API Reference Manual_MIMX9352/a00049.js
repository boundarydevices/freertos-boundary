var a00049 =
[
    [ "lpuart_config_t", "a00049.html#a00423", [
      [ "baudRate_Bps", "a00049.html#a09d359de28dc114424b2d702df014d1c", null ],
      [ "parityMode", "a00049.html#ae7ce86796f025a059c973c540d5a94ad", null ],
      [ "dataBitsCount", "a00049.html#a58ce25b71bde98b9c09875481637d120", null ],
      [ "isMsb", "a00049.html#aae9f69c98294d67da66edbce283f029b", null ],
      [ "stopBitCount", "a00049.html#ad133820d48c8f20f3f14194947d0e811", null ],
      [ "txFifoWatermark", "a00049.html#a824836b1509114ff1af39cb6180bfc05", null ],
      [ "rxFifoWatermark", "a00049.html#ab7ccf42982268a314684ef0cc9130daa", null ],
      [ "enableRxRTS", "a00049.html#a25d3592044284b02ce8a99be55f8375e", null ],
      [ "enableTxCTS", "a00049.html#a366656f224548055712aac31b264b30c", null ],
      [ "txCtsSource", "a00049.html#a086040445ae0fd73e4bee0312d7588b9", null ],
      [ "txCtsConfig", "a00049.html#a34c837d6370c91f7589d58e0ccbeeeb6", null ],
      [ "rxIdleType", "a00049.html#accbd00b653a769831310e62f8a9045eb", null ],
      [ "rxIdleConfig", "a00049.html#a00e18786e55ac3057c2bc32b8bc0e361", null ],
      [ "enableTx", "a00049.html#a0d677467cd14ee90f544d688f3dc9b9a", null ],
      [ "enableRx", "a00049.html#a48d3f37a9364c0093083ef843d5d062e", null ]
    ] ],
    [ "lpuart_transfer_t", "a00049.html#a00424", [
      [ "data", "a00049.html#a7c49cf389dea8ad6f674bff6cedd8e37", null ],
      [ "rxData", "a00049.html#a5c7fe6c7d0575874728260e0ee2439df", null ],
      [ "rxData16", "a00049.html#ae62d030524d1f93dc77f1b69d75284b8", null ],
      [ "txData", "a00049.html#a6403edb37a03ed860ac5c2cda4d314be", null ],
      [ "txData16", "a00049.html#a428b040401b4dffe1dc28832777d105c", null ],
      [ "dataSize", "a00049.html#ad269a833a8e8e4cdbc0d485d59e256d8", null ]
    ] ],
    [ "lpuart_handle_t", "a00049.html#a00293", [
      [ "txData", "a00049.html#a9d7a97a2805da5949867d433660a09a7", null ],
      [ "txData16", "a00049.html#a097d764aced5ac1ab1ef0a2c63fddbd3", null ],
      [ "txDataSize", "a00049.html#a2114edec74578fe798a62cf852ab0194", null ],
      [ "txDataSizeAll", "a00049.html#a84153c9f581e7201d5c2a20423a321da", null ],
      [ "rxData", "a00049.html#a6d3fceca5b3bee7f183116ee7b3a3b93", null ],
      [ "rxData16", "a00049.html#a489616e311bcf4f4878e928d90634dfd", null ],
      [ "rxDataSize", "a00049.html#a6b9d688ed6ecbb3b71d6b266bec66edb", null ],
      [ "rxDataSizeAll", "a00049.html#a4ac2cb3c691238ed65a34410ab8f2920", null ],
      [ "rxRingBuffer", "a00049.html#a3eca0396fcb49d3652a40c7cf49024c8", null ],
      [ "rxRingBuffer16", "a00049.html#a66012baf845be47240c66a427ba9e572", null ],
      [ "rxRingBufferSize", "a00049.html#a12cff540159d2fb592e4856957d820cd", null ],
      [ "rxRingBufferHead", "a00049.html#aaffed28a2a686bb90e3238a3d8e597b3", null ],
      [ "rxRingBufferTail", "a00049.html#acecaaa5df8327c5b33815cb7483abd75", null ],
      [ "callback", "a00049.html#a881c1d7231d1ee0bcb3eb5f1447f75a4", null ],
      [ "userData", "a00049.html#ad9f3989cffe26d3ca63d381da36024be", null ],
      [ "txState", "a00049.html#a86fe3c8f354afbe67d28a71068206b26", null ],
      [ "rxState", "a00049.html#a088a1e9a009d852b90fb8390fa7cbbcd", null ],
      [ "isSevenDataBits", "a00049.html#ab87c4083ec1d22d639842729f1b08502", null ],
      [ "is16bitData", "a00049.html#a3a8b8caf97e3ea596717be1e09036584", null ]
    ] ],
    [ "FSL_LPUART_DRIVER_VERSION", "a00049.html#ga0870fb824ece32739bd35f819f8c408e", null ],
    [ "UART_RETRY_TIMES", "a00049.html#gac0f88b67f77fd05f186a5ec940c340bd", null ],
    [ "lpuart_transfer_callback_t", "a00049.html#ga7ab1637091d166aa8b69517350fb05c8", [
      [ "kStatus_LPUART_TxBusy", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26abddb317db7dfffa95856604bfac2a17f", null ],
      [ "kStatus_LPUART_RxBusy", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a98dfeab0a23c81f6b7f2c18acff8cc30", null ],
      [ "kStatus_LPUART_TxIdle", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a079c6d0957d121ce7cd95cf97487dfbb", null ],
      [ "kStatus_LPUART_RxIdle", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a02b8fe84bbfd8c52856b5d48865f7088", null ],
      [ "kStatus_LPUART_TxWatermarkTooLarge", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26abbee969cb0f7b4c49b44b10c4eb583cc", null ],
      [ "kStatus_LPUART_RxWatermarkTooLarge", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26aca81b4d6e2e792c6d841b95ec25daad9", null ],
      [ "kStatus_LPUART_FlagCannotClearManually", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a07d5a5092ded158fe53ea4df940f8bdb", null ],
      [ "kStatus_LPUART_Error", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26af069a1997c3d25588d834ccb33dd35f4", null ],
      [ "kStatus_LPUART_RxRingBufferOverrun", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a45a7ed684f4c31aec8999b3da68d3b5e", null ],
      [ "kStatus_LPUART_RxHardwareOverrun", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26af8ada3eacff87751ec865b4fc584bac1", null ],
      [ "kStatus_LPUART_NoiseError", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a6ccebae2eb859fde044f15f1dd18cba1", null ],
      [ "kStatus_LPUART_FramingError", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a1528dc2aacb3a792a1ecbfbbc7941bc9", null ],
      [ "kStatus_LPUART_ParityError", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26ad42bcd27cb6e04725768c6b98d4cbe0d", null ],
      [ "kStatus_LPUART_BaudrateNotSupport", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26aaa020183f56b7d7f63e22fd5fd8d3df2", null ],
      [ "kStatus_LPUART_IdleLineDetected", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a29540bf056281514eb42c8885f7e2e10", null ],
      [ "kStatus_LPUART_Timeout", "a00049.html#ggaf8654c714018c6241d9ebd01f3fb5a26a0a6368e75ae51755bbd3f451c276c822", null ]
    ] ],
    [ "lpuart_parity_mode_t", "a00049.html#ga6fcd73abf900b8a17dab1f2b1f3f53c7", [
      [ "kLPUART_ParityDisabled", "a00049.html#gga6fcd73abf900b8a17dab1f2b1f3f53c7a0e5bdb8fc4e1010930d05e1490a75b1a", null ],
      [ "kLPUART_ParityEven", "a00049.html#gga6fcd73abf900b8a17dab1f2b1f3f53c7ac92adb3fdf11240ca5dee6c6543b6ff7", null ],
      [ "kLPUART_ParityOdd", "a00049.html#gga6fcd73abf900b8a17dab1f2b1f3f53c7adab63856e98e0715f4ab289ac0da3575", null ]
    ] ],
    [ "lpuart_data_bits_t", "a00049.html#ga9c4d95a2016ff0cb826d50035a1ba216", [
      [ "kLPUART_EightDataBits", "a00049.html#gga9c4d95a2016ff0cb826d50035a1ba216aaa10fe51f0b83d5c0a2e060dab983899", null ],
      [ "kLPUART_SevenDataBits", "a00049.html#gga9c4d95a2016ff0cb826d50035a1ba216a39e919f0523d445c9e35034b15329031", null ]
    ] ],
    [ "lpuart_stop_bit_count_t", "a00049.html#ga7540d87bc3fa8a605d8da53fe08219f0", [
      [ "kLPUART_OneStopBit", "a00049.html#gga7540d87bc3fa8a605d8da53fe08219f0a4304f0ee73a5fabfadfc05ca1fbd3901", null ],
      [ "kLPUART_TwoStopBit", "a00049.html#gga7540d87bc3fa8a605d8da53fe08219f0a6e049e0faaf89ed2dfe493ad8f6c93d4", null ]
    ] ],
    [ "lpuart_transmit_cts_source_t", "a00049.html#gadd3cf9892416c5503dce7f0567e8c41f", [
      [ "kLPUART_CtsSourcePin", "a00049.html#ggadd3cf9892416c5503dce7f0567e8c41fab9dc5632b86f32ceb88d8aa882471bf5", null ],
      [ "kLPUART_CtsSourceMatchResult", "a00049.html#ggadd3cf9892416c5503dce7f0567e8c41fa75ac72fc4281ef68f2a97ff96e90654b", null ]
    ] ],
    [ "lpuart_transmit_cts_config_t", "a00049.html#gafe1039afd48853bd649e23bdfa034540", [
      [ "kLPUART_CtsSampleAtStart", "a00049.html#ggafe1039afd48853bd649e23bdfa034540ad32cfafeb9de4981efcaccfd15787500", null ],
      [ "kLPUART_CtsSampleAtIdle", "a00049.html#ggafe1039afd48853bd649e23bdfa034540afa8f0e420059feab07c6efa7c3ca9d91", null ]
    ] ],
    [ "lpuart_idle_type_select_t", "a00049.html#gac2792920d552d2a9eab5c1b857b695e1", [
      [ "kLPUART_IdleTypeStartBit", "a00049.html#ggac2792920d552d2a9eab5c1b857b695e1a0644f6b95813c520dede56ee3a944267", null ],
      [ "kLPUART_IdleTypeStopBit", "a00049.html#ggac2792920d552d2a9eab5c1b857b695e1a69545f21a3401c126bf295b5cf94225b", null ]
    ] ],
    [ "lpuart_idle_config_t", "a00049.html#ga0a377113a8abdeeb03d68fa749a5eb0c", [
      [ "kLPUART_IdleCharacter1", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0ca955e0bb4d3e75e577eef544b440c24be", null ],
      [ "kLPUART_IdleCharacter2", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0ca270caa8e77b08697404771af82abd131", null ],
      [ "kLPUART_IdleCharacter4", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0cacab443d3d053070635ea1f859b73f34c", null ],
      [ "kLPUART_IdleCharacter8", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0caf125ff40887939add6dd0f42d4485bf3", null ],
      [ "kLPUART_IdleCharacter16", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0cace45d3af9a0c590f053df7bb00e6582a", null ],
      [ "kLPUART_IdleCharacter32", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0ca1daee04c54b7e37ca5e7331a3e1e7374", null ],
      [ "kLPUART_IdleCharacter64", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0cac497a53ed2755d26961f3b72fbd180ed", null ],
      [ "kLPUART_IdleCharacter128", "a00049.html#gga0a377113a8abdeeb03d68fa749a5eb0ca4e080722efa87475f1710f5524e50c67", null ]
    ] ],
    [ "_lpuart_interrupt_enable", "a00049.html#ga199a157d391291a9d003bf23954f9603", [
      [ "kLPUART_LinBreakInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603ade355c45064ff74257d57eb42d475adb", null ],
      [ "kLPUART_RxActiveEdgeInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a43750aac20f72535350c1ab4a1862a3a", null ],
      [ "kLPUART_TxDataRegEmptyInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a0e8bf389f65e5f86a3063dc55b8aae1c", null ],
      [ "kLPUART_TransmissionCompleteInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a0b7f783393a61cce88eab28307e9fe14", null ],
      [ "kLPUART_RxDataRegFullInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a5b4a0893c98bf79d0dad88aeb7714d22", null ],
      [ "kLPUART_IdleLineInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603af3f83c56032b14e50a682857dd7c152d", null ],
      [ "kLPUART_RxOverrunInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a8a29c714eaa6acab06a87314f4f29636", null ],
      [ "kLPUART_NoiseErrorInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603ad1a35bc7e89f170a5b82cb4801b73b5e", null ],
      [ "kLPUART_FramingErrorInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a1b43ca06e0af6b0fcf4b55612363a64d", null ],
      [ "kLPUART_ParityErrorInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a13c12b816605deaabcbc3e6a6db82466", null ],
      [ "kLPUART_Match1InterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a6065cef19fc1ebd279984a1503c129b1", null ],
      [ "kLPUART_Match2InterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a5168efe76104a5fa3794efb2f594aa72", null ],
      [ "kLPUART_TxFifoOverflowInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a1ec2f3da1de23b1fdc9ebc96266ce34a", null ],
      [ "kLPUART_RxFifoUnderflowInterruptEnable", "a00049.html#gga199a157d391291a9d003bf23954f9603a94432948fe51acd5cc1efee2b970166b", null ]
    ] ],
    [ "_lpuart_flags", "a00049.html#ga24bb7ca3f894fe5ff55b9f38bec16c89", [
      [ "kLPUART_TxDataRegEmptyFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89aa765f8ddac00348328f64ad4222d057a", null ],
      [ "kLPUART_TransmissionCompleteFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89ae0539c4cf39d4d1e7839a4896fad2a85", null ],
      [ "kLPUART_RxDataRegFullFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a9bc679bcc20b81768f84b04e499c5a2f", null ],
      [ "kLPUART_IdleLineFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89acf1a40aca38878bc395f9f0b10d8225e", null ],
      [ "kLPUART_RxOverrunFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a994f5f484509133c632215a8b701f8d1", null ],
      [ "kLPUART_NoiseErrorFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a2198232cb9d239f937ab221bbf03259f", null ],
      [ "kLPUART_FramingErrorFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89ad1d40f89cb6aab9c12113586fda7f510", null ],
      [ "kLPUART_ParityErrorFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a2f8d4c03df61bc4678b2ccf1c69eedeb", null ],
      [ "kLPUART_LinBreakFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89ae7bdab3a8c6eb966e2afc605d8b86faf", null ],
      [ "kLPUART_RxActiveEdgeFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89ae89f181d8dbbf5254d6fe843e4cac6d6", null ],
      [ "kLPUART_RxActiveFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a1f14711a74db1cc141b5c2627ee4c799", null ],
      [ "kLPUART_DataMatch1Flag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89add8c5e7785285e805f7066d90ef338f4", null ],
      [ "kLPUART_DataMatch2Flag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a71e5c8e3b81dbe575dfdb258997ed280", null ],
      [ "kLPUART_TxFifoEmptyFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89ad7b809a6e24b93450f93840e698f3f2d", null ],
      [ "kLPUART_RxFifoEmptyFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a82d7e96fff053e5f4a0ead254e3ac5d5", null ],
      [ "kLPUART_TxFifoOverflowFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a58890b43ef6f610690c7cfa842ce0c56", null ],
      [ "kLPUART_RxFifoUnderflowFlag", "a00049.html#gga24bb7ca3f894fe5ff55b9f38bec16c89a0e38f16380ea64d5ca5080793dfbb16e", null ]
    ] ],
    [ "LPUART_SoftwareReset", "a00049.html#ga56e999abbe3a38445582867f6df2665e", null ],
    [ "LPUART_Init", "a00049.html#ga26ce3e5d63d8dd5d317a83f22af9682c", null ],
    [ "LPUART_Deinit", "a00049.html#ga303ff3b77767bafa449d96f1e8c921e0", null ],
    [ "LPUART_GetDefaultConfig", "a00049.html#ga95dfe3c3886692f1fe32023d59708440", null ],
    [ "LPUART_SetBaudRate", "a00049.html#gaf03d9292f8b4cb6e9748cb0bc1db7577", null ],
    [ "LPUART_Enable9bitMode", "a00049.html#gae7e13bb206bd78070737968610437fb1", null ],
    [ "LPUART_SetMatchAddress", "a00049.html#gae4987ccc6a25b2aa8a99a18868fda3eb", null ],
    [ "LPUART_EnableMatchAddress", "a00049.html#gaafe7ddb53960e2f4cd7ba2a01f00982e", null ],
    [ "LPUART_SetRxFifoWatermark", "a00049.html#ga134476bb857ca271e4b65158abf0bc43", null ],
    [ "LPUART_SetTxFifoWatermark", "a00049.html#ga387d3ebb8a051efaf6e5b547bb7bc0f8", null ],
    [ "LPUART_TransferEnable16Bit", "a00049.html#ga97eaafd4eba9443bcc11212fee90705f", null ],
    [ "LPUART_GetStatusFlags", "a00049.html#gab83db963591b116f90daf3e24118cb09", null ],
    [ "LPUART_ClearStatusFlags", "a00049.html#gac6bcdb29d31a2addb8d80d98855ba147", null ],
    [ "LPUART_EnableInterrupts", "a00049.html#gab5998ebb0dc457f0864c84c16f83d745", null ],
    [ "LPUART_DisableInterrupts", "a00049.html#ga2540406e4a338199acddaa828829cad8", null ],
    [ "LPUART_GetEnabledInterrupts", "a00049.html#ga172b524bae8bacc6dc95d9daf82c97b5", null ],
    [ "LPUART_GetDataRegisterAddress", "a00049.html#ga1550dd083d4b36b05ed23a67d661c9e7", null ],
    [ "LPUART_EnableTxDMA", "a00049.html#gaaaca771c26254dc78f1fc19390907dfe", null ],
    [ "LPUART_EnableRxDMA", "a00049.html#gae38de19055fca51a30c13e1cd27fb60b", null ],
    [ "LPUART_GetInstance", "a00049.html#gaaf4c8ce1f1730cdbf094931033d9b52c", null ],
    [ "LPUART_EnableTx", "a00049.html#ga49961d4e9043ff9bd10e477add9258d7", null ],
    [ "LPUART_EnableRx", "a00049.html#gaadb8a7199526555e50e65e017da4eae2", null ],
    [ "LPUART_WriteByte", "a00049.html#ga9a9389e1c7bcce6c23e00eb77006a717", null ],
    [ "LPUART_ReadByte", "a00049.html#ga02013105f0aacc7062eaae59d7401d29", null ],
    [ "LPUART_GetRxFifoCount", "a00049.html#ga45dcdc1dcb9361c0084524f8f4ab27f0", null ],
    [ "LPUART_GetTxFifoCount", "a00049.html#ga253fd7d22cc9380d92714dd40319474c", null ],
    [ "LPUART_SendAddress", "a00049.html#ga85a7dbe15a9f822847791cebe75d5394", null ],
    [ "LPUART_WriteBlocking", "a00049.html#ga2699958de62ff4832f95bc2dd8c454a5", null ],
    [ "LPUART_WriteBlocking16bit", "a00049.html#ga01d146f5e1b46526d460c5f7aae3891d", null ],
    [ "LPUART_ReadBlocking", "a00049.html#gae76aba14dbfe94124082785e2c0ecd9d", null ],
    [ "LPUART_ReadBlocking16bit", "a00049.html#ga9c95aa20caeceb3d709dd7851ce84eb1", null ],
    [ "LPUART_TransferCreateHandle", "a00049.html#ga10eae12610523a624c1016882f8dba5f", null ],
    [ "LPUART_TransferSendNonBlocking", "a00049.html#gafba986c473e5935131e63cb882cf26ff", null ],
    [ "LPUART_TransferStartRingBuffer", "a00049.html#ga5257b77491042af5913a8d91c66318e1", null ],
    [ "LPUART_TransferStopRingBuffer", "a00049.html#gad6a230a664808592aab153ea20e3d60b", null ],
    [ "LPUART_TransferGetRxRingBufferLength", "a00049.html#ga550523d301acfa413919c2f979228bcc", null ],
    [ "LPUART_TransferAbortSend", "a00049.html#ga6dfe9efe9656e126c70ee79fa03f2be3", null ],
    [ "LPUART_TransferGetSendCount", "a00049.html#gad80d2469dce0de9361e731e4cefde9fd", null ],
    [ "LPUART_TransferReceiveNonBlocking", "a00049.html#ga8bdb584704ce7955004751e32627f918", null ],
    [ "LPUART_TransferAbortReceive", "a00049.html#ga4950fa0f3835992251c109f655a3ca7d", null ],
    [ "LPUART_TransferGetReceiveCount", "a00049.html#gabfcdc658c463e9e7523cc60c5e8f9672", null ],
    [ "LPUART_TransferHandleIRQ", "a00049.html#ga6377050807e670565fe51b71c95a923c", null ],
    [ "LPUART_TransferHandleErrorIRQ", "a00049.html#ga277f4cfc074cf67c2c27082df630f2da", null ]
];