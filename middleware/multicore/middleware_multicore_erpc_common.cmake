# Add set(CONFIG_USE_middleware_multicore_erpc_common true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(((CONFIG_DEVICE_ID STREQUAL MIMX9301xxxxD OR CONFIG_DEVICE_ID STREQUAL MIMX9302xxxxD OR CONFIG_DEVICE_ID STREQUAL MIMX9311xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9312xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9321xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9322xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9331xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9332xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9351xxxxM OR CONFIG_DEVICE_ID STREQUAL MIMX9352xxxxM)))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/infra/erpc_basic_codec.cpp
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/infra/erpc_message_buffer.cpp
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/infra/erpc_message_loggers.cpp
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/infra/erpc_crc16.cpp
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/infra/erpc_pre_post_action.cpp
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/infra/erpc_utils.cpp
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/infra
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/setup
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/port
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c/transports
  ${CMAKE_CURRENT_LIST_DIR}/erpc/erpc_c
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  if(CONFIG_TOOLCHAIN STREQUAL iar)
    target_compile_options(${MCUX_SDK_PROJECT_NAME} PUBLIC
      --enable_restrict
    )
  endif()

endif()

else()

message(SEND_ERROR "middleware_multicore_erpc_common dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
