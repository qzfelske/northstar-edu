//#define FLY_SKY
#ifdef FLY_SKY

#include "subsystem/fly_sky_control_operator_interface.hpp"

#include <random>

#include <tap/architecture/clock.hpp>

#include "tap/algorithms/math_user_utils.hpp"
#include "tap/architecture/clock.hpp"
#include "tap/drivers.hpp"

using namespace tap::algorithms;
using namespace tap::communication::serial;

namespace src
{
namespace control
{
/* Chassis task 6:
For the translation methods here, dont worry about keyboard input. An example of accessing a channel
would be remote.getChannel(FlySky::Channel::LEFT_HORIZONTAL)
*/

float ControlOperatorInterface::getDrivetrainHorizontalTranslation()
{
    float horizontal = 0;
    horizontal += remote.getChannel(FlySky::Channel::LEFT_HORIZONTAL);
    return horizontal;
}
float ControlOperatorInterface::getDrivetrainVerticalTranslation()
{
    float vertical = 0;
    vertical += remote.getChannel(FlySky::Channel::LEFT_VERTICAL);
    return vertical;
}
float ControlOperatorInterface::getDrivetrainRotationalTranslation()
{
    float maxRotationSpeed = 3.14;  // rad / sec
    float rotation = 0;
    rotation += remote.getChannel(FlySky::Channel::RIGHT_HORIZONTAL);
    return rotation * maxRotationSpeed;
}

}  // namespace control

}  // namespace src

#endif  // FLY_SKY