# Add set(CONFIG_USE_driver_dc-fb-lcdif true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_driver_dc-fb-common AND CONFIG_USE_driver_lcdif)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/fsl_dc_fb_lcdif.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/.
)

else()

message(SEND_ERROR "driver_dc-fb-lcdif.MIMX8UD7 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
