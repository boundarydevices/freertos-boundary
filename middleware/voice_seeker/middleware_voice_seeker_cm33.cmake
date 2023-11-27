# Add set(CONFIG_USE_middleware_voice_seeker_cm33 true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_voice_seeker_template AND (CONFIG_BOARD STREQUAL mcimx93evk) AND CONFIG_USE_middleware_voice_seeker_rdsp_utilities_public)

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/ARM_CortexM33/include
)
endif()

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
  target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE
    -Wl,--start-group
      ${CMAKE_CURRENT_LIST_DIR}/ARM_CortexM33/lib/libvoiceseeker_no_aec.a
      -Wl,--end-group
  )
endif()

else()

message(SEND_ERROR "middleware_voice_seeker_cm33 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
