#include "ros/ros.h"
#include "beginner_tutorials/hour.h"
#include <time.h>

bool hour(class_6::Request &req, class_6::hour::Response &res)
{

time_t heure = time(NULL);
struct tm *temps = localtime(&heure);

res.hour = temps->tm_hour;
res.min = temps->tm_min;
ros.sec = temps->tm_sec;
ROS_INFO("Envoi de l'heure en cours");
return true;

}

int main(int argc, char **argv)
{

ros::init(argc, argv, "serveur");
ros::NodeHandle n;

ros::ServiceServer service = n.advertiseService("hour", hour);
RS_INFO("Prêt à envoyer l'heure");
ros::spin();

return ;
}

