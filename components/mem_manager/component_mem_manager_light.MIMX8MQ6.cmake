# Add set(CONFIG_USE_component_mem_manager_light true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/fsl_component_mem_manager_light.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/.
)

else()

message(SEND_ERROR "component_mem_manager_light.MIMX8MQ6 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
