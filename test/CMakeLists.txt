enable_testing()
find_package(GTest REQUIRED)

set(
	TESTS
	"src/geometry/shapesTest.cpp"
	"src/main.cpp"
)

add_executable(tests ${TESTS})
target_link_libraries(tests gmock GTest::GTest GTest::Main geometry)


