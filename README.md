# Covid19-Health-Monitoring-System
A wearable that gives a patients heart rate and temperature to doctors without any contact!

## Where we started

The world is currently in a very unusual dilemma, also known as the novel Covid 19. With over 10 million Covid 19 cases around the world, one of the most challenging jobs are those of doctors. As a team, we wanted to help protect these doctors. The basic idea we had in our minds was finding a way to reduce physical contact in between the doctors and patients, because Covid 19 can spread quickly in this manner. After some research and a few failed ideas, we found out that doctors constantly check a symptomatic patient's temperature and heart rate. Both of these include some form of physical contact, and thus we found a somewhat small but significant problem the doctors face. Along with this, a machine that detects and presents this data could be very useful when there is a shortage of medical personnel.

## How we wanted to solve it

In simple terms, we wanted to find a way that doctors could measure any patients temperature and heart rate without any form of physical contact. Our first instinct was to use the Internet of Things(IoT). We wanted to get the data from our sensors and send it to a server where it would display the data. With some more research, we found two sensors which could measure the temperature along with the heart rate of a user. They were the LM35 temperature and MAX30102 heart rate sensors. To give it WiFi capabilities, we decided to use the ESP8266 NodeMCU and the MQTT protocol to send the data from our micro controller to the server. Now that we had a plan, we wanted to assign jobs to everyone, and this project had enough content for everyone to contribute a fair share of their thinking. There were three jobs, the software, the hardware, and the code for the server. After assembling the hardware, we moved on to the coding part, which was the most interesting yet most frustrating part of our project. With lots of trial and error, we got the code to work, with just a few hours left to submit our creation.

## How it works

Applications of the longtime monitoring device were limited but significant. A Covid 19 patient could wear this device for as long as the doctors would need him or her to. The temperature and heart rate of the patient gets recorded every 30 seconds, and will go to our server where it will be added to a graph. Doctors will be able to see the growth or decrease of a certain patients temperature and heart rate with less of a threat of catching the virus in the process. This project could be enhanced with blood oxygen saturation(SpO2) measurement capabilities. Low SpO2 could show sleep apnea, breathing problems, and other unhealthy symptoms of Covid 19, which could help many people. It could also be further revamped with a notification system that could alert the user if his or her temperature, heart rate, or SpO2 is dangerously high or low. This device will also reduce the number of personnel needed, which could potentially protect more lives.

## The final part of the project

After we got our device to successfully work, we approached the final step: the looks. We wanted the device to look appealing to the eye. We made our own case and designed the outside. We finally finished our project.

This was a very enlightening and extraordinary experience for all of us, and we learned plenty from our failed and successful attempts.

Thank you for reading this,

Sharvayu Chavan, Pratham Bumb, and Shrenik Jangada.
