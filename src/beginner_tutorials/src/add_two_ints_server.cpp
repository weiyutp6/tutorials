#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
using namespace ros;
bool add(beginner_tutorials::AddTwoInts::Request &req, beginner_tutorials::AddTwoInts::Response &res){
    res.sum = req.a + req.b;
    ROS_INFO("request: x=%1d, y=%1d",(long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%1d]",(long int)res.sum);
    return true;
}

int main(int argc, char** argv){
    init(argc, argv, "add_two_ints_server");
    NodeHandle n;

    ServiceServer service = n.advertiseService("add_two_ints",add);
    ROS_INFO("Ready to add two ints.");
    spin();

    return 0;
}
