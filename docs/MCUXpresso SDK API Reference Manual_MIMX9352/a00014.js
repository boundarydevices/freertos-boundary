var a00014 =
[
    [ "edma_config_t", "a00014.html#a00315", [
      [ "enableContinuousLinkMode", "a00014.html#aa45bd940803ec470b60e5b5d5bd0356b", null ],
      [ "enableHaltOnError", "a00014.html#a4d319e29ce0ab4f2406aae26a136422a", null ],
      [ "enableRoundRobinArbitration", "a00014.html#aef3200ba1711d6649c69fca888cf3468", null ],
      [ "enableDebugMode", "a00014.html#a7929ad2b37282a423c5ac5d7f4c7e744", null ],
      [ "enableGlobalChannelLink", "a00014.html#ad568833f3f99401325d6a860c8433f51", null ]
    ] ],
    [ "edma_transfer_config_t", "a00014.html#a00322", [
      [ "srcAddr", "a00014.html#aa1ff988241ea8238e8793f4236c55553", null ],
      [ "destAddr", "a00014.html#a70e10c552f356c4d2935e9f308a3317a", null ],
      [ "srcTransferSize", "a00014.html#ae5f96bb8d80f6f7a6c8a687e8a42a77e", null ],
      [ "destTransferSize", "a00014.html#afe8f8da3ed5f7c4079c818ef0197a4d7", null ],
      [ "srcOffset", "a00014.html#a25b479621f01e4e2cf7fcdab62d6e266", null ],
      [ "destOffset", "a00014.html#a09907c86542286a95a655e748789ba3e", null ],
      [ "minorLoopBytes", "a00014.html#a6f4c2ec17c05de3741d67447f784f721", null ],
      [ "majorLoopCounts", "a00014.html#accd14b645237edae7fa51c5db6aa6998", null ],
      [ "enabledInterruptMask", "a00014.html#a35c09e13ed1958ae2c23c0377828bc9c", null ],
      [ "srcAddrModulo", "a00014.html#a4f55d0d641efb777ebb4599021cc1de9", null ],
      [ "srcMajorLoopOffset", "a00014.html#a27d0f7387ab84fdacf70b53452e3682a", null ],
      [ "dstAddrModulo", "a00014.html#af68bdcac4f7db35ab38e0491a2503f16", null ],
      [ "dstMajorLoopOffset", "a00014.html#aa90157971edd3d32607dfaecd7d1fd0b", null ],
      [ "enableSrcMinorLoopOffset", "a00014.html#a4527f39c46650eb89c36d465b81d4bbc", null ],
      [ "enableDstMinorLoopOffset", "a00014.html#acf93cd985f6eb4512cb30c86ceb035bf", null ],
      [ "minorLoopOffset", "a00014.html#ac693a777f26809a75748bf6d042f51a8", null ],
      [ "enableChannelMajorLoopLink", "a00014.html#a4ff7ee109f45723fbb9d7e98bbb8018b", null ],
      [ "majorLoopLinkChannel", "a00014.html#a92227215af7c9c390ba85092e3d69e23", null ],
      [ "enableChannelMinorLoopLink", "a00014.html#a520a0bc9c9e976977decb002ae26935a", null ],
      [ "minorLoopLinkChannel", "a00014.html#a31d78ea5b3aa5d07c830c15b44014ff3", null ],
      [ "enableChannelRequest", "a00014.html#a49518cbbb1fa796c69eda19facaec706", null ],
      [ "linkTCD", "a00014.html#a552d054737eddf2f3e42ae9fac1d6f03", null ]
    ] ],
    [ "edma_channel_Preemption_config_t", "a00014.html#a00314", [
      [ "enableChannelPreemption", "a00014.html#aa1230352459f3f47b0e396ef7971bbd6", null ],
      [ "enablePreemptAbility", "a00014.html#ab7329f8b16f7e8bb0283c9305d9902ce", null ],
      [ "channelPriority", "a00014.html#a38fbcb827c573361d0043d95faca2d8f", null ]
    ] ],
    [ "edma_minor_offset_config_t", "a00014.html#a00320", [
      [ "enableSrcMinorOffset", "a00014.html#aa2b34fbdc053b7f2f3ea476048e9f80f", null ],
      [ "enableDestMinorOffset", "a00014.html#a5a2ce555e51bc7694fec6443c191fb5b", null ],
      [ "minorOffset", "a00014.html#aff7bae6e4e019c2b49508bbfec6cd1ea", null ]
    ] ],
    [ "edma_tcd_t", "a00014.html#a00321", [
      [ "SADDR", "a00014.html#a0390d1bdd79814503542ca534da58e90", null ],
      [ "SOFF", "a00014.html#a28284a4d47a0b15aa5eabc67888f9a2a", null ],
      [ "ATTR", "a00014.html#a4ac302b14c968761b4bd8bc4e620d9f6", null ],
      [ "NBYTES", "a00014.html#ada2a3af3cbf20ed38a3669c963d49f7d", null ],
      [ "SLAST", "a00014.html#a95d71d585f55cc4c5565df98c1941be0", null ],
      [ "DADDR", "a00014.html#af499a2c9e1a20435bebad40224fa577f", null ],
      [ "DOFF", "a00014.html#a7f90a8871ce94801ae7bc3ed9c94ef29", null ],
      [ "CITER", "a00014.html#a96f0c927b263c679c4463c74830968c1", null ],
      [ "DLAST_SGA", "a00014.html#a892f3dec0f15e33b64f9a966416e9ca6", null ],
      [ "CSR", "a00014.html#aa49f8458af67a904d9f5dae1dc829a10", null ],
      [ "BITER", "a00014.html#a4c5331d08a6b43c9ebc15d41c5734140", null ]
    ] ],
    [ "edma_handle_t", "a00014.html#a00319", [
      [ "callback", "a00014.html#a2103986f2733a5b6ce42b5983eabcb11", null ],
      [ "userData", "a00014.html#ad7272b78f90b9d639df09591cf2a99ac", null ],
      [ "base", "a00014.html#aac2e55c398c06eb64a7cd00b0d5dc6e3", null ],
      [ "tcdPool", "a00014.html#a60e91b4678ae407820c848671f56e3ea", null ],
      [ "channel", "a00014.html#ada5950638afd0310331d32760695089f", null ],
      [ "header", "a00014.html#a5af4b292d3fbfa8026530ffdf9949633", null ],
      [ "tail", "a00014.html#a86059d052b3d4fff045e21120b9d28a7", null ],
      [ "tcdUsed", "a00014.html#ad13ee25dd17eed61d772b88fda12badc", null ],
      [ "tcdSize", "a00014.html#a1e1640f38c69ed7cf38ef12615e341f0", null ],
      [ "flags", "a00014.html#a3be13f114e3b653751645b65972fad2f", null ],
      [ "base", "a00014.html#a43ccb35b0b767c11462b1e55ec4352e9", null ],
      [ "tcdBase", "a00014.html#ae9ea42fe384755624dae1188038caa44", null ],
      [ "channel", "a00014.html#ad487065130b5245dba2e52e1d4fba297", null ]
    ] ],
    [ "FSL_EDMA_DRIVER_VERSION", "a00014.html#ga5f0841e9527b371724ef4418e6807643", null ],
    [ "DMA_DCHPRI_INDEX", "a00014.html#ga6f2ecddbfb5e68cd1c9243dc141ec275", null ],
    [ "FSL_EDMA_DRIVER_VERSION", "a00014.html#ga5f0841e9527b371724ef4418e6807643", null ],
    [ "DMA_DCHPRI_INDEX", "a00014.html#ga6f2ecddbfb5e68cd1c9243dc141ec275", null ],
    [ "edma_callback", "a00014.html#ga9ee3a34d12fbb39bc972f62ba6357022", null ],
    [ "edma_tcd_t", "a00014.html#ga30c002c19c87dccaace466ac1c5dc391", null ],
    [ "edma_callback", "a00014.html#ga9ee3a34d12fbb39bc972f62ba6357022", null ],
    [ "edma_transfer_size_t", "a00014.html#gafeb85400b3b87188983f5d62e9e26cb6", [
      [ "kEDMA_TransferSize1Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6acb4e50cd0e23c0d36edf958be77c8dc2", null ],
      [ "kEDMA_TransferSize2Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a589480546c8db2d1372e62a7946fbb2c", null ],
      [ "kEDMA_TransferSize4Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a4d91559541642b997418406ec927c454", null ],
      [ "kEDMA_TransferSize8Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a3c361ee4008e6ba8097557e3d4a55ce8", null ],
      [ "kEDMA_TransferSize16Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a0d4cdfd536f2985eea3e8111eecd3c43", null ],
      [ "kEDMA_TransferSize32Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6ad7e2421e513fc84a29cd20ab47409229", null ],
      [ "kEDMA_TransferSize1Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6acb4e50cd0e23c0d36edf958be77c8dc2", null ],
      [ "kEDMA_TransferSize2Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a589480546c8db2d1372e62a7946fbb2c", null ],
      [ "kEDMA_TransferSize4Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a4d91559541642b997418406ec927c454", null ],
      [ "kEDMA_TransferSize8Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a3c361ee4008e6ba8097557e3d4a55ce8", null ],
      [ "kEDMA_TransferSize16Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a0d4cdfd536f2985eea3e8111eecd3c43", null ],
      [ "kEDMA_TransferSize32Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6ad7e2421e513fc84a29cd20ab47409229", null ],
      [ "kEDMA_TransferSize64Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a84075bc94ca49c5641a5d2e4b3ca2396", null ]
    ] ],
    [ "edma_modulo_t", "a00014.html#ga13ac7c9e76c11d3dce06f8976d9e4dd7", [
      [ "kEDMA_ModuloDisable", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab77c38c19ddcc44212b258bdafe2f207", null ],
      [ "kEDMA_Modulo2bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af7cbe0618a06406e5473ec1aa11195a0", null ],
      [ "kEDMA_Modulo4bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2eaf98fea83570be353ff21fde4b8d53", null ],
      [ "kEDMA_Modulo8bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a99fad23e0502470cddec1391edc483e2", null ],
      [ "kEDMA_Modulo16bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7abd6ec81a3b0822ea6c3a7c77215e85a8", null ],
      [ "kEDMA_Modulo32bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd0d2322a93a86bb7bb1160217184569", null ],
      [ "kEDMA_Modulo64bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af60e65e2fdc306df458cabaa77c0a62c", null ],
      [ "kEDMA_Modulo128bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ac5b734f88d8fbe08c19f4b881e643ebd", null ],
      [ "kEDMA_Modulo256bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab6354112d539cb71083057f72a43f282", null ],
      [ "kEDMA_Modulo512bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a56d31f1fa472122b9edf4d8c8d437359", null ],
      [ "kEDMA_Modulo1Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a7b85b92e30afea2d7d2eb11e40751496", null ],
      [ "kEDMA_Modulo2Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd26e0c0dc1a6518dca27c0a418df484", null ],
      [ "kEDMA_Modulo4Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae9f8fd54c7f183214653a750775b1e1c", null ],
      [ "kEDMA_Modulo8Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a568ad80f68673d4f57362dc48701aec6", null ],
      [ "kEDMA_Modulo16Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a6e8595a1168272eab8923212c1cabaee", null ],
      [ "kEDMA_Modulo32Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af12cea48af625688f7d3a6e9e2d19d56", null ],
      [ "kEDMA_Modulo64Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aab39052aeb4a70843c6ddd61b94f95a0", null ],
      [ "kEDMA_Modulo128Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7afb80c06c8d24882fdeb592a37673e499", null ],
      [ "kEDMA_Modulo256Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae1c82fe430bd6a43cd8bfca46671cca1", null ],
      [ "kEDMA_Modulo512Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aff7dbf518027bc1d2a84a4dcfe7f0adc", null ],
      [ "kEDMA_Modulo1Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a48ff619715bb526b6d917d6b37686b8a", null ],
      [ "kEDMA_Modulo2Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a5c2909e6956a01efc28bb70a73ddb9f5", null ],
      [ "kEDMA_Modulo4Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a4b07b0456e0aadbde3a32790e423f4d7", null ],
      [ "kEDMA_Modulo8Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ad4f068091510d3fc90b8a21bd2492a38", null ],
      [ "kEDMA_Modulo16Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a3ff219951928d6e40f658f612f9106c0", null ],
      [ "kEDMA_Modulo32Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ade7587c87a42242eb0e47a1dbac5f686", null ],
      [ "kEDMA_Modulo64Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aedc3a67726be1cdac9385a37556c7056", null ],
      [ "kEDMA_Modulo128Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a0f2c2ca6e26fcf1edefe6bd091504041", null ],
      [ "kEDMA_Modulo256Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a50818bce765be0d7ccfac7490242c119", null ],
      [ "kEDMA_Modulo512Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2289cd131c9052e9ab097abbff3499e7", null ],
      [ "kEDMA_Modulo1Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a22c8078316841b5cc5886d506f95a8e3", null ],
      [ "kEDMA_Modulo2Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab4a779add96a309505f06a540d75340f", null ],
      [ "kEDMA_ModuloDisable", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab77c38c19ddcc44212b258bdafe2f207", null ],
      [ "kEDMA_Modulo2bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af7cbe0618a06406e5473ec1aa11195a0", null ],
      [ "kEDMA_Modulo4bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2eaf98fea83570be353ff21fde4b8d53", null ],
      [ "kEDMA_Modulo8bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a99fad23e0502470cddec1391edc483e2", null ],
      [ "kEDMA_Modulo16bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7abd6ec81a3b0822ea6c3a7c77215e85a8", null ],
      [ "kEDMA_Modulo32bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd0d2322a93a86bb7bb1160217184569", null ],
      [ "kEDMA_Modulo64bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af60e65e2fdc306df458cabaa77c0a62c", null ],
      [ "kEDMA_Modulo128bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ac5b734f88d8fbe08c19f4b881e643ebd", null ],
      [ "kEDMA_Modulo256bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab6354112d539cb71083057f72a43f282", null ],
      [ "kEDMA_Modulo512bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a56d31f1fa472122b9edf4d8c8d437359", null ],
      [ "kEDMA_Modulo1Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a7b85b92e30afea2d7d2eb11e40751496", null ],
      [ "kEDMA_Modulo2Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd26e0c0dc1a6518dca27c0a418df484", null ],
      [ "kEDMA_Modulo4Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae9f8fd54c7f183214653a750775b1e1c", null ],
      [ "kEDMA_Modulo8Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a568ad80f68673d4f57362dc48701aec6", null ],
      [ "kEDMA_Modulo16Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a6e8595a1168272eab8923212c1cabaee", null ],
      [ "kEDMA_Modulo32Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af12cea48af625688f7d3a6e9e2d19d56", null ],
      [ "kEDMA_Modulo64Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aab39052aeb4a70843c6ddd61b94f95a0", null ],
      [ "kEDMA_Modulo128Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7afb80c06c8d24882fdeb592a37673e499", null ],
      [ "kEDMA_Modulo256Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae1c82fe430bd6a43cd8bfca46671cca1", null ],
      [ "kEDMA_Modulo512Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aff7dbf518027bc1d2a84a4dcfe7f0adc", null ],
      [ "kEDMA_Modulo1Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a48ff619715bb526b6d917d6b37686b8a", null ],
      [ "kEDMA_Modulo2Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a5c2909e6956a01efc28bb70a73ddb9f5", null ],
      [ "kEDMA_Modulo4Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a4b07b0456e0aadbde3a32790e423f4d7", null ],
      [ "kEDMA_Modulo8Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ad4f068091510d3fc90b8a21bd2492a38", null ],
      [ "kEDMA_Modulo16Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a3ff219951928d6e40f658f612f9106c0", null ],
      [ "kEDMA_Modulo32Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ade7587c87a42242eb0e47a1dbac5f686", null ],
      [ "kEDMA_Modulo64Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aedc3a67726be1cdac9385a37556c7056", null ],
      [ "kEDMA_Modulo128Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a0f2c2ca6e26fcf1edefe6bd091504041", null ],
      [ "kEDMA_Modulo256Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a50818bce765be0d7ccfac7490242c119", null ],
      [ "kEDMA_Modulo512Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2289cd131c9052e9ab097abbff3499e7", null ],
      [ "kEDMA_Modulo1Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a22c8078316841b5cc5886d506f95a8e3", null ],
      [ "kEDMA_Modulo2Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab4a779add96a309505f06a540d75340f", null ]
    ] ],
    [ "edma_bandwidth_t", "a00014.html#ga77dde4bf7218f5dff3f5eeeccd565d0f", [
      [ "kEDMA_BandwidthStallNone", "a00014.html#gga77dde4bf7218f5dff3f5eeeccd565d0faeb09bbf3022f40b276ab9b94035ef308", null ],
      [ "kEDMA_BandwidthStall4Cycle", "a00014.html#gga77dde4bf7218f5dff3f5eeeccd565d0fa443b7698b1950201d47d97de1b643f3c", null ],
      [ "kEDMA_BandwidthStall8Cycle", "a00014.html#gga77dde4bf7218f5dff3f5eeeccd565d0fac21c278bddfbadae35d53cc565bca9d9", null ]
    ] ],
    [ "edma_channel_link_type_t", "a00014.html#ga9b736ab8d1dd10d8a277712904b29c91", [
      [ "kEDMA_LinkNone", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91aba8b1349b47c8e99c950c179b5548caa", null ],
      [ "kEDMA_MinorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91a804db702dd385d11a01dd512f3e1606c", null ],
      [ "kEDMA_MajorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91ab9798ac8a18b9632a7d3fabf0bd76881", null ],
      [ "kEDMA_LinkNone", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91aba8b1349b47c8e99c950c179b5548caa", null ],
      [ "kEDMA_MinorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91a804db702dd385d11a01dd512f3e1606c", null ],
      [ "kEDMA_MajorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91ab9798ac8a18b9632a7d3fabf0bd76881", null ],
      [ "kEDMA_DoneFlag", "a00014.html#ggadf764cbdea00d65edcd07bb9953ad2b7a3fc49e0e9df4c15438fac350d2d7da56", null ],
      [ "kEDMA_ErrorFlag", "a00014.html#ggadf764cbdea00d65edcd07bb9953ad2b7a2c5dd54b1cb8bd4917b99a914c7bdc84", null ],
      [ "kEDMA_InterruptFlag", "a00014.html#ggadf764cbdea00d65edcd07bb9953ad2b7afca58961c7da506e2f1c05451d16f4d9", null ],
      [ "kEDMA_DestinationBusErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5a54ca64713f21fd2337d165b273d6f680", null ],
      [ "kEDMA_SourceBusErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5a5eb8315759ff492642e8fde45cd3d244", null ],
      [ "kEDMA_ScatterGatherErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5a9aeb6aad3c245959ab91944bc0136479", null ],
      [ "kEDMA_NbytesErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5acc8bc58b1704ba1f4f4ee1533f69c98e", null ],
      [ "kEDMA_DestinationOffsetErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5aa53400970fa05f5d2790f20338aa6d06", null ],
      [ "kEDMA_DestinationAddressErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5ae516e9e9db0a946f1565e1c2e3175574", null ],
      [ "kEDMA_SourceOffsetErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5ad611243e3bd0baed42ed2343e5e575ac", null ],
      [ "kEDMA_SourceAddressErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5a4c0642a49305653638e275415320f0f0", null ],
      [ "kEDMA_ErrorChannelFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5a2cc6d4262814dc42f05843199e9540c1", null ],
      [ "kEDMA_ChannelPriorityErrorFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5a6f919249e70bf24808d10ff0aaeedbae", null ],
      [ "kEDMA_TransferCanceledFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5a1c6f9d050df7f2f0aa945b5f1c46e230", null ],
      [ "kEDMA_ValidFlag", "a00014.html#gga99fb83031ce9923c84392b4e92f956b5ab930c63068a6d7ee6ccb21df993bd48f", null ]
    ] ],
    [ "edma_interrupt_enable_t", "a00014.html#ga345805161c8c8ca55c0866085e3d3f76", [
      [ "kEDMA_ErrorInterruptEnable", "a00014.html#gga345805161c8c8ca55c0866085e3d3f76ab2be76dc7af93bec6801d76376f924c0", null ],
      [ "kEDMA_MajorInterruptEnable", "a00014.html#gga345805161c8c8ca55c0866085e3d3f76a19c5998906a159df3204e818033a3c0e", null ],
      [ "kEDMA_HalfInterruptEnable", "a00014.html#gga345805161c8c8ca55c0866085e3d3f76a2f1573636dcd4a54d9189bdee4cf39d0", null ]
    ] ],
    [ "edma_transfer_type_t", "a00014.html#ga7803399034b374663f76a589da7d8419", [
      [ "kEDMA_MemoryToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419aba1ccd03368799d9752bd6001f5373a5", null ],
      [ "kEDMA_PeripheralToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419a1041287c7dc311d81017f529a51734e6", null ],
      [ "kEDMA_MemoryToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a172d3e1f201639f3157563f4a1a275bf", null ],
      [ "kEDMA_PeripheralToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a5c9cc27e04a3c22204b90ba07b860727", null ],
      [ "kEDMA_MemoryToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419aba1ccd03368799d9752bd6001f5373a5", null ],
      [ "kEDMA_PeripheralToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419a1041287c7dc311d81017f529a51734e6", null ],
      [ "kEDMA_MemoryToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a172d3e1f201639f3157563f4a1a275bf", null ],
      [ "kEDMA_PeripheralToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a5c9cc27e04a3c22204b90ba07b860727", null ],
      [ "kStatus_EDMA_QueueFull", "a00014.html#ggabc6126af1d45847bc59afa0aa3216b04a6d33d9a7019b18917669f16d51085b32", null ],
      [ "kStatus_EDMA_Busy", "a00014.html#ggabc6126af1d45847bc59afa0aa3216b04a96aa3062c73a9f439f63c0ed24f09c07", null ],
      [ "kStatus_EDMA_QueueFull", "a00014.html#ggadc29c2ff13d900c2f185ee95427fb06ca6d33d9a7019b18917669f16d51085b32", null ],
      [ "kStatus_EDMA_Busy", "a00014.html#ggadc29c2ff13d900c2f185ee95427fb06ca96aa3062c73a9f439f63c0ed24f09c07", null ]
    ] ],
    [ "edma_transfer_size_t", "a00014.html#gafeb85400b3b87188983f5d62e9e26cb6", [
      [ "kEDMA_TransferSize1Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6acb4e50cd0e23c0d36edf958be77c8dc2", null ],
      [ "kEDMA_TransferSize2Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a589480546c8db2d1372e62a7946fbb2c", null ],
      [ "kEDMA_TransferSize4Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a4d91559541642b997418406ec927c454", null ],
      [ "kEDMA_TransferSize8Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a3c361ee4008e6ba8097557e3d4a55ce8", null ],
      [ "kEDMA_TransferSize16Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a0d4cdfd536f2985eea3e8111eecd3c43", null ],
      [ "kEDMA_TransferSize32Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6ad7e2421e513fc84a29cd20ab47409229", null ],
      [ "kEDMA_TransferSize1Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6acb4e50cd0e23c0d36edf958be77c8dc2", null ],
      [ "kEDMA_TransferSize2Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a589480546c8db2d1372e62a7946fbb2c", null ],
      [ "kEDMA_TransferSize4Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a4d91559541642b997418406ec927c454", null ],
      [ "kEDMA_TransferSize8Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a3c361ee4008e6ba8097557e3d4a55ce8", null ],
      [ "kEDMA_TransferSize16Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a0d4cdfd536f2985eea3e8111eecd3c43", null ],
      [ "kEDMA_TransferSize32Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6ad7e2421e513fc84a29cd20ab47409229", null ],
      [ "kEDMA_TransferSize64Bytes", "a00014.html#ggafeb85400b3b87188983f5d62e9e26cb6a84075bc94ca49c5641a5d2e4b3ca2396", null ]
    ] ],
    [ "edma_modulo_t", "a00014.html#ga13ac7c9e76c11d3dce06f8976d9e4dd7", [
      [ "kEDMA_ModuloDisable", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab77c38c19ddcc44212b258bdafe2f207", null ],
      [ "kEDMA_Modulo2bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af7cbe0618a06406e5473ec1aa11195a0", null ],
      [ "kEDMA_Modulo4bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2eaf98fea83570be353ff21fde4b8d53", null ],
      [ "kEDMA_Modulo8bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a99fad23e0502470cddec1391edc483e2", null ],
      [ "kEDMA_Modulo16bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7abd6ec81a3b0822ea6c3a7c77215e85a8", null ],
      [ "kEDMA_Modulo32bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd0d2322a93a86bb7bb1160217184569", null ],
      [ "kEDMA_Modulo64bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af60e65e2fdc306df458cabaa77c0a62c", null ],
      [ "kEDMA_Modulo128bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ac5b734f88d8fbe08c19f4b881e643ebd", null ],
      [ "kEDMA_Modulo256bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab6354112d539cb71083057f72a43f282", null ],
      [ "kEDMA_Modulo512bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a56d31f1fa472122b9edf4d8c8d437359", null ],
      [ "kEDMA_Modulo1Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a7b85b92e30afea2d7d2eb11e40751496", null ],
      [ "kEDMA_Modulo2Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd26e0c0dc1a6518dca27c0a418df484", null ],
      [ "kEDMA_Modulo4Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae9f8fd54c7f183214653a750775b1e1c", null ],
      [ "kEDMA_Modulo8Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a568ad80f68673d4f57362dc48701aec6", null ],
      [ "kEDMA_Modulo16Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a6e8595a1168272eab8923212c1cabaee", null ],
      [ "kEDMA_Modulo32Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af12cea48af625688f7d3a6e9e2d19d56", null ],
      [ "kEDMA_Modulo64Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aab39052aeb4a70843c6ddd61b94f95a0", null ],
      [ "kEDMA_Modulo128Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7afb80c06c8d24882fdeb592a37673e499", null ],
      [ "kEDMA_Modulo256Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae1c82fe430bd6a43cd8bfca46671cca1", null ],
      [ "kEDMA_Modulo512Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aff7dbf518027bc1d2a84a4dcfe7f0adc", null ],
      [ "kEDMA_Modulo1Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a48ff619715bb526b6d917d6b37686b8a", null ],
      [ "kEDMA_Modulo2Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a5c2909e6956a01efc28bb70a73ddb9f5", null ],
      [ "kEDMA_Modulo4Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a4b07b0456e0aadbde3a32790e423f4d7", null ],
      [ "kEDMA_Modulo8Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ad4f068091510d3fc90b8a21bd2492a38", null ],
      [ "kEDMA_Modulo16Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a3ff219951928d6e40f658f612f9106c0", null ],
      [ "kEDMA_Modulo32Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ade7587c87a42242eb0e47a1dbac5f686", null ],
      [ "kEDMA_Modulo64Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aedc3a67726be1cdac9385a37556c7056", null ],
      [ "kEDMA_Modulo128Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a0f2c2ca6e26fcf1edefe6bd091504041", null ],
      [ "kEDMA_Modulo256Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a50818bce765be0d7ccfac7490242c119", null ],
      [ "kEDMA_Modulo512Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2289cd131c9052e9ab097abbff3499e7", null ],
      [ "kEDMA_Modulo1Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a22c8078316841b5cc5886d506f95a8e3", null ],
      [ "kEDMA_Modulo2Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab4a779add96a309505f06a540d75340f", null ],
      [ "kEDMA_ModuloDisable", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab77c38c19ddcc44212b258bdafe2f207", null ],
      [ "kEDMA_Modulo2bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af7cbe0618a06406e5473ec1aa11195a0", null ],
      [ "kEDMA_Modulo4bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2eaf98fea83570be353ff21fde4b8d53", null ],
      [ "kEDMA_Modulo8bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a99fad23e0502470cddec1391edc483e2", null ],
      [ "kEDMA_Modulo16bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7abd6ec81a3b0822ea6c3a7c77215e85a8", null ],
      [ "kEDMA_Modulo32bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd0d2322a93a86bb7bb1160217184569", null ],
      [ "kEDMA_Modulo64bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af60e65e2fdc306df458cabaa77c0a62c", null ],
      [ "kEDMA_Modulo128bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ac5b734f88d8fbe08c19f4b881e643ebd", null ],
      [ "kEDMA_Modulo256bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab6354112d539cb71083057f72a43f282", null ],
      [ "kEDMA_Modulo512bytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a56d31f1fa472122b9edf4d8c8d437359", null ],
      [ "kEDMA_Modulo1Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a7b85b92e30afea2d7d2eb11e40751496", null ],
      [ "kEDMA_Modulo2Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7acd26e0c0dc1a6518dca27c0a418df484", null ],
      [ "kEDMA_Modulo4Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae9f8fd54c7f183214653a750775b1e1c", null ],
      [ "kEDMA_Modulo8Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a568ad80f68673d4f57362dc48701aec6", null ],
      [ "kEDMA_Modulo16Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a6e8595a1168272eab8923212c1cabaee", null ],
      [ "kEDMA_Modulo32Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7af12cea48af625688f7d3a6e9e2d19d56", null ],
      [ "kEDMA_Modulo64Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aab39052aeb4a70843c6ddd61b94f95a0", null ],
      [ "kEDMA_Modulo128Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7afb80c06c8d24882fdeb592a37673e499", null ],
      [ "kEDMA_Modulo256Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ae1c82fe430bd6a43cd8bfca46671cca1", null ],
      [ "kEDMA_Modulo512Kbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aff7dbf518027bc1d2a84a4dcfe7f0adc", null ],
      [ "kEDMA_Modulo1Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a48ff619715bb526b6d917d6b37686b8a", null ],
      [ "kEDMA_Modulo2Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a5c2909e6956a01efc28bb70a73ddb9f5", null ],
      [ "kEDMA_Modulo4Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a4b07b0456e0aadbde3a32790e423f4d7", null ],
      [ "kEDMA_Modulo8Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ad4f068091510d3fc90b8a21bd2492a38", null ],
      [ "kEDMA_Modulo16Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a3ff219951928d6e40f658f612f9106c0", null ],
      [ "kEDMA_Modulo32Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ade7587c87a42242eb0e47a1dbac5f686", null ],
      [ "kEDMA_Modulo64Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7aedc3a67726be1cdac9385a37556c7056", null ],
      [ "kEDMA_Modulo128Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a0f2c2ca6e26fcf1edefe6bd091504041", null ],
      [ "kEDMA_Modulo256Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a50818bce765be0d7ccfac7490242c119", null ],
      [ "kEDMA_Modulo512Mbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a2289cd131c9052e9ab097abbff3499e7", null ],
      [ "kEDMA_Modulo1Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7a22c8078316841b5cc5886d506f95a8e3", null ],
      [ "kEDMA_Modulo2Gbytes", "a00014.html#gga13ac7c9e76c11d3dce06f8976d9e4dd7ab4a779add96a309505f06a540d75340f", null ]
    ] ],
    [ "edma_channel_link_type_t", "a00014.html#ga9b736ab8d1dd10d8a277712904b29c91", [
      [ "kEDMA_LinkNone", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91aba8b1349b47c8e99c950c179b5548caa", null ],
      [ "kEDMA_MinorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91a804db702dd385d11a01dd512f3e1606c", null ],
      [ "kEDMA_MajorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91ab9798ac8a18b9632a7d3fabf0bd76881", null ],
      [ "kEDMA_LinkNone", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91aba8b1349b47c8e99c950c179b5548caa", null ],
      [ "kEDMA_MinorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91a804db702dd385d11a01dd512f3e1606c", null ],
      [ "kEDMA_MajorLink", "a00014.html#gga9b736ab8d1dd10d8a277712904b29c91ab9798ac8a18b9632a7d3fabf0bd76881", null ],
      [ "kEDMA_DoneFlag", "a00014.html#gga61dadd085c1777f559549e05962b2c9ea3fc49e0e9df4c15438fac350d2d7da56", null ],
      [ "kEDMA_ErrorFlag", "a00014.html#gga61dadd085c1777f559549e05962b2c9ea2c5dd54b1cb8bd4917b99a914c7bdc84", null ],
      [ "kEDMA_InterruptFlag", "a00014.html#gga61dadd085c1777f559549e05962b2c9eafca58961c7da506e2f1c05451d16f4d9", null ]
    ] ],
    [ "_edma_interrupt_enable", "a00014.html#ga4b9e8a6e5ac90d2b80f8b995a9e8e7ef", [
      [ "kEDMA_ErrorInterruptEnable", "a00014.html#gga4b9e8a6e5ac90d2b80f8b995a9e8e7efab2be76dc7af93bec6801d76376f924c0", null ],
      [ "kEDMA_MajorInterruptEnable", "a00014.html#gga4b9e8a6e5ac90d2b80f8b995a9e8e7efa19c5998906a159df3204e818033a3c0e", null ],
      [ "kEDMA_HalfInterruptEnable", "a00014.html#gga4b9e8a6e5ac90d2b80f8b995a9e8e7efa2f1573636dcd4a54d9189bdee4cf39d0", null ]
    ] ],
    [ "edma_transfer_type_t", "a00014.html#ga7803399034b374663f76a589da7d8419", [
      [ "kEDMA_MemoryToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419aba1ccd03368799d9752bd6001f5373a5", null ],
      [ "kEDMA_PeripheralToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419a1041287c7dc311d81017f529a51734e6", null ],
      [ "kEDMA_MemoryToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a172d3e1f201639f3157563f4a1a275bf", null ],
      [ "kEDMA_PeripheralToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a5c9cc27e04a3c22204b90ba07b860727", null ],
      [ "kEDMA_MemoryToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419aba1ccd03368799d9752bd6001f5373a5", null ],
      [ "kEDMA_PeripheralToMemory", "a00014.html#gga7803399034b374663f76a589da7d8419a1041287c7dc311d81017f529a51734e6", null ],
      [ "kEDMA_MemoryToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a172d3e1f201639f3157563f4a1a275bf", null ],
      [ "kEDMA_PeripheralToPeripheral", "a00014.html#gga7803399034b374663f76a589da7d8419a5c9cc27e04a3c22204b90ba07b860727", null ]
    ] ],
    [ "EDMA_Init", "a00014.html#gaf7588eb4b54499f0f55c698bd98bc1bb", null ],
    [ "EDMA_Deinit", "a00014.html#ga29aa2b1f72c154c12305d6615845618c", null ],
    [ "EDMA_InstallTCD", "a00014.html#ga23e063167a1b666dcdd5538407c5c948", null ],
    [ "EDMA_GetDefaultConfig", "a00014.html#ga9851dc5addd6a1fc557bfdb625aa5c19", null ],
    [ "EDMA_EnableContinuousChannelLinkMode", "a00014.html#ga7957e210d6f4904d42df81508da25d56", null ],
    [ "EDMA_EnableMinorLoopMapping", "a00014.html#ga3b2e736c8b20f41b5df9932452fe9d3c", null ],
    [ "EDMA_ResetChannel", "a00014.html#gaecea06e22455415332bbc342c309cb6b", null ],
    [ "EDMA_SetTransferConfig", "a00014.html#gaad0c5872dda63e558ee6c62f9bc5eaa8", null ],
    [ "EDMA_SetMinorOffsetConfig", "a00014.html#gae77bdff6263bed3a02291efb8f1146f0", null ],
    [ "EDMA_SetChannelPreemptionConfig", "a00014.html#ga136076d50d98d4eadfaa9cd592b273e7", null ],
    [ "EDMA_SetChannelLink", "a00014.html#ga8cd3ca8512357b64af15846a2b87edd6", null ],
    [ "EDMA_SetBandWidth", "a00014.html#gaf2997a300751b52e3c2e699e3f2296f2", null ],
    [ "EDMA_SetModulo", "a00014.html#gaa3f4855fe92ed80276487771b9bd2705", null ],
    [ "EDMA_EnableAsyncRequest", "a00014.html#ga0e5cbacd0f64515239695b9f94bb78a4", null ],
    [ "EDMA_EnableAutoStopRequest", "a00014.html#gac3ef15106efff13ea6a25441fc228349", null ],
    [ "EDMA_EnableChannelInterrupts", "a00014.html#ga15df898b3b420958f51c4df22dc85b98", null ],
    [ "EDMA_DisableChannelInterrupts", "a00014.html#ga251561e70531dfcea586b5f1fff9c916", null ],
    [ "EDMA_SetMajorOffsetConfig", "a00014.html#ga44f984a5522f544407e43b1147c40cb4", null ],
    [ "EDMA_TcdReset", "a00014.html#ga3c6239d1c1cd5483fa9b390f568e3066", null ],
    [ "EDMA_TcdSetTransferConfig", "a00014.html#gad7efa07faa29e3acf456fc1cffb3f9d5", null ],
    [ "EDMA_TcdSetMinorOffsetConfig", "a00014.html#ga5409f4a24baec461a186df10fe1f8c52", null ],
    [ "EDMA_TcdSetChannelLink", "a00014.html#ga04ee251c7c7efd9ab4f5b2182ef8a626", null ],
    [ "EDMA_TcdSetBandWidth", "a00014.html#ga7357cc963fb15ce336ea8fb78f3475a7", null ],
    [ "EDMA_TcdSetModulo", "a00014.html#ga998211b8fa494160251f2bdfae2d67b4", null ],
    [ "EDMA_TcdEnableAutoStopRequest", "a00014.html#gabc58ab357e8425a3211048a77ca5ed82", null ],
    [ "EDMA_TcdEnableInterrupts", "a00014.html#gaff194ee32f2848aa721f8d65f4329fce", null ],
    [ "EDMA_TcdDisableInterrupts", "a00014.html#ga1dad41c69a12e8abb772f60c66d9f162", null ],
    [ "EDMA_TcdSetMajorOffsetConfig", "a00014.html#ga1de61e7f86f4f9f00f757dafe2dbc5d5", null ],
    [ "EDMA_EnableChannelRequest", "a00014.html#gaabbec6b59a4313df50af39872743deaf", null ],
    [ "EDMA_DisableChannelRequest", "a00014.html#ga44708108a447777f25e322063df70c95", null ],
    [ "EDMA_TriggerChannelStart", "a00014.html#ga38aa18611518af3211f23044527d6992", null ],
    [ "EDMA_GetRemainingMajorLoopCount", "a00014.html#ga097a1bad709b591528fc967867e98d14", null ],
    [ "EDMA_GetErrorStatusFlags", "a00014.html#ga2416059ab1bd9c51df50bf78f0f98221", null ],
    [ "EDMA_GetChannelStatusFlags", "a00014.html#ga6e33fe1b55eb7296b1c2cb440c63bf0e", null ],
    [ "EDMA_ClearChannelStatusFlags", "a00014.html#ga4575eda0bdf9bbec225cdb322bfadb97", null ],
    [ "EDMA_CreateHandle", "a00014.html#gae71842684e693908395784e8b7f7ef55", null ],
    [ "EDMA_InstallTCDMemory", "a00014.html#ga61e4c8c8c4292918fe976a9071fa68e2", null ],
    [ "EDMA_SetCallback", "a00014.html#ga945ae6f5db8b32c9b39ec0954073d65d", null ],
    [ "EDMA_PrepareTransferConfig", "a00014.html#ga5d1bb30d93e3fd08656d77f0e3a9f75f", null ],
    [ "EDMA_PrepareTransfer", "a00014.html#ga7b9fea80d9316b081f4dfb33b393bbb0", null ],
    [ "EDMA_SubmitTransfer", "a00014.html#ga8a78ca4c4c941f0ba5fa60033b81b61b", null ],
    [ "EDMA_StartTransfer", "a00014.html#gab4a5570a9a0936f6666ec3c6a619296f", null ],
    [ "EDMA_StopTransfer", "a00014.html#ga253a133e7834d7cb958911a05acc16b8", null ],
    [ "EDMA_AbortTransfer", "a00014.html#ga2098cf6995bc79b25c5c9588f1c711e9", null ],
    [ "EDMA_GetUnusedTCDNumber", "a00014.html#ga491de73a29d57aca475bbfe70a7a628e", null ],
    [ "EDMA_GetNextTCDAddress", "a00014.html#ga2b97ab97e7bc0b5f15d905bae8341950", null ],
    [ "EDMA_HandleIRQ", "a00014.html#gaebf4a6a6000c296d3ab795aae77b65a0", null ],
    [ "EDMA_Init", "a00014.html#gac9ac0d8983270150ff59f5d6fcb640ad", null ],
    [ "EDMA_Deinit", "a00014.html#gaef26e952740aa51e98f6a9ba9abf1cff", null ],
    [ "EDMA_InstallTCD", "a00014.html#ga8fa86ef70519bef2e13f32821ee93151", null ],
    [ "EDMA_ResetChannel", "a00014.html#ga7decfcad24902ac0e3722280225059bb", null ],
    [ "EDMA_SetTransferConfig", "a00014.html#ga930df98587d7d1574975df7f0f5a9017", null ],
    [ "EDMA_SetMinorOffsetConfig", "a00014.html#gafaf198d3254c23f973f5a6775ff1a5a8", null ],
    [ "EDMA_SetChannelPreemptionConfig", "a00014.html#gafef794d2b2bbbc363d4ba31becdf3853", null ],
    [ "EDMA_SetChannelLink", "a00014.html#gaec764928518b592356ea03dfc5be8655", null ],
    [ "EDMA_SetModulo", "a00014.html#gaf9fcb3dd54c84ebb876bdb65c1279e92", null ],
    [ "EDMA_EnableAsyncRequest", "a00014.html#gaf6c501b086871bf93b130e35bcf15f9a", null ],
    [ "EDMA_EnableAutoStopRequest", "a00014.html#ga767c734378d1265aea3525884f34562f", null ],
    [ "EDMA_EnableChannelInterrupts", "a00014.html#ga8ffb1cd880076103b8eb132ec593263b", null ],
    [ "EDMA_DisableChannelInterrupts", "a00014.html#gaff7f388910cfac872ba91f9d3829c852", null ],
    [ "EDMA_SetMajorOffsetConfig", "a00014.html#ga499d0a2a0803d3d15adea62293abd745", null ],
    [ "EDMA_ConfigChannelSoftwareTCD", "a00014.html#ga15324b7d29e84d16e1b01a9e4875f3ee", null ],
    [ "EDMA_EnableChannelRequest", "a00014.html#ga01f2480f3cf21e9bdd55356c18547dd1", null ],
    [ "EDMA_DisableChannelRequest", "a00014.html#gade300e98dc0021cde353b4cc5f370ada", null ],
    [ "EDMA_TriggerChannelStart", "a00014.html#ga7cf09dd082102c80ad7f29d31c89d192", null ],
    [ "EDMA_GetRemainingMajorLoopCount", "a00014.html#gad2c05e0dc9d21af66ec4270a251976c2", null ],
    [ "EDMA_GetErrorStatusFlags", "a00014.html#ga96b5f6a1304b974fe79fee4b50dbe5fc", null ],
    [ "EDMA_GetChannelStatusFlags", "a00014.html#ga09572f26f410216bf0e0b8bea48c61cf", null ],
    [ "EDMA_ClearChannelStatusFlags", "a00014.html#ga84d44db926afe63bd958732a0564e35c", null ],
    [ "EDMA_CreateHandle", "a00014.html#gab640a86fd7035c962cc8fc202b0cbc91", null ],
    [ "EDMA_SubmitLoopTransfer", "a00014.html#ga7a875f256e7792a023ec5eba060c68a7", null ]
];