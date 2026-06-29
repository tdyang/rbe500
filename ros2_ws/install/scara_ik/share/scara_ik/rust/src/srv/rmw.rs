#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "scara_ik__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__scara_ik__srv__ScaraIK_Request() -> *const std::ffi::c_void;
}

#[link(name = "scara_ik__rosidl_generator_c")]
extern "C" {
    fn scara_ik__srv__ScaraIK_Request__init(msg: *mut ScaraIK_Request) -> bool;
    fn scara_ik__srv__ScaraIK_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ScaraIK_Request>, size: usize) -> bool;
    fn scara_ik__srv__ScaraIK_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ScaraIK_Request>);
    fn scara_ik__srv__ScaraIK_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ScaraIK_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ScaraIK_Request>) -> bool;
}

// Corresponds to scara_ik__srv__ScaraIK_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ScaraIK_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f64,

}



impl Default for ScaraIK_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !scara_ik__srv__ScaraIK_Request__init(&mut msg as *mut _) {
        panic!("Call to scara_ik__srv__ScaraIK_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ScaraIK_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { scara_ik__srv__ScaraIK_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { scara_ik__srv__ScaraIK_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { scara_ik__srv__ScaraIK_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ScaraIK_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ScaraIK_Request where Self: Sized {
  const TYPE_NAME: &'static str = "scara_ik/srv/ScaraIK_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__scara_ik__srv__ScaraIK_Request() }
  }
}


#[link(name = "scara_ik__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__scara_ik__srv__ScaraIK_Response() -> *const std::ffi::c_void;
}

#[link(name = "scara_ik__rosidl_generator_c")]
extern "C" {
    fn scara_ik__srv__ScaraIK_Response__init(msg: *mut ScaraIK_Response) -> bool;
    fn scara_ik__srv__ScaraIK_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ScaraIK_Response>, size: usize) -> bool;
    fn scara_ik__srv__ScaraIK_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ScaraIK_Response>);
    fn scara_ik__srv__ScaraIK_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ScaraIK_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ScaraIK_Response>) -> bool;
}

// Corresponds to scara_ik__srv__ScaraIK_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ScaraIK_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub theta1: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta2: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub d3: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for ScaraIK_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !scara_ik__srv__ScaraIK_Response__init(&mut msg as *mut _) {
        panic!("Call to scara_ik__srv__ScaraIK_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ScaraIK_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { scara_ik__srv__ScaraIK_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { scara_ik__srv__ScaraIK_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { scara_ik__srv__ScaraIK_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ScaraIK_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ScaraIK_Response where Self: Sized {
  const TYPE_NAME: &'static str = "scara_ik/srv/ScaraIK_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__scara_ik__srv__ScaraIK_Response() }
  }
}






#[link(name = "scara_ik__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__scara_ik__srv__ScaraIK() -> *const std::ffi::c_void;
}

// Corresponds to scara_ik__srv__ScaraIK
#[allow(missing_docs, non_camel_case_types)]
pub struct ScaraIK;

impl rosidl_runtime_rs::Service for ScaraIK {
    type Request = ScaraIK_Request;
    type Response = ScaraIK_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__scara_ik__srv__ScaraIK() }
    }
}


