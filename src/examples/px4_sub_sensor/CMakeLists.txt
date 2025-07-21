px4_add_module(
	MODULE examples__px4_sub_sensor
	MAIN px4_sub_sensor
	STACK_MAIN 2000
	SRCS
		px4_sub_sensor.cpp
	DEPENDS
		px4_platform
		uORB

)
