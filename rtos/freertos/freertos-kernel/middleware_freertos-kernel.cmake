# Add set(CONFIG_USE_middleware_freertos-kernel true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_freertos-kernel_template AND (CONFIG_USE_middleware_freertos-kernel_heap_4 OR (NOT CONFIG_USE_middleware_freertos-kernel_heap_4)) AND (CONFIG_USE_middleware_freertos-kernel_heap_3 OR (NOT CONFIG_USE_middleware_freertos-kernel_heap_3)) AND (CONFIG_USE_middleware_freertos-kernel_heap_2 OR (NOT CONFIG_USE_middleware_freertos-kernel_heap_2)) AND (CONFIG_USE_middleware_freertos-kernel_heap_1 OR (NOT CONFIG_USE_middleware_freertos-kernel_heap_1)) AND (CONFIG_USE_middleware_freertos-kernel_heap_5 OR (NOT CONFIG_USE_middleware_freertos-kernel_heap_5)) AND (CONFIG_USE_middleware_freertos-kernel_extension OR (NOT CONFIG_USE_middleware_freertos-kernel_extension)) AND (CONFIG_USE_middleware_freertos-kernel_mpu_wrappers OR (NOT CONFIG_USE_middleware_freertos-kernel_mpu_wrappers)) AND (CONFIG_USE_middleware_freertos-kernel_cm33_non_trustzone OR (NOT CONFIG_USE_middleware_freertos-kernel_cm33_non_trustzone)) AND (CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_non_secure OR (NOT CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_non_secure)) AND (CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_secure OR (NOT CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_secure)))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/croutine.c
  ${CMAKE_CURRENT_LIST_DIR}/event_groups.c
  ${CMAKE_CURRENT_LIST_DIR}/list.c
  ${CMAKE_CURRENT_LIST_DIR}/queue.c
  ${CMAKE_CURRENT_LIST_DIR}/stream_buffer.c
  ${CMAKE_CURRENT_LIST_DIR}/tasks.c
  ${CMAKE_CURRENT_LIST_DIR}/timers.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_OS_FREE_RTOS
  )

endif()

else()

message(SEND_ERROR "middleware_freertos-kernel dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
