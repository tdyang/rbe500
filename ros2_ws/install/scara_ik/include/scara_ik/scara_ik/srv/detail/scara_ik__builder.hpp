// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scara_ik:srv/ScaraIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scara_ik/srv/scara_ik.hpp"


#ifndef SCARA_IK__SRV__DETAIL__SCARA_IK__BUILDER_HPP_
#define SCARA_IK__SRV__DETAIL__SCARA_IK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scara_ik/srv/detail/scara_ik__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scara_ik
{

namespace srv
{

namespace builder
{

class Init_ScaraIK_Request_z
{
public:
  explicit Init_ScaraIK_Request_z(::scara_ik::srv::ScaraIK_Request & msg)
  : msg_(msg)
  {}
  ::scara_ik::srv::ScaraIK_Request z(::scara_ik::srv::ScaraIK_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Request msg_;
};

class Init_ScaraIK_Request_y
{
public:
  explicit Init_ScaraIK_Request_y(::scara_ik::srv::ScaraIK_Request & msg)
  : msg_(msg)
  {}
  Init_ScaraIK_Request_z y(::scara_ik::srv::ScaraIK_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ScaraIK_Request_z(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Request msg_;
};

class Init_ScaraIK_Request_x
{
public:
  Init_ScaraIK_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScaraIK_Request_y x(::scara_ik::srv::ScaraIK_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ScaraIK_Request_y(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::scara_ik::srv::ScaraIK_Request>()
{
  return scara_ik::srv::builder::Init_ScaraIK_Request_x();
}

}  // namespace scara_ik


namespace scara_ik
{

namespace srv
{

namespace builder
{

class Init_ScaraIK_Response_message
{
public:
  explicit Init_ScaraIK_Response_message(::scara_ik::srv::ScaraIK_Response & msg)
  : msg_(msg)
  {}
  ::scara_ik::srv::ScaraIK_Response message(::scara_ik::srv::ScaraIK_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Response msg_;
};

class Init_ScaraIK_Response_success
{
public:
  explicit Init_ScaraIK_Response_success(::scara_ik::srv::ScaraIK_Response & msg)
  : msg_(msg)
  {}
  Init_ScaraIK_Response_message success(::scara_ik::srv::ScaraIK_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ScaraIK_Response_message(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Response msg_;
};

class Init_ScaraIK_Response_d3
{
public:
  explicit Init_ScaraIK_Response_d3(::scara_ik::srv::ScaraIK_Response & msg)
  : msg_(msg)
  {}
  Init_ScaraIK_Response_success d3(::scara_ik::srv::ScaraIK_Response::_d3_type arg)
  {
    msg_.d3 = std::move(arg);
    return Init_ScaraIK_Response_success(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Response msg_;
};

class Init_ScaraIK_Response_theta2
{
public:
  explicit Init_ScaraIK_Response_theta2(::scara_ik::srv::ScaraIK_Response & msg)
  : msg_(msg)
  {}
  Init_ScaraIK_Response_d3 theta2(::scara_ik::srv::ScaraIK_Response::_theta2_type arg)
  {
    msg_.theta2 = std::move(arg);
    return Init_ScaraIK_Response_d3(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Response msg_;
};

class Init_ScaraIK_Response_theta1
{
public:
  Init_ScaraIK_Response_theta1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScaraIK_Response_theta2 theta1(::scara_ik::srv::ScaraIK_Response::_theta1_type arg)
  {
    msg_.theta1 = std::move(arg);
    return Init_ScaraIK_Response_theta2(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::scara_ik::srv::ScaraIK_Response>()
{
  return scara_ik::srv::builder::Init_ScaraIK_Response_theta1();
}

}  // namespace scara_ik


namespace scara_ik
{

namespace srv
{

namespace builder
{

class Init_ScaraIK_Event_response
{
public:
  explicit Init_ScaraIK_Event_response(::scara_ik::srv::ScaraIK_Event & msg)
  : msg_(msg)
  {}
  ::scara_ik::srv::ScaraIK_Event response(::scara_ik::srv::ScaraIK_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Event msg_;
};

class Init_ScaraIK_Event_request
{
public:
  explicit Init_ScaraIK_Event_request(::scara_ik::srv::ScaraIK_Event & msg)
  : msg_(msg)
  {}
  Init_ScaraIK_Event_response request(::scara_ik::srv::ScaraIK_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ScaraIK_Event_response(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Event msg_;
};

class Init_ScaraIK_Event_info
{
public:
  Init_ScaraIK_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScaraIK_Event_request info(::scara_ik::srv::ScaraIK_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ScaraIK_Event_request(msg_);
  }

private:
  ::scara_ik::srv::ScaraIK_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::scara_ik::srv::ScaraIK_Event>()
{
  return scara_ik::srv::builder::Init_ScaraIK_Event_info();
}

}  // namespace scara_ik

#endif  // SCARA_IK__SRV__DETAIL__SCARA_IK__BUILDER_HPP_
