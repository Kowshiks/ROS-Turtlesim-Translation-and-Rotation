#ifndef TURTLESIM_KINEMATICS_H
#define TURTLESIM_KINEMATICS_H

#include <ros/ros.h>
#include <turtlesim/Pose.h>

class TurtlesimKinematics
{

public:

    TurtlesimKinematics();

    // These 2 functions will be executed by the subscribers of the Topic when new poses are received.

    void turtle1PoseCallback(const turtlesim::Pose& pose);

    void turtle2PoseCallback(const turtlesim::Pose& pose);


private:

    // The private field contains the SUbscriber and Publisher implementation

    ros::NodeHandle nh;
    ros::Subscriber turtle1_pos_sub;
    ros::Subscriber turtle2_pos_sub;

    turtlesim::Pose last_turtle1_pos;
    turtlesim::Pose last_turtle2_pos;

};

#endif