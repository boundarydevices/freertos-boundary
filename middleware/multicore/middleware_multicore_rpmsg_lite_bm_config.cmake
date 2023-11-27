# Add set(CONFIG_USE_middleware_multicore_rpmsg_lite_bm_config true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_multicore_rpmsg_lite AND (CONFIG_BOARD STREQUAL mcimx93evk) AND CONFIG_USE_middleware_multicore_rpmsg_lite_imx93_m33_bm)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/rpmsg_lite/template_application
)

else()

message(SEND_ERROR "middleware_multicore_rpmsg_lite_bm_config dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
