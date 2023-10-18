# Add set(CONFIG_USE_component_i3c_bus_adapter true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_driver_i3c AND CONFIG_USE_component_i3c_bus)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/fsl_component_i3c_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/.
)

else()

message(SEND_ERROR "component_i3c_bus_adapter.MIMX8UD7 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
