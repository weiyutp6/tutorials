#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std_msgs;
using namespace ros;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main (int argc, char **argv)
{
    init(argc, argv, "listener");
    NodeHandle n;
    Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    spin();
    return 0;
}
