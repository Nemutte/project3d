add_executable(${PROJECT3D}
	${CMAKE_CURRENT_SOURCE_DIR}/src/model.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/model.h
	
	${CMAKE_CURRENT_SOURCE_DIR}/src/camera.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/camera.h
	
	${CMAKE_CURRENT_SOURCE_DIR}/src/v3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/v3.h
	
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/main.h
)

target_include_directories(${PROJECT3D} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)

set (SFML_LIB_NAME SFML)
FetchContent_Declare(
	${SFML_LIB_NAME}
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.6.1
	GIT_SHALLOW FALSE
)
FetchContent_MakeAvailable(${SFML_LIB_NAME})

target_link_libraries(${PROJECT3D} PUBLIC sfml-graphics)
target_link_libraries(${PROJECT3D} PUBLIC sfml-window)
target_link_libraries(${PROJECT3D} PUBLIC sfml-system)

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
	add_custom_command( 
		TARGET ${TARGET_NAME}
		POST_BUILD
		COMMAND
		${CMAKE_COMMAND} -E copy_directory
		$<TARGET_FILE_DIR:${LIB_NAME}>
		$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibDirToTarget(sfml-graphics ${PROJECT3D})
CopyLibDirToTarget(sfml-window ${PROJECT3D})
CopyLibDirToTarget(sfml-system ${PROJECT3D})