#include <CL/sycl.hpp>
#include <sstream>
#include <stdexcept>
#include <ze_api.h>

#define ZE_CHECK(...)                                                          \
  do {                                                                         \
    ze_result_t res = __VA_ARGS__;                                             \
    if (res != ZE_RESULT_SUCCESS) {                                            \
      std::stringstream ss;                                                    \
      ss << __FILE__ << ":" << __LINE__ << ": Level Zero error code " << res;   \
      throw std::runtime_error(ss.str());                                      \
    }                                                                          \
  } while (0)

int main() {
  ZE_CHECK(zeInit(0));
  ze_driver_handle_t ze_driver;
  uint32_t ze_driver_count = 1;
  ZE_CHECK(zeDriverGet(&ze_driver_count, &ze_driver));
  ze_device_handle_t ze_device;
  uint32_t ze_device_count = 1;
  ZE_CHECK(zeDeviceGet(ze_driver, &ze_device_count, &ze_device));
  cl::sycl::device sycl_device =
      cl::sycl::make_device<cl::sycl::backend::ext_oneapi_level_zero>(
          cl::sycl::backend_input_t<cl::sycl::backend::ext_oneapi_level_zero,
                                    cl::sycl::device>(ze_device));
  return 0;
}
