if(NOT DRIVER_AUDIOMIX_MIMX8ML8_INCLUDED)
    
    set(DRIVER_AUDIOMIX_MIMX8ML8_INCLUDED true CACHE BOOL "driver_audiomix component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_audiomix.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MIMX8ML8)

endif()
