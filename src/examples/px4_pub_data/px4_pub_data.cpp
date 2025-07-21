#include <px4_platform_common/log.h>
#include <uORB/uORB.h>
#include <uORB/topics/vehicle_attitude.h>
#include <bits/stdc++.h>

extern "C" __EXPORT int px4_pub_data_main(int argc, char *argv[])
{
	PX4_INFO("Module has been started.");

	struct vehicle_attitude_s att;
	memset(&att, 0, sizeof(att));

	orb_advert_t att_pub_fd = orb_advertise(ORB_ID(vehicle_attitude), &att);

	att.q[0] = 4312;
	att.q[1] = 4314;
	att.q[2] = 431;

	orb_publish(ORB_ID(vehicle_attitude), att_pub_fd, &att);

	PX4_INFO("Module stopped.");
	return 0;
}
