#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "srv_pkg__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__srv_pkg__srv__SendImg_Request() -> *const std::ffi::c_void;
}

#[link(name = "srv_pkg__rosidl_generator_c")]
extern "C" {
    fn srv_pkg__srv__SendImg_Request__init(msg: *mut SendImg_Request) -> bool;
    fn srv_pkg__srv__SendImg_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SendImg_Request>, size: usize) -> bool;
    fn srv_pkg__srv__SendImg_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SendImg_Request>);
    fn srv_pkg__srv__SendImg_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SendImg_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SendImg_Request>) -> bool;
}

// Corresponds to srv_pkg__srv__SendImg_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SendImg_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub req: bool,

}



impl Default for SendImg_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !srv_pkg__srv__SendImg_Request__init(&mut msg as *mut _) {
        panic!("Call to srv_pkg__srv__SendImg_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SendImg_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { srv_pkg__srv__SendImg_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { srv_pkg__srv__SendImg_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { srv_pkg__srv__SendImg_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SendImg_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SendImg_Request where Self: Sized {
  const TYPE_NAME: &'static str = "srv_pkg/srv/SendImg_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__srv_pkg__srv__SendImg_Request() }
  }
}


#[link(name = "srv_pkg__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__srv_pkg__srv__SendImg_Response() -> *const std::ffi::c_void;
}

#[link(name = "srv_pkg__rosidl_generator_c")]
extern "C" {
    fn srv_pkg__srv__SendImg_Response__init(msg: *mut SendImg_Response) -> bool;
    fn srv_pkg__srv__SendImg_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SendImg_Response>, size: usize) -> bool;
    fn srv_pkg__srv__SendImg_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SendImg_Response>);
    fn srv_pkg__srv__SendImg_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SendImg_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SendImg_Response>) -> bool;
}

// Corresponds to srv_pkg__srv__SendImg_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SendImg_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub img: sensor_msgs::msg::rmw::Image,

}



impl Default for SendImg_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !srv_pkg__srv__SendImg_Response__init(&mut msg as *mut _) {
        panic!("Call to srv_pkg__srv__SendImg_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SendImg_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { srv_pkg__srv__SendImg_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { srv_pkg__srv__SendImg_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { srv_pkg__srv__SendImg_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SendImg_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SendImg_Response where Self: Sized {
  const TYPE_NAME: &'static str = "srv_pkg/srv/SendImg_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__srv_pkg__srv__SendImg_Response() }
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


