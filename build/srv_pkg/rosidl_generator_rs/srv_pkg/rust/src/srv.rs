#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to srv_pkg__srv__SendImg_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SendImg_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: bool,

}



impl Default for SendImg_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SendImg_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SendImg_Request {
  type RmwMsg = super::srv::rmw::SendImg_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        req: msg.req,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      req: msg.req,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      req: msg.req,
    }
  }
}


// Corresponds to srv_pkg__srv__SendImg_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SendImg_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub img: sensor_msgs::msg::Image,

}



impl Default for SendImg_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SendImg_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SendImg_Response {
  type RmwMsg = super::srv::rmw::SendImg_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        img: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(msg.img)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        img: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(&msg.img)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      img: sensor_msgs::msg::Image::from_rmw_message(msg.img),
    }
  }
}






#[link(name = "srv_pkg__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__srv_pkg__srv__SendImg() -> *const std::ffi::c_void;
}

// Corresponds to srv_pkg__srv__SendImg
#[allow(missing_docs, non_camel_case_types)]
pub struct SendImg;

impl rosidl_runtime_rs::Service for SendImg {
    type Request = SendImg_Request;
    type Response = SendImg_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__srv_pkg__srv__SendImg() }
    }
}


