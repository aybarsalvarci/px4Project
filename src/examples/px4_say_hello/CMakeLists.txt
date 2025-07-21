px4_add_module(
	MODULE examples__px4_say_hello
	MAIN px4_say_hello
	STACK_MAIN 2000
	SRCS
		px4_say_hello.cpp
	DEPENDS
)
