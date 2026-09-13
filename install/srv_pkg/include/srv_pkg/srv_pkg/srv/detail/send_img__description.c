// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from srv_pkg:srv/SendImg.idl
// generated code does not contain a copyright notice

#include "srv_pkg/srv/detail/send_img__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_srv_pkg
const rosidl_type_hash_t *
srv_pkg__srv__SendImg__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4d, 0x9b, 0x43, 0x1d, 0x17, 0x0e, 0xfe, 0x82,
      0x02, 0xbc, 0x41, 0x25, 0xa3, 0xaa, 0x1f, 0xaa,
      0x1d, 0xce, 0x49, 0x76, 0xe9, 0xbd, 0x16, 0xcd,
      0x1c, 0xa0, 0x3e, 0xa5, 0xed, 0x97, 0xea, 0xec,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_srv_pkg
const rosidl_type_hash_t *
srv_pkg__srv__SendImg_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf1, 0x0c, 0x90, 0x00, 0x7e, 0xf2, 0x6b, 0x28,
      0xa3, 0xf9, 0x0b, 0x72, 0x74, 0x3f, 0x13, 0x89,
      0xa1, 0xa1, 0xe1, 0xf9, 0xce, 0x8e, 0xcd, 0xe5,
      0x41, 0x27, 0x4d, 0xb5, 0xcb, 0x70, 0xa0, 0x98,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_srv_pkg
const rosidl_type_hash_t *
srv_pkg__srv__SendImg_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x12, 0x21, 0x74, 0xbd, 0xfc, 0x01, 0x35, 0xc1,
      0xc5, 0x0d, 0x9a, 0x7b, 0x6a, 0x39, 0x6a, 0xfd,
      0xf5, 0x0c, 0xa7, 0x6d, 0xed, 0x2c, 0x2c, 0xf4,
      0x5a, 0x90, 0xdf, 0xff, 0xb6, 0xde, 0x45, 0x5c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_srv_pkg
const rosidl_type_hash_t *
srv_pkg__srv__SendImg_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0x54, 0xf6, 0xb7, 0x34, 0x93, 0x0a, 0xd2,
      0xc3, 0x47, 0x39, 0xc8, 0x74, 0xec, 0x5e, 0x23,
      0x50, 0xe1, 0xb6, 0x94, 0x9a, 0x76, 0x0e, 0xe9,
      0x6c, 0xa1, 0xcd, 0xd4, 0x2f, 0x15, 0x0f, 0xef,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "sensor_msgs/msg/detail/image__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__Image__EXPECTED_HASH = {1, {
    0xd3, 0x1d, 0x41, 0xa9, 0xa4, 0xc4, 0xbc, 0x8e,
    0xae, 0x9b, 0xe7, 0x57, 0xb0, 0xbe, 0xed, 0x30,
    0x65, 0x64, 0xf7, 0x52, 0x6c, 0x88, 0xea, 0x6a,
    0x45, 0x88, 0xfb, 0x95, 0x82, 0x52, 0x7d, 0x47,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char srv_pkg__srv__SendImg__TYPE_NAME[] = "srv_pkg/srv/SendImg";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char sensor_msgs__msg__Image__TYPE_NAME[] = "sensor_msgs/msg/Image";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char srv_pkg__srv__SendImg_Event__TYPE_NAME[] = "srv_pkg/srv/SendImg_Event";
static char srv_pkg__srv__SendImg_Request__TYPE_NAME[] = "srv_pkg/srv/SendImg_Request";
static char srv_pkg__srv__SendImg_Response__TYPE_NAME[] = "srv_pkg/srv/SendImg_Response";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char srv_pkg__srv__SendImg__FIELD_NAME__request_message[] = "request_message";
static char srv_pkg__srv__SendImg__FIELD_NAME__response_message[] = "response_message";
static char srv_pkg__srv__SendImg__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field srv_pkg__srv__SendImg__FIELDS[] = {
  {
    {srv_pkg__srv__SendImg__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {srv_pkg__srv__SendImg_Request__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {srv_pkg__srv__SendImg_Response__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {srv_pkg__srv__SendImg_Event__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription srv_pkg__srv__SendImg__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg_Event__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg_Request__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg_Response__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
srv_pkg__srv__SendImg__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {srv_pkg__srv__SendImg__TYPE_NAME, 19, 19},
      {srv_pkg__srv__SendImg__FIELDS, 3, 3},
    },
    {srv_pkg__srv__SendImg__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__Image__EXPECTED_HASH, sensor_msgs__msg__Image__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = sensor_msgs__msg__Image__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = srv_pkg__srv__SendImg_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = srv_pkg__srv__SendImg_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = srv_pkg__srv__SendImg_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char srv_pkg__srv__SendImg_Request__FIELD_NAME__req[] = "req";

static rosidl_runtime_c__type_description__Field srv_pkg__srv__SendImg_Request__FIELDS[] = {
  {
    {srv_pkg__srv__SendImg_Request__FIELD_NAME__req, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
srv_pkg__srv__SendImg_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {srv_pkg__srv__SendImg_Request__TYPE_NAME, 27, 27},
      {srv_pkg__srv__SendImg_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char srv_pkg__srv__SendImg_Response__FIELD_NAME__img[] = "img";

static rosidl_runtime_c__type_description__Field srv_pkg__srv__SendImg_Response__FIELDS[] = {
  {
    {srv_pkg__srv__SendImg_Response__FIELD_NAME__img, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription srv_pkg__srv__SendImg_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
srv_pkg__srv__SendImg_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {srv_pkg__srv__SendImg_Response__TYPE_NAME, 28, 28},
      {srv_pkg__srv__SendImg_Response__FIELDS, 1, 1},
    },
    {srv_pkg__srv__SendImg_Response__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__Image__EXPECTED_HASH, sensor_msgs__msg__Image__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = sensor_msgs__msg__Image__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char srv_pkg__srv__SendImg_Event__FIELD_NAME__info[] = "info";
static char srv_pkg__srv__SendImg_Event__FIELD_NAME__request[] = "request";
static char srv_pkg__srv__SendImg_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field srv_pkg__srv__SendImg_Event__FIELDS[] = {
  {
    {srv_pkg__srv__SendImg_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {srv_pkg__srv__SendImg_Request__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {srv_pkg__srv__SendImg_Response__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription srv_pkg__srv__SendImg_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg_Request__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {srv_pkg__srv__SendImg_Response__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
srv_pkg__srv__SendImg_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {srv_pkg__srv__SendImg_Event__TYPE_NAME, 25, 25},
      {srv_pkg__srv__SendImg_Event__FIELDS, 3, 3},
    },
    {srv_pkg__srv__SendImg_Event__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__Image__EXPECTED_HASH, sensor_msgs__msg__Image__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = sensor_msgs__msg__Image__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = srv_pkg__srv__SendImg_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = srv_pkg__srv__SendImg_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool req\n"
  "---\n"
  "sensor_msgs/Image img";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
srv_pkg__srv__SendImg__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {srv_pkg__srv__SendImg__TYPE_NAME, 19, 19},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 34, 34},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
srv_pkg__srv__SendImg_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {srv_pkg__srv__SendImg_Request__TYPE_NAME, 27, 27},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
srv_pkg__srv__SendImg_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {srv_pkg__srv__SendImg_Response__TYPE_NAME, 28, 28},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
srv_pkg__srv__SendImg_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {srv_pkg__srv__SendImg_Event__TYPE_NAME, 25, 25},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
srv_pkg__srv__SendImg__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *srv_pkg__srv__SendImg__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *sensor_msgs__msg__Image__get_individual_type_description_source(NULL);
    sources[3] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[4] = *srv_pkg__srv__SendImg_Event__get_individual_type_description_source(NULL);
    sources[5] = *srv_pkg__srv__SendImg_Request__get_individual_type_description_source(NULL);
    sources[6] = *srv_pkg__srv__SendImg_Response__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
srv_pkg__srv__SendImg_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *srv_pkg__srv__SendImg_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
srv_pkg__srv__SendImg_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *srv_pkg__srv__SendImg_Response__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *sensor_msgs__msg__Image__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
srv_pkg__srv__SendImg_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *srv_pkg__srv__SendImg_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *sensor_msgs__msg__Image__get_individual_type_description_source(NULL);
    sources[3] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[4] = *srv_pkg__srv__SendImg_Request__get_individual_type_description_source(NULL);
    sources[5] = *srv_pkg__srv__SendImg_Response__get_individual_type_description_source(NULL);
    sources[6] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
