# Add set(CONFIG_USE_driver_display-it6161 true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_driver_video-common AND CONFIG_USE_driver_video-i2c AND CONFIG_USE_driver_display-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/fsl_it6161.c
  ${CMAKE_CURRENT_LIST_DIR}/hdmi_tx.c
  ${CMAKE_CURRENT_LIST_DIR}/mipi_rx.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/.
)

else()

message(SEND_ERROR "driver_display-it6161.MIMX9352 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
