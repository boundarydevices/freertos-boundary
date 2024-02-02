# Add set(CONFIG_USE_middleware_voice_spot_fusionf1_imx8ULP true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if((CONFIG_BOARD STREQUAL evkmimx8ulp) AND CONFIG_USE_middleware_voice_spot_model AND CONFIG_USE_middleware_naturedsp_naturedsp_fusionf1)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/iMX8ULP_FusionF1/rdsp_utilities_public/rdsp_memory_utils_public/RdspMemoryUtilsPublic.c
  ${CMAKE_CURRENT_LIST_DIR}/iMX8ULP_FusionF1/rdsp_utilities_public/rdsp_memory_utils_public/memcheck.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/iMX8ULP_FusionF1/lib/include
  ${CMAKE_CURRENT_LIST_DIR}/iMX8ULP_FusionF1/rdsp_utilities_public/include
  ${CMAKE_CURRENT_LIST_DIR}/iMX8ULP_FusionF1/rdsp_utilities_public/rdsp_memory_utils_public
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  if(CONFIG_TOOLCHAIN STREQUAL xtensa)
    target_compile_options(${MCUX_SDK_PROJECT_NAME} PUBLIC
    )
  endif()
  if(CONFIG_TOOLCHAIN STREQUAL xcc)
    target_compile_options(${MCUX_SDK_PROJECT_NAME} PUBLIC
    )
  endif()

endif()

if((CONFIG_TOOLCHAIN STREQUAL xcc OR CONFIG_TOOLCHAIN STREQUAL xtensa))
  target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE
    -Wl,--start-group
      ${CMAKE_CURRENT_LIST_DIR}/iMX8ULP_FusionF1/lib/libvoicespot.a
      -Wl,--end-group
  )
endif()

else()

message(SEND_ERROR "middleware_voice_spot_fusionf1_imx8ULP dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
