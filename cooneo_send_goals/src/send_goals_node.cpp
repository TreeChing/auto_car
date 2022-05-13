#include <iostream>
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char ** argv){
    ros::init(argc, argv, "send_goals_node");
    MoveBaseClient ac("move_base", true);
    uint8_t goals_number = 4;

    while(!ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the move_base action server to come up.");
    }

    move_base_msgs::MoveBaseGoal goals[goals_number];

    //The first goal in the "map" frame.
    goals[0].target_pose.pose.position.x = 1.8450011;
    goals[0].target_pose.pose.position.y = -0.88307857;
    goals[0].target_pose.pose.orientation.z = -0.3065959;
    goals[0].target_pose.pose.orientation.w = -0.95183976;

    //The second goal in the "map" frame.
    goals[1].target_pose.pose.position.x = 3.243586;
    goals[1].target_pose.pose.position.y = 0.97767937;
    goals[1].target_pose.pose.orientation.z = 0.6478712;
    goals[1].target_pose.pose.orientation.w = 0.76174986;

    //The third goal in the "map" frame.
    goals[2].target_pose.pose.position.x = 2.41693687;
    goals[2].target_pose.pose.position.y = 1.646318674;
    goals[2].target_pose.pose.orientation.z = 0.9881494846;
    goals[2].target_pose.pose.orientation.w = 0.1534946;

    //The forth goal in the "map" frame.
    goals[3].target_pose.pose.position.x = -0.9701852798;
    goals[3].target_pose.pose.position.y = 0.453477025;
    goals[3].target_pose.pose.orientation.z = 0.946238058;
    goals[3].target_pose.pose.orientation.w = -0.32347107;

    ROS_INFO("Init success!");

    while(goals_number){
        switch((4 - goals_number)){
            case 0:
                goals[4 - goals_number].target_pose.header.frame_id = "map";
                goals[4 - goals_number].target_pose.header.stamp = ros::Time::now();
                ac.sendGoal(goals[4 - goals_number]);
                ROS_INFO("Send NO. %d Goal", 4 - goals_number);
                break;
            case 1:
                goals[4 - goals_number].target_pose.header.frame_id = "map";
                goals[4 - goals_number].target_pose.header.stamp = ros::Time::now();
                ac.sendGoal(goals[4 - goals_number]);
                ROS_INFO("Send NO. %d Goal", 4 - goals_number);
                break;
            case 2:
                goals[4 - goals_number].target_pose.header.frame_id = "map";
                goals[4 - goals_number].target_pose.header.stamp = ros::Time::now();
                ac.sendGoal(goals[4 - goals_number]);
                ROS_INFO("Send NO. %d Goal", 4 - goals_number);
                break;
            case 3:
                goals[4 - goals_number].target_pose.header.frame_id = "map";
                goals[4 - goals_number].target_pose.header.stamp = ros::Time::now();
                ac.sendGoal(goals[4 - goals_number]);
                ROS_INFO("Send NO. %d Goal", 4 - goals_number);
                break;
            default:
                break;
        }
        ac.waitForResult();
        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
            ROS_INFO("The NO. %d Goal achieved success!", 4 - goals_number);
            goals_number--;
        }else{
            ROS_WARN("The NO. %d Goal Planning Failed for some reason", 4 - goals_number);
        }
        ros::Duration(5).sleep();
    }
    return 0;
}
