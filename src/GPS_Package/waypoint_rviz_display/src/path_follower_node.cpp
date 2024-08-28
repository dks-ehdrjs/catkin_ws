#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/PoseStamped.h>
#include <cmath>
#include <tf/tf.h>
#include "tf/transform_listener.h"

class StanleyController
{
public:
    StanleyController()
    {
        // 스탠리 알고리즘 매개변수 설정
        k_ = 0.5;  // 제어 게인
        max_steer_ = M_PI / 6;  // 최대 조향각 (30도)
        target_velocity_ = 1.0;  // 목표 속도 (예시로 1.0 m/s로 설정)

        // ROS 노드 핸들러
        ros::NodeHandle nh;

        // 구독자(subscriber) 설정
        path_sub_ = nh.subscribe("/planned_path", 10, &StanleyController::pathCallback, this);
        velocity_sub_ = nh.subscribe("/current_velocity", 10, &StanleyController::velocityCallback, this);

        // 퍼블리셔(publisher) 설정
        goal_angle_pub_ = nh.advertise<std_msgs::Float64>("/goal_angle", 10);
        goal_velocity_pub_ = nh.advertise<std_msgs::Float64>("/goal_velocity", 10);

        // TF listener 초기화
        listener_ = new tf::TransformListener();
    }

    ~StanleyController()
    {
        delete listener_;
    }

    void pathCallback(const nav_msgs::Path::ConstPtr& msg)
    {
        path_ = *msg;
    }

    void velocityCallback(const std_msgs::Float64::ConstPtr& msg)
    {
        // km/h를 m/s로 변환하여 v_에 저장
        v_ = msg->data * 0.27778;
    }

    void controlLoop()
    {
        ros::Rate rate(30);  // 30Hz 주기로 제어

        while (ros::ok())
        {   
            tf::StampedTransform transform;
            try {
                listener_->lookupTransform("map", "gps_footprint", ros::Time(0), transform);
            } catch (tf::TransformException &ex) {
                ROS_ERROR("%s", ex.what());
                ros::Duration(1.0).sleep();
                continue;
            }

            // gps_footprint_pose를 x_, y_, yaw_에 대입
            x_ = transform.getOrigin().x();
            y_ = transform.getOrigin().y();
            yaw_ = tf::getYaw(transform.getRotation());

            if (!path_.poses.empty())
            {
                // 스탠리 알고리즘에 의한 조향각 계산
                double steer_angle = calculateSteeringAngle();

                // 조향각 퍼블리시
                std_msgs::Float64 goal_angle_msg;
                goal_angle_msg.data = steer_angle;
                goal_angle_pub_.publish(goal_angle_msg);

                // 목표 속도 퍼블리시
                std_msgs::Float64 goal_velocity_msg;
                goal_velocity_msg.data = target_velocity_;
                goal_velocity_pub_.publish(goal_velocity_msg);
            }

            ros::spinOnce();
            rate.sleep();
        }
    }

private:
    double calculateSteeringAngle()
    {
        // 현재 위치에서 가장 가까운 경로점 찾기
        double min_dist = std::numeric_limits<double>::max();
        int target_index = 0;

        for (int i = 0; i < path_.poses.size(); ++i)
        {   
            
            double dx = path_.poses[i].pose.position.x - x_;
            double dy = path_.poses[i].pose.position.y - y_;
            double dist = std::sqrt(dx * dx + dy * dy);

            if (dist < min_dist)
            {
                min_dist = dist;
                target_index = i;
            }
        }
        ROS_INFO("target_index: %d",target_index);
        // 경로와의 횡오차 계산
        double dx = path_.poses[target_index].pose.position.x - x_;
        double dy = path_.poses[target_index].pose.position.y - y_;
        double path_yaw = std::atan2(dy, dx);
        
        ROS_INFO("path_.poses[target_index].pose.position.x : %f",path_.poses[target_index].pose.position.x);
        double cross_track_error = std::sin(path_yaw - yaw_) * min_dist;

        // 스탠리 알고리즘 적용하여 조향각 계산
        double steering = path_yaw - yaw_ + std::atan2(k_ * cross_track_error, v_);

        // 조향각을 최대 조향각으로 제한
        steering = std::max(-max_steer_, std::min(max_steer_, steering));

        return steering;
    }

    // ROS 관련 변수
    ros::Subscriber path_sub_;
    ros::Subscriber velocity_sub_;
    ros::Publisher goal_angle_pub_;
    ros::Publisher goal_velocity_pub_;
    tf::TransformListener* listener_;

    // 차량 상태 변수
    double x_, y_, yaw_, v_;

    // 경로 변수
    nav_msgs::Path path_;

    // 스탠리 알고리즘 매개변수
    double k_;
    double max_steer_;
    double target_velocity_;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "stanley_controller");

    StanleyController controller;
    controller.controlLoop();

    return 0;
}
