// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from srv_pkg:srv/SendImg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "srv_pkg/srv/send_img.hpp"


#ifndef SRV_PKG__SRV__DETAIL__SEND_IMG__BUILDER_HPP_
#define SRV_PKG__SRV__DETAIL__SEND_IMG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "srv_pkg/srv/detail/send_img__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace srv_pkg
{

namespace srv
{

namespace builder
{

class Init_SendImg_Request_req
{
public:
  Init_SendImg_Request_req()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::srv_pkg::srv::SendImg_Request req(::srv_pkg::srv::SendImg_Request::_req_type arg)
  {
    msg_.req = std::move(arg);
    return std::move(msg_);
  }

private:
  ::srv_pkg::srv::SendImg_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::srv_pkg::srv::SendImg_Request>()
{
  return srv_pkg::srv::builder::Init_SendImg_Request_req();
}

}  // namespace srv_pkg


namespace srv_pkg
{

namespace srv
{

namespace builder
{

class Init_SendImg_Response_img
{
public:
  Init_SendImg_Response_img()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::srv_pkg::srv::SendImg_Response img(::srv_pkg::srv::SendImg_Response::_img_type arg)
  {
    msg_.img = std::move(arg);
    return std::move(msg_);
  }

private:
  ::srv_pkg::srv::SendImg_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::srv_pkg::srv::SendImg_Response>()
{
  return srv_pkg::srv::builder::Init_SendImg_Response_img();
}

}  // namespace srv_pkg


namespace srv_pkg
{

namespace srv
{

namespace builder
{

class Init_SendImg_Event_response
{
public:
  explicit Init_SendImg_Event_response(::srv_pkg::srv::SendImg_Event & msg)
  : msg_(msg)
  {}
  ::srv_pkg::srv::SendImg_Event response(::srv_pkg::srv::SendImg_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::srv_pkg::srv::SendImg_Event msg_;
};

class Init_SendImg_Event_request
{
public:
  explicit Init_SendImg_Event_request(::srv_pkg::srv::SendImg_Event & msg)
  : msg_(msg)
  {}
  Init_SendImg_Event_response request(::srv_pkg::srv::SendImg_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SendImg_Event_response(msg_);
  }

private:
  ::srv_pkg::srv::SendImg_Event msg_;
};

class Init_SendImg_Event_info
{
public:
  Init_SendImg_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendImg_Event_request info(::srv_pkg::srv::SendImg_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SendImg_Event_request(msg_);
  }

private:
  ::srv_pkg::srv::SendImg_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::srv_pkg::srv::SendImg_Event>()
{
  return srv_pkg::srv::builder::Init_SendImg_Event_info();
}

}  // namespace srv_pkg

#endif  // SRV_PKG__SRV__DETAIL__SEND_IMG__BUILDER_HPP_
