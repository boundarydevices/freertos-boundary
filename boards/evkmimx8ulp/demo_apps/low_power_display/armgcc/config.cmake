# config to select component, the format is CONFIG_USE_${component}
# Please refer to cmake files below to get available components:
#  ${SdkRootDirPath}/devices/MIMX8UD7/all_lib_device.cmake

set(CONFIG_COMPILER gcc)
set(CONFIG_TOOLCHAIN armgcc)
set(CONFIG_USE_COMPONENT_CONFIGURATION false)
set(CONFIG_USE_driver_video-common true)
set(CONFIG_USE_driver_display-common true)
set(CONFIG_USE_driver_mipi_dsi true)
set(CONFIG_USE_driver_display-mipi-dsi-cmd true)
set(CONFIG_USE_driver_display-rm68200 true)
set(CONFIG_USE_driver_display-hx8394 true)
set(CONFIG_USE_driver_codec true)
set(CONFIG_USE_driver_lcdif true)
set(CONFIG_USE_driver_reset true)
set(CONFIG_USE_component_lpi2c_adapter true)
set(CONFIG_USE_component_codec_i2c true)
set(CONFIG_USE_component_wm8960_adapter true)
set(CONFIG_USE_middleware_freertos-kernel_cm33_non_trustzone true)
set(CONFIG_USE_middleware_freertos-kernel_heap_4 true)
set(CONFIG_USE_driver_mu1 true)
set(CONFIG_USE_driver_rtd_cmc true)
set(CONFIG_USE_driver_sentinel true)
set(CONFIG_USE_middleware_multicore_rpmsg_lite_freertos true)
set(CONFIG_USE_middleware_multicore_rpmsg_lite true)
set(CONFIG_USE_driver_lptmr true)
set(CONFIG_USE_driver_pca6416a true)
set(CONFIG_USE_driver_clock true)
set(CONFIG_USE_driver_common true)
set(CONFIG_USE_device_MIMX8UD7_CMSIS true)
set(CONFIG_USE_utility_debug_console true)
set(CONFIG_USE_utility_assert true)
set(CONFIG_USE_component_lpuart_adapter true)
set(CONFIG_USE_driver_flexspi true)
set(CONFIG_USE_component_serial_manager_uart true)
set(CONFIG_USE_component_serial_manager true)
set(CONFIG_USE_driver_lpuart true)
set(CONFIG_USE_component_lists true)
set(CONFIG_USE_device_MIMX8UD7_startup true)
set(CONFIG_USE_driver_cache_cache64 true)
set(CONFIG_USE_driver_iomuxc true)
set(CONFIG_USE_driver_upower true)
set(CONFIG_USE_driver_rgpio true)
set(CONFIG_USE_driver_fusion true)
set(CONFIG_USE_driver_trdc true)
set(CONFIG_USE_driver_dma3 true)
set(CONFIG_USE_driver_lpi2c true)
set(CONFIG_USE_driver_sai_edma true)
set(CONFIG_USE_driver_wuu true)
set(CONFIG_USE_driver_lsm6dso true)
set(CONFIG_USE_driver_pdm_edma true)
set(CONFIG_USE_driver_pdm true)
set(CONFIG_USE_driver_srtm_freertos true)
set(CONFIG_USE_middleware_multicore_rpmsg_lite_imx8ulp_m33_freertos true)
set(CONFIG_USE_component_pwm_tpm_adapter true)
set(CONFIG_USE_component_rtc_bbnsm_adapter true)
set(CONFIG_USE_utilities_misc_utilities true)
set(CONFIG_USE_driver_soc_mipi_dsi true)
set(CONFIG_USE_driver_wm8960 true)
set(CONFIG_USE_middleware_freertos-kernel true)
set(CONFIG_USE_middleware_freertos-kernel_template true)
set(CONFIG_USE_middleware_freertos-kernel_extension true)
set(CONFIG_USE_CMSIS_Include_core_cm true)
set(CONFIG_USE_utility_str true)
set(CONFIG_USE_driver_sai true)
set(CONFIG_USE_driver_srtm true)
set(CONFIG_USE_driver_tpm true)
set(CONFIG_USE_driver_bbnsm true)
set(CONFIG_CORE cm33)
set(CONFIG_DEVICE MIMX8UD7)
set(CONFIG_BOARD evkmimx8ulp)
set(CONFIG_KIT evkmimx8ulp)
set(CONFIG_DEVICE_ID MIMX8UD7xxx08)
set(CONFIG_FPU SP_FPU)
set(CONFIG_DSP DSP)
set(CONFIG_CORE_ID cm33)
