project(demo)

# source files
set(SRC_FILES 
    UDL_Distance.cpp
)

# header files
# set(HDR_FILES 
#     demo.h
# )

# create an executable and link the source and header files
add_executable(${PROJECT_NAME} ${SRC_FILES} )