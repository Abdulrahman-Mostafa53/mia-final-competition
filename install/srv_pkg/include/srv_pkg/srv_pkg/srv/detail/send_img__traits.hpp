// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from srv_pkg:srv/SendImg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "srv_pkg/srv/send_img.hpp"


#ifndef SRV_PKG__SRV__DETAIL__SEND_IMG__TRAITS_HPP_
#define SRV_PKG__SRV__DETAIL__SEND_IMG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "srv_pkg/srv/detail/send_img__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace srv_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SendImg_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: req
  {
    out << "req: ";
    rosidl_generator_traits::value_to_yaml(msg.req, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SendImg_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: req
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "req: ";
    rosidl_generator_traits::value_to_yaml(msg.req, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SendImg_Request & msg, bool use_flow_style = false)
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

}  // namespace srv_pkg

namespace rosidl_generator_traits
{

[[deprecated("use srv_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const srv_pkg::srv::SendImg_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  srv_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use srv_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const srv_pkg::srv::SendImg_Request & msg)
{
  return srv_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<srv_pkg::srv::SendImg_Request>()
{
  return "srv_pkg::srv::SendImg_Request";
}

template<>
inline const char * name<srv_pkg::srv::SendImg_Request>()
{
  return "srv_pkg/srv/SendImg_Request";
}

template<>
struct has_fixed_size<srv_pkg::srv::SendImg_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<srv_pkg::srv::SendImg_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<srv_pkg::srv::SendImg_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'img'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace srv_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SendImg_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: img
  {
    out << "img: ";
    to_flow_style_yaml(msg.img, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SendImg_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: img
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "img:\n";
    to_block_style_yaml(msg.img, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SendImg_Response & msg, bool use_flow_style = false)
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

}  // namespace srv_pkg

namespace rosidl_generator_traits
{

[[deprecated("use srv_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const srv_pkg::srv::SendImg_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  srv_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use srv_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const srv_pkg::srv::SendImg_Response & msg)
{
  return srv_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<srv_pkg::srv::SendImg_Response>()
{
  return "srv_pkg::srv::SendImg_Response";
}

template<>
inline const char * name<srv_pkg::srv::SendImg_Response>()
{
  return "srv_pkg/srv/SendImg_Response";
}

template<>
struct has_fixed_size<srv_pkg::srv::SendImg_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<srv_pkg::srv::SendImg_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<srv_pkg::srv::SendImg_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace srv_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SendImg_Event & msg,
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
  const SendImg_Event & msg,
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

inline std::string to_yaml(const SendImg_Event & msg, bool use_flow_style = false)
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

}  // namespace srv_pkg

namespace rosidl_generator_traits
{

[[deprecated("use srv_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const srv_pkg::srv::SendImg_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  srv_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use srv_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const srv_pkg::srv::SendImg_Event & msg)
{
  return srv_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<srv_pkg::srv::SendImg_Event>()
{
  return "srv_pkg::srv::SendImg_Event";
}

template<>
inline const char * name<srv_pkg::srv::SendImg_Event>()
{
  return "srv_pkg/srv/SendImg_Event";
}

template<>
struct has_fixed_size<srv_pkg::srv::SendImg_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<srv_pkg::srv::SendImg_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<srv_pkg::srv::SendImg_Request>::value && has_bounded_size<srv_pkg::srv::SendImg_Response>::value> {};

template<>
struct is_message<srv_pkg::srv::SendImg_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<srv_pkg::srv::SendImg>()
{
  return "srv_pkg::srv::SendImg";
}

template<>
inline const char * name<srv_pkg::srv::SendImg>()
{
  return "srv_pkg/srv/SendImg";
}

template<>
struct has_fixed_size<srv_pkg::srv::SendImg>
  : std::integral_constant<
    bool,
    has_fixed_size<srv_pkg::srv::SendImg_Request>::value &&
    has_fixed_size<srv_pkg::srv::SendImg_Response>::value
  >
{
};

template<>
struct has_bounded_size<srv_pkg::srv::SendImg>
  : std::integral_constant<
    bool,
    has_bounded_size<srv_pkg::srv::SendImg_Request>::value &&
    has_bounded_size<srv_pkg::srv::SendImg_Response>::value
  >
{
};

template<>
struct is_service<srv_pkg::srv::SendImg>
  : std::true_type
{
};

template<>
struct is_service_request<srv_pkg::srv::SendImg_Request>
  : std::true_type
{
};

template<>
struct is_service_response<srv_pkg::srv::SendImg_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SRV_PKG__SRV__DETAIL__SEND_IMG__TRAITS_HPP_
