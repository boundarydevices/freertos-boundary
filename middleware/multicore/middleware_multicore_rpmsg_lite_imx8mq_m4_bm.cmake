# Add set(CONFIG_USE_middleware_multicore_rpmsg_lite_imx8mq_m4_bm true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if((CONFIG_BOARD STREQUAL evkmimx8mq))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/rpmsg_lite/lib/rpmsg_lite/porting/platform/imx8mq_m4/rpmsg_platform.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/rpmsg_lite/lib/include/platform/imx8mq_m4
)

else()

message(SEND_ERROR "middleware_multicore_rpmsg_lite_imx8mq_m4_bm dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
