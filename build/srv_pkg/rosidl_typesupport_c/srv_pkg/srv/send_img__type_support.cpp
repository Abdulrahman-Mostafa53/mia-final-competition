// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from srv_pkg:srv/SendImg.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "srv_pkg/srv/detail/send_img__struct.h"
#include "srv_pkg/srv/detail/send_img__type_support.h"
#include "srv_pkg/srv/detail/send_img__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace srv_pkg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SendImg_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendImg_Request_type_support_ids_t;

static const _SendImg_Request_type_support_ids_t _SendImg_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SendImg_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendImg_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendImg_Request_type_support_symbol_names_t _SendImg_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, srv_pkg, srv, SendImg_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, srv_pkg, srv, SendImg_Request)),
  }
};

typedef struct _SendImg_Request_type_support_data_t
{
  void * data[2];
} _SendImg_Request_type_support_data_t;

static _SendImg_Request_type_support_data_t _SendImg_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendImg_Request_message_typesupport_map = {
  2,
  "srv_pkg",
  &_SendImg_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SendImg_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SendImg_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SendImg_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendImg_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &srv_pkg__srv__SendImg_Request__get_type_hash,
  &srv_pkg__srv__SendImg_Request__get_type_description,
  &srv_pkg__srv__SendImg_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace srv_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, srv_pkg, srv, SendImg_Request)() {
  return &::srv_pkg::srv::rosidl_typesupport_c::SendImg_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "srv_pkg/srv/detail/send_img__struct.h"
// already included above
// #include "srv_pkg/srv/detail/send_img__type_support.h"
// already included above
// #include "srv_pkg/srv/detail/send_img__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace srv_pkg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SendImg_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendImg_Response_type_support_ids_t;

static const _SendImg_Response_type_support_ids_t _SendImg_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SendImg_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendImg_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendImg_Response_type_support_symbol_names_t _SendImg_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, srv_pkg, srv, SendImg_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, srv_pkg, srv, SendImg_Response)),
  }
};

typedef struct _SendImg_Response_type_support_data_t
{
  void * data[2];
} _SendImg_Response_type_support_data_t;

static _SendImg_Response_type_support_data_t _SendImg_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendImg_Response_message_typesupport_map = {
  2,
  "srv_pkg",
  &_SendImg_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SendImg_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SendImg_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SendImg_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendImg_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &srv_pkg__srv__SendImg_Response__get_type_hash,
  &srv_pkg__srv__SendImg_Response__get_type_description,
  &srv_pkg__srv__SendImg_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace srv_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, srv_pkg, srv, SendImg_Response)() {
  return &::srv_pkg::srv::rosidl_typesupport_c::SendImg_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "srv_pkg/srv/detail/send_img__struct.h"
// already included above
// #include "srv_pkg/srv/detail/send_img__type_support.h"
// already included above
// #include "srv_pkg/srv/detail/send_img__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace srv_pkg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SendImg_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendImg_Event_type_support_ids_t;

static const _SendImg_Event_type_support_ids_t _SendImg_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SendImg_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendImg_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendImg_Event_type_support_symbol_names_t _SendImg_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, srv_pkg, srv, SendImg_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, srv_pkg, srv, SendImg_Event)),
  }
};

typedef struct _SendImg_Event_type_support_data_t
{
  void * data[2];
} _SendImg_Event_type_support_data_t;

static _SendImg_Event_type_support_data_t _SendImg_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendImg_Event_message_typesupport_map = {
  2,
  "srv_pkg",
  &_SendImg_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SendImg_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SendImg_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SendImg_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendImg_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &srv_pkg__srv__SendImg_Event__get_type_hash,
  &srv_pkg__srv__SendImg_Event__get_type_description,
  &srv_pkg__srv__SendImg_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace srv_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, srv_pkg, srv, SendImg_Event)() {
  return &::srv_pkg::srv::rosidl_typesupport_c::SendImg_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "srv_pkg/srv/detail/send_img__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace srv_pkg
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _SendImg_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SendImg_type_support_ids_t;

static const _SendImg_type_support_ids_t _SendImg_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SendImg_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SendImg_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SendImg_type_support_symbol_names_t _SendImg_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, srv_pkg, srv, SendImg)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, srv_pkg, srv, SendImg)),
  }
};

typedef struct _SendImg_type_support_data_t
{
  void * data[2];
} _SendImg_type_support_data_t;

static _SendImg_type_support_data_t _SendImg_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SendImg_service_typesupport_map = {
  2,
  "srv_pkg",
  &_SendImg_service_typesupport_ids.typesupport_identifier[0],
  &_SendImg_service_typesupport_symbol_names.symbol_name[0],
  &_SendImg_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SendImg_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SendImg_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &SendImg_Request_message_type_support_handle,
  &SendImg_Response_message_type_support_handle,
  &SendImg_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    srv_pkg,
    srv,
    SendImg
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    srv_pkg,
    srv,
    SendImg
  ),
  &srv_pkg__srv__SendImg__get_type_hash,
  &srv_pkg__srv__SendImg__get_type_description,
  &srv_pkg__srv__SendImg__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace srv_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, srv_pkg, srv, SendImg)() {
  return &::srv_pkg::srv::rosidl_typesupport_c::SendImg_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
