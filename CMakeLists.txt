cmake_minimum_required(VERSION 3.16)
set(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)

####################################
#  Target-specific stuff
set(TARGET_CPU ATmega328)
#  End of target-specific stuff
####################################

###################################
#  Machine-specific stuff
set(AVR_DUDE_EXECUTABLE C:/tools/avrdude-6.3-mingw32/avrdude.exe)
set(AVR_DUDE_PORT COM13)
set(AVR_OBJCOPY_EXECUTABLE C:/tools/avrdude-6.3-mingw32/avr-objdump.exe)
#  End of machine-specific stuff
###################################

project(clion_avr_c_demo CXX C)

include(CMakeVerifyCompiler.txt)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

add_compile_definitions("__AVR_${TARGET_CPU}__")

add_link_options(-Wl,--print-memory-usage)

add_executable(${PROJECT_NAME} src/main.cpp)

#### Uncomment this to see flashing process details
#set(FLASH_VERBOSE_FLAG "-v")

add_custom_target(LINK
        ${AVR_OBJCOPY_EXECUTABLE} -j .text -j .data -O binary ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin
        DEPENDS ${PROJECT_NAME}
        COMMENT "Link into a flashable binary")

add_custom_target(FLASH
        ${AVR_DUDE_EXECUTABLE} -p ${TARGET_CPU} -c arduino -b115200 -P ${AVR_DUDE_PORT} ${FLASH_VERBOSE_FLAG} -F -D -U flash:w:${PROJECT_BINARY_DIR}/${PROJECT_NAME}:a
        DEPENDS LINK
        COMMENT "Flash to ${TARGET_CPU}")

