#include "ros/ros.h"
#include "cal_service/calSrv.h"

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION	3
#define DIVISION	4

int my_operator = PLUS;

bool calculation(cal_service::calSrv::Request& req,
cal_service::calSrv::Response& res)
{
	switch (my_operator)
	{
		case PLUS:
			res.result = req.x + req.y;
			break;
		case MINUS:
			res.result = req.x - req.y;
			break;
		case MULTIPLICATION:
			res.result = req.x * req.y;
			break;
		case DIVISION:
			res.result = req.x / req.y;
			break;
		default:
			res.result = req.x + req.y;
			break;			
	}
	ROS_INFO("x: %d, y: %d, result: %d", req.x, req.y, res.result);
	return true;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "srv_server");
	ros::NodeHandle nh;

	nh.setParam("calculation_method", PLUS);

	ros::ServiceServer sv = nh.advertiseService("calculate", calculation);
	ros::Rate loop_rate(10);

	while(ros::ok())
	{	
		//command : rosparam list
		//rosrun <pkgName> <parameter_Val(1 ~ 4)
		nh.getParam("calculation_method", my_operator);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
