# Add set(CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_secure true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if((CONFIG_USE_middleware_freertos-kernel_template OR (NOT CONFIG_USE_middleware_freertos-kernel_template)) AND CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_secure_context AND (CONFIG_DEVICE_ID STREQUAL MIMX9352xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9352xxxxK))

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM33/secure/secure_context.c
      ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM33/secure/secure_context_port.c
      ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM33/secure/secure_heap.c
      ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM33/secure/secure_init.c
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL iar)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM33/secure/secure_context.c
      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM33/secure/secure_context_port_asm.s
      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM33/secure/secure_heap.c
      ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM33/secure/secure_init.c
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL iar)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM33/secure
  ${CMAKE_CURRENT_LIST_DIR}/portable/IAR/ARM_CM33/non_secure
)
endif()

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM33/secure
  ${CMAKE_CURRENT_LIST_DIR}/portable/GCC/ARM_CM33/non_secure
)
endif()

else()

message(SEND_ERROR "middleware_freertos-kernel_cm33_trustzone_secure dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
