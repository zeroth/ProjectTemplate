add_executable(myapp
    src/main.cpp
)

target_link_libraries(myapp
    PRIVATE
        mylib
)

install(TARGETS myapp
    RUNTIME DESTINATION bin
) 