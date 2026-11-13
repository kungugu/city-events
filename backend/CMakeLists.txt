
cmake_minimum_required(VERSION 3.24)

project(CityEventsBackend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Drogon CONFIG REQUIRED)

add_executable(backend
    src/main.cpp
    src/controllers/EventController.cpp
)

target_link_libraries(backend PRIVATE Drogon::Drogon)
