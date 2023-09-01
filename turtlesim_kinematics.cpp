#include "bumperbot_examples/turtlesim_kinematics.h"


TurtlesimKinematics::TurtlesimKinematics()
{

    turtle1_pos_sub = nh.subscribe("/turtle1/pose", 1000, &TurtlesimKinematics::turtle1PoseCallback, this); // This will be listening to the topic /turtle1/pose
    turtle2_pos_sub = nh.subscribe("/turtle2/pose", 1000, &TurtlesimKinematics::turtle2PoseCallback, this); // This will be listening to the topic /turtle2/pose

}

void TurtlesimKinematics::turtle1PoseCallback(const turtlesim::Pose& pose)
{
    last_turtle1_pos = pose;
}

void TurtlesimKinematics::turtle2PoseCallback(const turtlesim::Pose& pose)
{
    last_turtle2_pos = pose;

    //Translation vector

    float Tx = last_turtle2_pos.x - last_turtle1_pos.x;
    float Ty = last_turtle2_pos.y - last_turtle1_pos.y;

    float theta_rad = last_turtle2_pos.theta - last_turtle1_pos.theta;
    float theta_deg = 180 * theta_rad / 3.14;

    ROS_INFO_STREAM("--------------------\n"<<"Translation Vector turtle1 -> turtle2\n"<<
                    "Tx : "<<Tx<<"\n"<<"Ty : "<<Ty<<"\n"<<
                    "Rotation Matrix turtle1 -> turtle2\n"<<
                    "theta (rad): "<<theta_rad<<"\n"<<
                    "theta (deg): "<<theta_deg<<"\n"<<
                    "| R11     R12|    |"<<std::cos(theta_rad)<<"\t"<<-std::sin(theta_rad)<<"|\n"<<
                    "| R21     R22|    |"<<std::sin(theta_rad)<<"\t"<<std::cos(theta_rad)<<"|\n");
}