/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.14.v202310241605.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_Park_Distance_Control_Sensor_STUB_DEFAULT_HPP_
#define V0_COMMONAPI_Park_Distance_Control_Sensor_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v0/commonapi/ParkDistanceControlSensorStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v0 {
namespace commonapi {

/**
 * Provides a default implementation for ParkDistanceControlSensorStubRemoteEvent and
 * ParkDistanceControlSensorStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT ParkDistanceControlSensorStubDefault
    : public virtual ParkDistanceControlSensorStub {
public:
    COMMONAPI_EXPORT ParkDistanceControlSensorStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(ParkDistanceControlSensor::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT ParkDistanceControlSensorStubRemoteEvent* initStubAdapter(const std::shared_ptr< ParkDistanceControlSensorStubAdapter> &_adapter) {
        CommonAPI::Stub<ParkDistanceControlSensorStubAdapter, ParkDistanceControlSensorStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual const ::v0::commonapi::ParkDistanceControlSensor::SonarArrayStruct &getDistancesAttribute() {
        return distancesAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const ::v0::commonapi::ParkDistanceControlSensor::SonarArrayStruct &getDistancesAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getDistancesAttribute();
    }
    COMMONAPI_EXPORT virtual void setDistancesAttribute(::v0::commonapi::ParkDistanceControlSensor::SonarArrayStruct _value) {
        const bool valueChanged = trySetDistancesAttribute(std::move(_value));
        if (valueChanged) {
            fireDistancesAttributeChanged(distancesAttributeValue_);
        }
    }


protected:
    COMMONAPI_EXPORT virtual bool trySetDistancesAttribute(::v0::commonapi::ParkDistanceControlSensor::SonarArrayStruct _value) {
        if (!validateDistancesAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<ParkDistanceControlSensorStubAdapter> stubAdapter = CommonAPI::Stub<ParkDistanceControlSensorStubAdapter, ParkDistanceControlSensorStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockDistancesAttribute(true);
            valueChanged = (distancesAttributeValue_ != _value);
            distancesAttributeValue_ = std::move(_value);
            stubAdapter->lockDistancesAttribute(false);
        } else {
            valueChanged = (distancesAttributeValue_ != _value);
            distancesAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateDistancesAttributeRequestedValue(const ::v0::commonapi::ParkDistanceControlSensor::SonarArrayStruct &_value) {
        (void)_value;
        return true;
    }
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual ParkDistanceControlSensorStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(ParkDistanceControlSensorStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }


    private:
        ParkDistanceControlSensorStubDefault *defaultStub_;
    };
protected:
    ParkDistanceControlSensorStubDefault::RemoteEventHandler remoteEventHandler_;

private:

    ::v0::commonapi::ParkDistanceControlSensor::SonarArrayStruct distancesAttributeValue_ {};

    CommonAPI::Version interfaceVersion_;
};

} // namespace commonapi
} // namespace v0


// Compatibility
namespace v0_1 = v0;

#endif // V0_COMMONAPI_Park_Distance_Control_Sensor_STUB_DEFAULT
