# Add set(CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_secure_context true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_freertos-kernel)

if(CONFIG_CORE STREQUAL cm33 AND CONFIG_TOOLCHAIN STREQUAL armgcc AND CONFIG_FPU STREQUAL SP_FPU)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM33/secure
)
endif()

if(CONFIG_CORE STREQUAL cm33 AND CONFIG_TOOLCHAIN STREQUAL iar AND CONFIG_FPU STREQUAL SP_FPU)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM33/secure
)
endif()

else()

message(SEND_ERROR "middleware_freertos-kernel_cm33_trustzone_secure_context dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
