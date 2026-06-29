// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from scara_ik:srv/ScaraIK.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "scara_ik/srv/detail/scara_ik__struct.h"
#include "scara_ik/srv/detail/scara_ik__type_support.h"
#include "scara_ik/srv/detail/scara_ik__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace scara_ik
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ScaraIK_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ScaraIK_Request_type_support_ids_t;

static const _ScaraIK_Request_type_support_ids_t _ScaraIK_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ScaraIK_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ScaraIK_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ScaraIK_Request_type_support_symbol_names_t _ScaraIK_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scara_ik, srv, ScaraIK_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scara_ik, srv, ScaraIK_Request)),
  }
};

typedef struct _ScaraIK_Request_type_support_data_t
{
  void * data[2];
} _ScaraIK_Request_type_support_data_t;

static _ScaraIK_Request_type_support_data_t _ScaraIK_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ScaraIK_Request_message_typesupport_map = {
  2,
  "scara_ik",
  &_ScaraIK_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ScaraIK_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ScaraIK_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ScaraIK_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ScaraIK_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &scara_ik__srv__ScaraIK_Request__get_type_hash,
  &scara_ik__srv__ScaraIK_Request__get_type_description,
  &scara_ik__srv__ScaraIK_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace scara_ik

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, scara_ik, srv, ScaraIK_Request)() {
  return &::scara_ik::srv::rosidl_typesupport_c::ScaraIK_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "scara_ik/srv/detail/scara_ik__struct.h"
// already included above
// #include "scara_ik/srv/detail/scara_ik__type_support.h"
// already included above
// #include "scara_ik/srv/detail/scara_ik__functions.h"
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

namespace scara_ik
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ScaraIK_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ScaraIK_Response_type_support_ids_t;

static const _ScaraIK_Response_type_support_ids_t _ScaraIK_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ScaraIK_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ScaraIK_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ScaraIK_Response_type_support_symbol_names_t _ScaraIK_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scara_ik, srv, ScaraIK_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scara_ik, srv, ScaraIK_Response)),
  }
};

typedef struct _ScaraIK_Response_type_support_data_t
{
  void * data[2];
} _ScaraIK_Response_type_support_data_t;

static _ScaraIK_Response_type_support_data_t _ScaraIK_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ScaraIK_Response_message_typesupport_map = {
  2,
  "scara_ik",
  &_ScaraIK_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ScaraIK_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ScaraIK_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ScaraIK_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ScaraIK_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &scara_ik__srv__ScaraIK_Response__get_type_hash,
  &scara_ik__srv__ScaraIK_Response__get_type_description,
  &scara_ik__srv__ScaraIK_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace scara_ik

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, scara_ik, srv, ScaraIK_Response)() {
  return &::scara_ik::srv::rosidl_typesupport_c::ScaraIK_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "scara_ik/srv/detail/scara_ik__struct.h"
// already included above
// #include "scara_ik/srv/detail/scara_ik__type_support.h"
// already included above
// #include "scara_ik/srv/detail/scara_ik__functions.h"
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

namespace scara_ik
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ScaraIK_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ScaraIK_Event_type_support_ids_t;

static const _ScaraIK_Event_type_support_ids_t _ScaraIK_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ScaraIK_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ScaraIK_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ScaraIK_Event_type_support_symbol_names_t _ScaraIK_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scara_ik, srv, ScaraIK_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scara_ik, srv, ScaraIK_Event)),
  }
};

typedef struct _ScaraIK_Event_type_support_data_t
{
  void * data[2];
} _ScaraIK_Event_type_support_data_t;

static _ScaraIK_Event_type_support_data_t _ScaraIK_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ScaraIK_Event_message_typesupport_map = {
  2,
  "scara_ik",
  &_ScaraIK_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ScaraIK_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ScaraIK_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ScaraIK_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ScaraIK_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &scara_ik__srv__ScaraIK_Event__get_type_hash,
  &scara_ik__srv__ScaraIK_Event__get_type_description,
  &scara_ik__srv__ScaraIK_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace scara_ik

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, scara_ik, srv, ScaraIK_Event)() {
  return &::scara_ik::srv::rosidl_typesupport_c::ScaraIK_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "scara_ik/srv/detail/scara_ik__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace scara_ik
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _ScaraIK_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ScaraIK_type_support_ids_t;

static const _ScaraIK_type_support_ids_t _ScaraIK_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ScaraIK_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ScaraIK_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ScaraIK_type_support_symbol_names_t _ScaraIK_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scara_ik, srv, ScaraIK)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scara_ik, srv, ScaraIK)),
  }
};

typedef struct _ScaraIK_type_support_data_t
{
  void * data[2];
} _ScaraIK_type_support_data_t;

static _ScaraIK_type_support_data_t _ScaraIK_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ScaraIK_service_typesupport_map = {
  2,
  "scara_ik",
  &_ScaraIK_service_typesupport_ids.typesupport_identifier[0],
  &_ScaraIK_service_typesupport_symbol_names.symbol_name[0],
  &_ScaraIK_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ScaraIK_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ScaraIK_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &ScaraIK_Request_message_type_support_handle,
  &ScaraIK_Response_message_type_support_handle,
  &ScaraIK_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    scara_ik,
    srv,
    ScaraIK
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    scara_ik,
    srv,
    ScaraIK
  ),
  &scara_ik__srv__ScaraIK__get_type_hash,
  &scara_ik__srv__ScaraIK__get_type_description,
  &scara_ik__srv__ScaraIK__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace scara_ik

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, scara_ik, srv, ScaraIK)() {
  return &::scara_ik::srv::rosidl_typesupport_c::ScaraIK_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
