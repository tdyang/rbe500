#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to scara_ik__srv__ScaraIK_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ScaraIK_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ScaraIK_Request {
  type RmwMsg = super::srv::rmw::ScaraIK_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


// Corresponds to scara_ik__srv__ScaraIK_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub message: std::string::String,

}



impl Default for ScaraIK_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ScaraIK_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ScaraIK_Response {
  type RmwMsg = super::srv::rmw::ScaraIK_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        theta1: msg.theta1,
        theta2: msg.theta2,
        d3: msg.d3,
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      theta1: msg.theta1,
      theta2: msg.theta2,
      d3: msg.d3,
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      theta1: msg.theta1,
      theta2: msg.theta2,
      d3: msg.d3,
      success: msg.success,
      message: msg.message.to_string(),
    }
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


