// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scara_ik:srv/ScaraIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "scara_ik/srv/scara_ik.h"


#ifndef SCARA_IK__SRV__DETAIL__SCARA_IK__STRUCT_H_
#define SCARA_IK__SRV__DETAIL__SCARA_IK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ScaraIK in the package scara_ik.
typedef struct scara_ik__srv__ScaraIK_Request
{
  double x;
  double y;
  double z;
} scara_ik__srv__ScaraIK_Request;

// Struct for a sequence of scara_ik__srv__ScaraIK_Request.
typedef struct scara_ik__srv__ScaraIK_Request__Sequence
{
  scara_ik__srv__ScaraIK_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scara_ik__srv__ScaraIK_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ScaraIK in the package scara_ik.
typedef struct scara_ik__srv__ScaraIK_Response
{
  double theta1;
  double theta2;
  double d3;
  bool success;
  rosidl_runtime_c__String message;
} scara_ik__srv__ScaraIK_Response;

// Struct for a sequence of scara_ik__srv__ScaraIK_Response.
typedef struct scara_ik__srv__ScaraIK_Response__Sequence
{
  scara_ik__srv__ScaraIK_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scara_ik__srv__ScaraIK_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  scara_ik__srv__ScaraIK_Event__request__MAX_SIZE = 1
};
// response
enum
{
  scara_ik__srv__ScaraIK_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ScaraIK in the package scara_ik.
typedef struct scara_ik__srv__ScaraIK_Event
{
  service_msgs__msg__ServiceEventInfo info;
  scara_ik__srv__ScaraIK_Request__Sequence request;
  scara_ik__srv__ScaraIK_Response__Sequence response;
} scara_ik__srv__ScaraIK_Event;

// Struct for a sequence of scara_ik__srv__ScaraIK_Event.
typedef struct scara_ik__srv__ScaraIK_Event__Sequence
{
  scara_ik__srv__ScaraIK_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scara_ik__srv__ScaraIK_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCARA_IK__SRV__DETAIL__SCARA_IK__STRUCT_H_
