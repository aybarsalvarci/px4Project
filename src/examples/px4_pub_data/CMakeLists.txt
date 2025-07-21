px4_add_module(
	MODULE examples__px4_pub_data
	MAIN px4_pub_data
	STACK_MAIN 2000
	SRCS
		px4_pub_data.cpp
	DEPENDS
		px4_platform
		uORB
)
