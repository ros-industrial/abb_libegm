#ifndef ABB_LIBEGM__VISIBILITY_CONTROL_H_
#define ABB_LIBEGM__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ABB_LIBEGM_EXPORT __attribute__ ((dllexport))
    #define ABB_LIBEGM_IMPORT __attribute__ ((dllimport))
  #else
    #define ABB_LIBEGM_EXPORT __declspec(dllexport)
    #define ABB_LIBEGM_IMPORT __declspec(dllimport)
  #endif
  #ifdef ABB_LIBEGM_BUILDING_LIBRARY
    #define ABB_LIBEGM_PUBLIC ABB_LIBEGM_EXPORT
  #else
    #define ABB_LIBEGM_PUBLIC ABB_LIBEGM_IMPORT
  #endif
  #define ABB_LIBEGM_PUBLIC_TYPE ABB_LIBEGM_PUBLIC
  #define ABB_LIBEGM_LOCAL
#else
  #define ABB_LIBEGM_EXPORT __attribute__ ((visibility("default")))
  #define ABB_LIBEGM_IMPORT
  #if __GNUC__ >= 4
    #define ABB_LIBEGM_PUBLIC __attribute__ ((visibility("default")))
    #define ABB_LIBEGM_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ABB_LIBEGM_PUBLIC
    #define ABB_LIBEGM_LOCAL
  #endif
  #define ABB_LIBEGM_PUBLIC_TYPE
#endif

#endif  // ABB_LIBEGM__VISIBILITY_CONTROL_H_
