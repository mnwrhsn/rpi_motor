
/*	TO COMPILE:
*	g++ -std=c++11  test.cpp source/*.cpp -o test -lpthread 
*/


#include <thread>
#include <chrono>
#include "source/adafruitmotorhat.h"
//using namespace std;

int main()
{
    //using namespace std::chrono_literals;

    // connect using the default device address 0x60
    AdafruitMotorHAT hat;

    // get the motor connected to port 1
    if (auto motor { hat.getMotor (1) })
    {
        // speed must be set before running commands
        motor->setSpeed (255);

        motor->run (AdafruitDCMotor::kForward);
        //std::this_thread::sleep_for (1s);

        motor->run (AdafruitDCMotor::kBackward);
        //std::this_thread::sleep_for (1s);

        // release the motor after use
        motor->run (AdafruitDCMotor::kRelease);
    }

    return 0;
}