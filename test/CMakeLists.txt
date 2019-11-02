enable_testing()
find_package(GTest REQUIRED)

set(
	TESTS
	"src/geometry/LineTest.cpp"
        "src/geometry/PointTest.cpp"
	"src/main.cpp"
)

add_executable(tests ${TESTS})
target_link_libraries(tests gmock GTest::GTest GTest::Main geometry)


