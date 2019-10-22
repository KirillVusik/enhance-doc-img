
#ifndef MAKEBITONAL_EXPORT_H
#define MAKEBITONAL_EXPORT_H

#ifdef MAKEBITONAL_STATIC_DEFINE
#  define MAKEBITONAL_EXPORT
#  define MAKEBITONAL_NO_EXPORT
#else
#  ifndef MAKEBITONAL_EXPORT
#    ifdef makebitonal_EXPORTS
        /* We are building this library */
#      define MAKEBITONAL_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MAKEBITONAL_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MAKEBITONAL_NO_EXPORT
#    define MAKEBITONAL_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MAKEBITONAL_DEPRECATED
#  define MAKEBITONAL_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MAKEBITONAL_DEPRECATED_EXPORT
#  define MAKEBITONAL_DEPRECATED_EXPORT MAKEBITONAL_EXPORT MAKEBITONAL_DEPRECATED
#endif

#ifndef MAKEBITONAL_DEPRECATED_NO_EXPORT
#  define MAKEBITONAL_DEPRECATED_NO_EXPORT MAKEBITONAL_NO_EXPORT MAKEBITONAL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MAKEBITONAL_NO_DEPRECATED
#    define MAKEBITONAL_NO_DEPRECATED
#  endif
#endif

#endif
