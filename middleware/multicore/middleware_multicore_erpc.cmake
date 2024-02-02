# Add set(CONFIG_USE_middleware_multicore_erpc true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(((CONFIG_DEVICE_ID STREQUAL K32L2B11xxxxA OR CONFIG_DEVICE_ID STREQUAL K32L2B21xxxxA OR CONFIG_DEVICE_ID STREQUAL K32L2B31xxxxA OR CONFIG_DEVICE_ID STREQUAL K32L3A60xxx OR CONFIG_DEVICE_ID STREQUAL LPC5534 OR CONFIG_DEVICE_ID STREQUAL LPC5536 OR CONFIG_DEVICE_ID STREQUAL LPC55S36 OR CONFIG_DEVICE_ID STREQUAL LPC55S69 OR CONFIG_DEVICE_ID STREQUAL LPC55S66 OR CONFIG_DEVICE_ID STREQUAL MIMXRT1165xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMXRT1166xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMXRT1171xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMXRT1172xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMXRT1173xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMXRT1175xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMXRT1176xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMXRT595S OR CONFIG_DEVICE_ID STREQUAL MIMXRT633S OR CONFIG_DEVICE_ID STREQUAL MIMXRT685S OR CONFIG_DEVICE_ID STREQUAL MCIMX7U3xxxxx OR CONFIG_DEVICE_ID STREQUAL MCIMX7U5xxxxx OR CONFIG_DEVICE_ID STREQUAL MIMX8UD3xxx08 OR CONFIG_DEVICE_ID STREQUAL MIMX8UD5xxx08 OR CONFIG_DEVICE_ID STREQUAL MIMX8UD7xxx08 OR CONFIG_DEVICE_ID STREQUAL MIMX8US3xxx08 OR CONFIG_DEVICE_ID STREQUAL MIMX8US5xxx08) OR (CONFIG_BOARD STREQUAL frdmk22f OR CONFIG_BOARD STREQUAL frdmk32l2b OR CONFIG_BOARD STREQUAL evkmcimx7ulp OR CONFIG_BOARD STREQUAL frdmk32l3a6 OR CONFIG_BOARD STREQUAL lpcxpresso55s69 OR CONFIG_BOARD STREQUAL lpcxpresso55s36 OR CONFIG_BOARD STREQUAL evkmimxrt1160 OR CONFIG_BOARD STREQUAL evkmimxrt1170 OR CONFIG_BOARD STREQUAL evkbmimxrt1170 OR CONFIG_BOARD STREQUAL evkmimxrt685 OR CONFIG_BOARD STREQUAL evkmimxrt1060)))

else()

message(SEND_ERROR "middleware_multicore_erpc dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
