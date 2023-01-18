include_guard()
message("driver_ecspi_freertos component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_ecspi_freertos.c
)


target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(driver_ecspi_MIMX8MQ6)

include(middleware_freertos-kernel_MIMX8MQ6)

