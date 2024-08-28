#include "ros/ros.h"
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"
#include "nav_msgs/Odometry.h"
#include "tf/tf.h"
#include "tf/transform_listener.h"

ros::Publisher path_pub;
geometry_msgs::PoseStamped gps_footprint_pose;
bool gps_footprint_received = false;

void markerCallback(const visualization_msgs::MarkerArray::ConstPtr& marker_array, tf::TransformListener* listener)
{   
    

    if (!gps_footprint_received)
    {
        try
        {
            tf::StampedTransform transform;
            listener->lookupTransform("map", "gps_footprint", ros::Time(0), transform);

            gps_footprint_pose.header.frame_id = "map";
            gps_footprint_pose.header.stamp = ros::Time::now();

            gps_footprint_pose.pose.position.x = transform.getOrigin().x();
            gps_footprint_pose.pose.position.y = transform.getOrigin().y();
            gps_footprint_pose.pose.position.z = 0;

            gps_footprint_pose.pose.orientation.x = transform.getRotation().x();
            gps_footprint_pose.pose.orientation.y = transform.getRotation().y();
            gps_footprint_pose.pose.orientation.z = transform.getRotation().z();
            gps_footprint_pose.pose.orientation.w = transform.getRotation().w();

            gps_footprint_received = true;
        }
        catch (tf::TransformException &ex)
        {
            ROS_WARN("%s", ex.what());
            ros::Duration(1.0).sleep();
            return;
        }
    }

    nav_msgs::Path path;
    path.header.frame_id = "map";
    path.header.stamp = ros::Time::now();

    // Start with the GPS footprint position
    path.poses.push_back(gps_footprint_pose);

    size_t i = 0;
while (i < marker_array->markers.size())
{
    ROS_INFO("marker_array->markers.size() = %ld",marker_array->markers.size());
    const auto& marker = marker_array->markers[i];

    geometry_msgs::PoseStamped pose;
    pose.header.frame_id = "map";
    pose.header.stamp = ros::Time::now();

    pose.pose.position.x = marker.pose.position.x;
    pose.pose.position.y = marker.pose.position.y;
    pose.pose.position.z = 0;

    // 각 웨이포인트를 따라가는 경로이므로, 웨이포인트 간의 각도는 유지합니다.
    pose.pose.orientation = marker.pose.orientation;

    path.poses.push_back(pose);

    i++;
}


    path_pub.publish(path);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "waypoint_planner_node");
    ros::NodeHandle nh;

    tf::TransformListener listener;

    ros::Subscriber marker_sub = nh.subscribe<visualization_msgs::MarkerArray>("/marker/node", 1, boost::bind(markerCallback, _1, &listener));
    path_pub = nh.advertise<nav_msgs::Path>("/planned_path", 1, true);

    ros::spin();

    return 0;
}
