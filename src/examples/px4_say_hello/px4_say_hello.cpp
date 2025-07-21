#include <px4_platform_common/log.h>

extern "C" __EXPORT int px4_say_hello_main(int argc, char *argv[]);

extern "C" __EXPORT int px4_say_hello_main(int argc, char *argv[])
{
	PX4_INFO("Hellooo!");
	return OK;
}
