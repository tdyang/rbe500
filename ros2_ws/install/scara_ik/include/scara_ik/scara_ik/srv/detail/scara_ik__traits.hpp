// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scara_ik:srv/ScaraIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scara_ik/srv/scara_ik.hpp"


#ifndef SCARA_IK__SRV__DETAIL__SCARA_IK__TRAITS_HPP_
#define SCARA_IK__SRV__DETAIL__SCARA_IK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scara_ik/srv/detail/scara_ik__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace scara_ik
{

namespace srv
{

inline void to_flow_style_yaml(
  const ScaraIK_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ScaraIK_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScaraIK_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace scara_ik

namespace rosidl_generator_traits
{

[[deprecated("use scara_ik::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const scara_ik::srv::ScaraIK_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  scara_ik::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scara_ik::srv::to_yaml() instead")]]
inline std::string to_yaml(const scara_ik::srv::ScaraIK_Request & msg)
{
  return scara_ik::srv::to_yaml(msg);
}

template<>
inline const char * data_type<scara_ik::srv::ScaraIK_Request>()
{
  return "scara_ik::srv::ScaraIK_Request";
}

template<>
inline const char * name<scara_ik::srv::ScaraIK_Request>()
{
  return "scara_ik/srv/ScaraIK_Request";
}

template<>
struct has_fixed_size<scara_ik::srv::ScaraIK_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<scara_ik::srv::ScaraIK_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<scara_ik::srv::ScaraIK_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace scara_ik
{

namespace srv
{

inline void to_flow_style_yaml(
  const ScaraIK_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: theta1
  {
    out << "theta1: ";
    rosidl_generator_traits::value_to_yaml(msg.theta1, out);
    out << ", ";
  }

  // member: theta2
  {
    out << "theta2: ";
    rosidl_generator_traits::value_to_yaml(msg.theta2, out);
    out << ", ";
  }

  // member: d3
  {
    out << "d3: ";
    rosidl_generator_traits::value_to_yaml(msg.d3, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ScaraIK_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: theta1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta1: ";
    rosidl_generator_traits::value_to_yaml(msg.theta1, out);
    out << "\n";
  }

  // member: theta2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta2: ";
    rosidl_generator_traits::value_to_yaml(msg.theta2, out);
    out << "\n";
  }

  // member: d3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d3: ";
    rosidl_generator_traits::value_to_yaml(msg.d3, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScaraIK_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace scara_ik

namespace rosidl_generator_traits
{

[[deprecated("use scara_ik::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const scara_ik::srv::ScaraIK_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  scara_ik::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scara_ik::srv::to_yaml() instead")]]
inline std::string to_yaml(const scara_ik::srv::ScaraIK_Response & msg)
{
  return scara_ik::srv::to_yaml(msg);
}

template<>
inline const char * data_type<scara_ik::srv::ScaraIK_Response>()
{
  return "scara_ik::srv::ScaraIK_Response";
}

template<>
inline const char * name<scara_ik::srv::ScaraIK_Response>()
{
  return "scara_ik/srv/ScaraIK_Response";
}

template<>
struct has_fixed_size<scara_ik::srv::ScaraIK_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<scara_ik::srv::ScaraIK_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<scara_ik::srv::ScaraIK_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace scara_ik
{

namespace srv
{

inline void to_flow_style_yaml(
  const ScaraIK_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ScaraIK_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScaraIK_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace scara_ik

namespace rosidl_generator_traits
{

[[deprecated("use scara_ik::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const scara_ik::srv::ScaraIK_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  scara_ik::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scara_ik::srv::to_yaml() instead")]]
inline std::string to_yaml(const scara_ik::srv::ScaraIK_Event & msg)
{
  return scara_ik::srv::to_yaml(msg);
}

template<>
inline const char * data_type<scara_ik::srv::ScaraIK_Event>()
{
  return "scara_ik::srv::ScaraIK_Event";
}

template<>
inline const char * name<scara_ik::srv::ScaraIK_Event>()
{
  return "scara_ik/srv/ScaraIK_Event";
}

template<>
struct has_fixed_size<scara_ik::srv::ScaraIK_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<scara_ik::srv::ScaraIK_Event>
  : std::integral_constant<bool, has_bounded_size<scara_ik::srv::ScaraIK_Request>::value && has_bounded_size<scara_ik::srv::ScaraIK_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<scara_ik::srv::ScaraIK_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<scara_ik::srv::ScaraIK>()
{
  return "scara_ik::srv::ScaraIK";
}

template<>
inline const char * name<scara_ik::srv::ScaraIK>()
{
  return "scara_ik/srv/ScaraIK";
}

template<>
struct has_fixed_size<scara_ik::srv::ScaraIK>
  : std::integral_constant<
    bool,
    has_fixed_size<scara_ik::srv::ScaraIK_Request>::value &&
    has_fixed_size<scara_ik::srv::ScaraIK_Response>::value
  >
{
};

template<>
struct has_bounded_size<scara_ik::srv::ScaraIK>
  : std::integral_constant<
    bool,
    has_bounded_size<scara_ik::srv::ScaraIK_Request>::value &&
    has_bounded_size<scara_ik::srv::ScaraIK_Response>::value
  >
{
};

template<>
struct is_service<scara_ik::srv::ScaraIK>
  : std::true_type
{
};

template<>
struct is_service_request<scara_ik::srv::ScaraIK_Request>
  : std::true_type
{
};

template<>
struct is_service_response<scara_ik::srv::ScaraIK_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SCARA_IK__SRV__DETAIL__SCARA_IK__TRAITS_HPP_
