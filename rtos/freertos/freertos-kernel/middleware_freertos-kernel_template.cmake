# Add set(CONFIG_USE_middleware_freertos-kernel_template true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_CORE STREQUAL cm33 AND CONFIG_FPU STREQUAL SP_FPU)
  add_config_file(${CMAKE_CURRENT_LIST_DIR}/template/ARM_CM33/FreeRTOSConfig.h ${CMAKE_CURRENT_LIST_DIR}/template/ARM_CM33 middleware_freertos-kernel_template)
endif()

