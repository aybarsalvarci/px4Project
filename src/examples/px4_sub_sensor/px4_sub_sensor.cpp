#include <px4_platform_common/log.h>
#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <poll.h>
#include <px4_platform_common/posix.h>

extern "C" __EXPORT int px4_sub_sensor_main(int argc, char *argv[])
{

	int sensor_sub_fd = orb_subscribe(ORB_ID(sensor_combined));

	px4_pollfd_struct_t fds[] = {
		{.fd = sensor_sub_fd, .events = POLLIN}
	};

	for (int i = 0; i < 5; i++) {
		int poll_ret = px4_poll(fds, 1, 1000);

		if ((poll_ret > 0) && (fds[0].revents & POLLIN)) {
			struct sensor_combined_s raw;

			orb_copy(ORB_ID(sensor_combined), sensor_sub_fd, &raw);

			PX4_INFO("Accelerometer:\t%8.4f\t%8.4f\t%8.4f",
				 (double)raw.accelerometer_m_s2[0],
				 (double)raw.accelerometer_m_s2[1],
				 (double)raw.accelerometer_m_s2[2]
				);
		}
	}

	return 0;
}
