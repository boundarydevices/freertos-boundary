INCLUDE(CMakeForceCompiler)

# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

 
# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})


SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -g")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -Wall")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fno-common")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mthumb")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mapcs")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -std=gnu99")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -Wall")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fno-common")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mthumb")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mapcs")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -std=gnu99")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -g")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -Wall")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -fno-common")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -fdata-sections")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -ffreestanding")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -fno-builtin")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -mthumb")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -mapcs")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -std=gnu99")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_DDR_DEBUG "${CMAKE_ASM_FLAGS_DDR_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -Wall")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -fno-common")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -fdata-sections")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -ffreestanding")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -fno-builtin")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -mthumb")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -mapcs")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -std=gnu99")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_DDR_RELEASE "${CMAKE_ASM_FLAGS_DDR_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-common")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mthumb")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mapcs")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=gnu99")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -MMD")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -MP")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Os")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fno-common")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mthumb")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mapcs")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=gnu99")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -MMD")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -MP")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -g")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -O0")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -Wall")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -fno-common")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -ffunction-sections")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -fdata-sections")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -ffreestanding")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -fno-builtin")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -mthumb")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -mapcs")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -std=gnu99")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -MMD")

SET(CMAKE_C_FLAGS_DDR_DEBUG "${CMAKE_C_FLAGS_DDR_DEBUG} -MP")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -Os")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -Wall")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -fno-common")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -ffunction-sections")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -fdata-sections")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -ffreestanding")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -fno-builtin")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -mthumb")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -mapcs")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -std=gnu99")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -MMD")

SET(CMAKE_C_FLAGS_DDR_RELEASE "${CMAKE_C_FLAGS_DDR_RELEASE} -MP")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-common")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mthumb")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mapcs")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-rtti")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -MMD")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -MP")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-common")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mthumb")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mapcs")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-rtti")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -MMD")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -MP")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -g")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -O0")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -fno-common")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -fdata-sections")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -ffreestanding")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -fno-builtin")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -mthumb")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -mapcs")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -fno-rtti")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -MMD")

SET(CMAKE_CXX_FLAGS_DDR_DEBUG "${CMAKE_CXX_FLAGS_DDR_DEBUG} -MP")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -DCPU_MIMX8MQ6DVAJZ")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -Os")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -Wall")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -fno-common")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -fdata-sections")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -ffreestanding")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -fno-builtin")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -mthumb")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -mapcs")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -fno-rtti")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -MMD")

SET(CMAKE_CXX_FLAGS_DDR_RELEASE "${CMAKE_CXX_FLAGS_DDR_RELEASE} -MP")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -static")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -z")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -static")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -z")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -static")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -z")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -g")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -static")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -z")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -mfpu=fpv4-sp-d16")

include_directories(${ProjDirPath}/..)

include_directories(${ProjDirPath}/../../..)

include_directories(${ProjDirPath}/../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F)

include_directories(${ProjDirPath}/../../../../../CMSIS/Include)

include_directories(${ProjDirPath}/../../../../../devices)

include_directories(${ProjDirPath}/../../../../../rtos/freertos/Source/include)

include_directories(${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/platform/imx8mq_m4)

include_directories(${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include)

include_directories(${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers)

include_directories(${ProjDirPath}/../../../../../devices/MIMX8MQ6)

include_directories(${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/io)

include_directories(${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/str)

include_directories(${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/log)

include_directories(${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities)

add_executable(rpmsg_lite_str_echo_rtos_imxcm4.elf 
"${ProjDirPath}/../fsl_iomuxc.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${ProjDirPath}/../main_remote.c"
"${ProjDirPath}/../FreeRTOSConfig.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../rpmsg_config.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/platform/imx8mq_m4/rpmsg_platform.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/rpmsg_lite/porting/platform/imx8mq_m4/rpmsg_platform.c"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/rpmsg_lite/porting/environment/rpmsg_env_freertos.c"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/rpmsg_env.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/rpmsg_queue.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/rpmsg_lite/rpmsg_queue.c"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/rpmsg_lite.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/rpmsg_ns.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/llist.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/rpmsg_default_config.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/virtio_ring.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/virtqueue.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/include/rpmsg_compiler.h"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/common/llist.c"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/rpmsg_lite/rpmsg_lite.c"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/rpmsg_lite/rpmsg_ns.c"
"${ProjDirPath}/../../../../../middleware/multicore/rpmsg_lite/lib/virtio/virtqueue.c"
"${ProjDirPath}/../../../../../rtos/freertos/FreeRTOS_for_MCUXpresso_SDK_v2.0.txt"
"${ProjDirPath}/../../../../../rtos/freertos/License/license.txt"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/croutine.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/event_groups.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/FreeRTOS.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/list.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/mpu_wrappers.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/portable.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/projdefs.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/queue.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/semphr.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/StackMacros.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/stdint.readme"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/task.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/timers.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/deprecated_definitions.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/include/freertos_tasks_c_additions.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/croutine.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/list.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/queue.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/readme.txt"
"${ProjDirPath}/../../../../../rtos/freertos/Source/tasks.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/timers.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/event_groups.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/portable/readme.txt"
"${ProjDirPath}/../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/fsl_tickless_generic.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/fsl_tickless_systick.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/port.c"
"${ProjDirPath}/../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/portmacro.h"
"${ProjDirPath}/../../../../../rtos/freertos/Source/portable/MemMang/heap_4.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_clock.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_clock.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_common.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_common.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_rdc.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_rdc.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/io/fsl_io.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/io/fsl_io.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/log/fsl_log.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/log/fsl_log.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/str/fsl_str.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/str/fsl_str.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/fsl_debug_console.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/fsl_debug_console.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/fsl_debug_console_conf.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/system_MIMX8MQ6_cm4.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/system_MIMX8MQ6_cm4.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/gcc/startup_MIMX8MQ6_cm4.S"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_uart.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_uart.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/utilities/fsl_assert.c"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_mu.h"
"${ProjDirPath}/../../../../../devices/MIMX8MQ6/drivers/fsl_mu.c"
)


set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -T${ProjDirPath}/MIMX8MQ6xxxJZ_cm4_ram.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -T${ProjDirPath}/MIMX8MQ6xxxJZ_cm4_ram.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DDR_DEBUG} -T${ProjDirPath}/MIMX8MQ6xxxJZ_cm4_ddr_ram.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE "${CMAKE_EXE_LINKER_FLAGS_DDR_RELEASE} -T${ProjDirPath}/MIMX8MQ6xxxJZ_cm4_ddr_ram.ld -static")

TARGET_LINK_LIBRARIES(rpmsg_lite_str_echo_rtos_imxcm4.elf -Wl,--start-group)
target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf debug m)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf debug c)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf debug gcc)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf debug nosys)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized m)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized c)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized gcc)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized nosys)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized m)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized c)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized gcc)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized nosys)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized m)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized c)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized gcc)

target_link_libraries(rpmsg_lite_str_echo_rtos_imxcm4.elf optimized nosys)

TARGET_LINK_LIBRARIES(rpmsg_lite_str_echo_rtos_imxcm4.elf -Wl,--end-group)

ADD_CUSTOM_COMMAND(TARGET rpmsg_lite_str_echo_rtos_imxcm4.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY}
-Obinary ${EXECUTABLE_OUTPUT_PATH}/rpmsg_lite_str_echo_rtos_imxcm4.elf ${EXECUTABLE_OUTPUT_PATH}/rpmsg_lite_str_echo_rtos_imxcm4.bin)
