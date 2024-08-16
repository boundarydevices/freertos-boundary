# config to select component, the format is CONFIG_USE_${component}
# Please refer to cmake files below to get available components:
#  ${SdkRootDirPath}/devices/MIMX8UD7/all_lib_device.cmake

set(CONFIG_COMPILER gcc)
set(CONFIG_TOOLCHAIN armgcc)
set(CONFIG_USE_COMPONENT_CONFIGURATION false)
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
set(CONFIG_USE_driver_reset true)
set(CONFIG_USE_driver_upower true)
set(CONFIG_USE_driver_rgpio true)
set(CONFIG_USE_driver_fusion true)
set(CONFIG_USE_driver_trdc true)
set(CONFIG_USE_driver_sentinel true)
set(CONFIG_USE_driver_mu1 true)
set(CONFIG_USE_utilities_misc_utilities true)
set(CONFIG_USE_CMSIS_Include_core_cm true)
set(CONFIG_USE_utility_str true)
set(CONFIG_CORE cm33)
set(CONFIG_DEVICE MIMX8UD7)
set(CONFIG_BOARD evkmimx8ulp)
set(CONFIG_KIT evkmimx8ulp)
set(CONFIG_DEVICE_ID MIMX8UD7xxx08)
set(CONFIG_FPU SP_FPU)
set(CONFIG_DSP DSP)
set(CONFIG_CORE_ID cm33)