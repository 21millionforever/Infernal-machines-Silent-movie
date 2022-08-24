project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h
        Polygon.cpp Polygon.h include/machine-api.h ActualMachine.cpp ActualMachine.h Machine1Factory.cpp Machine1Factory.h WorkingMachine.cpp WorkingMachine.h Component.cpp Component.h Motor.cpp Motor.h Shape.cpp Shape.h Machine2Factory.cpp Machine2Factory.h Gear.cpp Gear.h RotationSource.cpp RotationSource.h RotationSink.cpp RotationSink.h Sink.cpp Sink.h Arm.cpp Arm.h Lever.cpp Lever.h Rod.cpp Rod.h PositionSource.cpp PositionSource.h PositionSink.cpp PositionSink.h RodSink.cpp RodSink.h RodSource.cpp RodSource.h Piston.cpp Piston.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)


# Copy resources into output directory
file(COPY resources/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

if(APPLE)
    # When building for MacOS, also copy resources into the bundle resources
    set(RESOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources)
    file(COPY resources/ DESTINATION ${RESOURCE_DIR}/)
endif()