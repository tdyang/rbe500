// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scara_ik:srv/ScaraIK.idl
// generated code does not contain a copyright notice
#include "scara_ik/srv/detail/scara_ik__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
scara_ik__srv__ScaraIK_Request__init(scara_ik__srv__ScaraIK_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
scara_ik__srv__ScaraIK_Request__fini(scara_ik__srv__ScaraIK_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

bool
scara_ik__srv__ScaraIK_Request__are_equal(const scara_ik__srv__ScaraIK_Request * lhs, const scara_ik__srv__ScaraIK_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
scara_ik__srv__ScaraIK_Request__copy(
  const scara_ik__srv__ScaraIK_Request * input,
  scara_ik__srv__ScaraIK_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

scara_ik__srv__ScaraIK_Request *
scara_ik__srv__ScaraIK_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Request * msg = (scara_ik__srv__ScaraIK_Request *)allocator.allocate(sizeof(scara_ik__srv__ScaraIK_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scara_ik__srv__ScaraIK_Request));
  bool success = scara_ik__srv__ScaraIK_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scara_ik__srv__ScaraIK_Request__destroy(scara_ik__srv__ScaraIK_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scara_ik__srv__ScaraIK_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scara_ik__srv__ScaraIK_Request__Sequence__init(scara_ik__srv__ScaraIK_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Request * data = NULL;

  if (size) {
    data = (scara_ik__srv__ScaraIK_Request *)allocator.zero_allocate(size, sizeof(scara_ik__srv__ScaraIK_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scara_ik__srv__ScaraIK_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scara_ik__srv__ScaraIK_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
scara_ik__srv__ScaraIK_Request__Sequence__fini(scara_ik__srv__ScaraIK_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      scara_ik__srv__ScaraIK_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

scara_ik__srv__ScaraIK_Request__Sequence *
scara_ik__srv__ScaraIK_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Request__Sequence * array = (scara_ik__srv__ScaraIK_Request__Sequence *)allocator.allocate(sizeof(scara_ik__srv__ScaraIK_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scara_ik__srv__ScaraIK_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scara_ik__srv__ScaraIK_Request__Sequence__destroy(scara_ik__srv__ScaraIK_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scara_ik__srv__ScaraIK_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scara_ik__srv__ScaraIK_Request__Sequence__are_equal(const scara_ik__srv__ScaraIK_Request__Sequence * lhs, const scara_ik__srv__ScaraIK_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scara_ik__srv__ScaraIK_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scara_ik__srv__ScaraIK_Request__Sequence__copy(
  const scara_ik__srv__ScaraIK_Request__Sequence * input,
  scara_ik__srv__ScaraIK_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scara_ik__srv__ScaraIK_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scara_ik__srv__ScaraIK_Request * data =
      (scara_ik__srv__ScaraIK_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scara_ik__srv__ScaraIK_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scara_ik__srv__ScaraIK_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scara_ik__srv__ScaraIK_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
scara_ik__srv__ScaraIK_Response__init(scara_ik__srv__ScaraIK_Response * msg)
{
  if (!msg) {
    return false;
  }
  // theta1
  // theta2
  // d3
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    scara_ik__srv__ScaraIK_Response__fini(msg);
    return false;
  }
  return true;
}

void
scara_ik__srv__ScaraIK_Response__fini(scara_ik__srv__ScaraIK_Response * msg)
{
  if (!msg) {
    return;
  }
  // theta1
  // theta2
  // d3
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
scara_ik__srv__ScaraIK_Response__are_equal(const scara_ik__srv__ScaraIK_Response * lhs, const scara_ik__srv__ScaraIK_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // theta1
  if (lhs->theta1 != rhs->theta1) {
    return false;
  }
  // theta2
  if (lhs->theta2 != rhs->theta2) {
    return false;
  }
  // d3
  if (lhs->d3 != rhs->d3) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
scara_ik__srv__ScaraIK_Response__copy(
  const scara_ik__srv__ScaraIK_Response * input,
  scara_ik__srv__ScaraIK_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // theta1
  output->theta1 = input->theta1;
  // theta2
  output->theta2 = input->theta2;
  // d3
  output->d3 = input->d3;
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

scara_ik__srv__ScaraIK_Response *
scara_ik__srv__ScaraIK_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Response * msg = (scara_ik__srv__ScaraIK_Response *)allocator.allocate(sizeof(scara_ik__srv__ScaraIK_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scara_ik__srv__ScaraIK_Response));
  bool success = scara_ik__srv__ScaraIK_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scara_ik__srv__ScaraIK_Response__destroy(scara_ik__srv__ScaraIK_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scara_ik__srv__ScaraIK_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scara_ik__srv__ScaraIK_Response__Sequence__init(scara_ik__srv__ScaraIK_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Response * data = NULL;

  if (size) {
    data = (scara_ik__srv__ScaraIK_Response *)allocator.zero_allocate(size, sizeof(scara_ik__srv__ScaraIK_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scara_ik__srv__ScaraIK_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scara_ik__srv__ScaraIK_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
scara_ik__srv__ScaraIK_Response__Sequence__fini(scara_ik__srv__ScaraIK_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      scara_ik__srv__ScaraIK_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

scara_ik__srv__ScaraIK_Response__Sequence *
scara_ik__srv__ScaraIK_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Response__Sequence * array = (scara_ik__srv__ScaraIK_Response__Sequence *)allocator.allocate(sizeof(scara_ik__srv__ScaraIK_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scara_ik__srv__ScaraIK_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scara_ik__srv__ScaraIK_Response__Sequence__destroy(scara_ik__srv__ScaraIK_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scara_ik__srv__ScaraIK_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scara_ik__srv__ScaraIK_Response__Sequence__are_equal(const scara_ik__srv__ScaraIK_Response__Sequence * lhs, const scara_ik__srv__ScaraIK_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scara_ik__srv__ScaraIK_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scara_ik__srv__ScaraIK_Response__Sequence__copy(
  const scara_ik__srv__ScaraIK_Response__Sequence * input,
  scara_ik__srv__ScaraIK_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scara_ik__srv__ScaraIK_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scara_ik__srv__ScaraIK_Response * data =
      (scara_ik__srv__ScaraIK_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scara_ik__srv__ScaraIK_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scara_ik__srv__ScaraIK_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scara_ik__srv__ScaraIK_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "scara_ik/srv/detail/scara_ik__functions.h"

bool
scara_ik__srv__ScaraIK_Event__init(scara_ik__srv__ScaraIK_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    scara_ik__srv__ScaraIK_Event__fini(msg);
    return false;
  }
  // request
  if (!scara_ik__srv__ScaraIK_Request__Sequence__init(&msg->request, 0)) {
    scara_ik__srv__ScaraIK_Event__fini(msg);
    return false;
  }
  // response
  if (!scara_ik__srv__ScaraIK_Response__Sequence__init(&msg->response, 0)) {
    scara_ik__srv__ScaraIK_Event__fini(msg);
    return false;
  }
  return true;
}

void
scara_ik__srv__ScaraIK_Event__fini(scara_ik__srv__ScaraIK_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  scara_ik__srv__ScaraIK_Request__Sequence__fini(&msg->request);
  // response
  scara_ik__srv__ScaraIK_Response__Sequence__fini(&msg->response);
}

bool
scara_ik__srv__ScaraIK_Event__are_equal(const scara_ik__srv__ScaraIK_Event * lhs, const scara_ik__srv__ScaraIK_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!scara_ik__srv__ScaraIK_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!scara_ik__srv__ScaraIK_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
scara_ik__srv__ScaraIK_Event__copy(
  const scara_ik__srv__ScaraIK_Event * input,
  scara_ik__srv__ScaraIK_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!scara_ik__srv__ScaraIK_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!scara_ik__srv__ScaraIK_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

scara_ik__srv__ScaraIK_Event *
scara_ik__srv__ScaraIK_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Event * msg = (scara_ik__srv__ScaraIK_Event *)allocator.allocate(sizeof(scara_ik__srv__ScaraIK_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scara_ik__srv__ScaraIK_Event));
  bool success = scara_ik__srv__ScaraIK_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scara_ik__srv__ScaraIK_Event__destroy(scara_ik__srv__ScaraIK_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scara_ik__srv__ScaraIK_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scara_ik__srv__ScaraIK_Event__Sequence__init(scara_ik__srv__ScaraIK_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Event * data = NULL;

  if (size) {
    data = (scara_ik__srv__ScaraIK_Event *)allocator.zero_allocate(size, sizeof(scara_ik__srv__ScaraIK_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scara_ik__srv__ScaraIK_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scara_ik__srv__ScaraIK_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
scara_ik__srv__ScaraIK_Event__Sequence__fini(scara_ik__srv__ScaraIK_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      scara_ik__srv__ScaraIK_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

scara_ik__srv__ScaraIK_Event__Sequence *
scara_ik__srv__ScaraIK_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scara_ik__srv__ScaraIK_Event__Sequence * array = (scara_ik__srv__ScaraIK_Event__Sequence *)allocator.allocate(sizeof(scara_ik__srv__ScaraIK_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scara_ik__srv__ScaraIK_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scara_ik__srv__ScaraIK_Event__Sequence__destroy(scara_ik__srv__ScaraIK_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scara_ik__srv__ScaraIK_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scara_ik__srv__ScaraIK_Event__Sequence__are_equal(const scara_ik__srv__ScaraIK_Event__Sequence * lhs, const scara_ik__srv__ScaraIK_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scara_ik__srv__ScaraIK_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scara_ik__srv__ScaraIK_Event__Sequence__copy(
  const scara_ik__srv__ScaraIK_Event__Sequence * input,
  scara_ik__srv__ScaraIK_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scara_ik__srv__ScaraIK_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scara_ik__srv__ScaraIK_Event * data =
      (scara_ik__srv__ScaraIK_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scara_ik__srv__ScaraIK_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scara_ik__srv__ScaraIK_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scara_ik__srv__ScaraIK_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
