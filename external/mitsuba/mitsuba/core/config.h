/* This file is automatically generated from "mitsuba.conf" using the script
   "resources/configure.py". Please do not attempt to change it manually,
   as any changes will be overwritten. The main purpose of this file is to
   helper various macros to instantiate multiple variants of Mitsuba. */

#pragma once

#include <mitsuba/core/fwd.h>

/// List of enabled Mitsuba variants
#define MTS_VARIANTS                                                            \
    "scalar_rgb\n"                                                              \
    "scalar_spectral\n"                                                         \

/// Default variant to be used by the "mitsuba" executable
#define MTS_DEFAULT_VARIANT "scalar_spectral"                                   \

/// Declare that a "struct" template is to be imported and not instantiated
#define MTS_EXTERN_STRUCT_CORE(Name)                                            \
    MTS_EXTERN_CORE template struct MTS_EXPORT_CORE Name<float, Color<float, 3>>; \
    MTS_EXTERN_CORE template struct MTS_EXPORT_CORE Name<float, Spectrum<float, 4>>; \

/// Declare that a "class" template is to be imported and not instantiated
#define MTS_EXTERN_CLASS_CORE(Name)                                             \
    MTS_EXTERN_CORE template class MTS_EXPORT_CORE Name<float, Color<float, 3>>; \
    MTS_EXTERN_CORE template class MTS_EXPORT_CORE Name<float, Spectrum<float, 4>>; \

/// Declare that a "struct" template is to be imported and not instantiated
#define MTS_EXTERN_STRUCT_RENDER(Name)                                          \
    MTS_EXTERN_RENDER template struct MTS_EXPORT_RENDER Name<float, Color<float, 3>>; \
    MTS_EXTERN_RENDER template struct MTS_EXPORT_RENDER Name<float, Spectrum<float, 4>>; \

/// Declare that a "class" template is to be imported and not instantiated
#define MTS_EXTERN_CLASS_RENDER(Name)                                           \
    MTS_EXTERN_RENDER template class MTS_EXPORT_RENDER Name<float, Color<float, 3>>; \
    MTS_EXTERN_RENDER template class MTS_EXPORT_RENDER Name<float, Spectrum<float, 4>>; \

/// Explicitly instantiate all variants of a "struct" template
#define MTS_INSTANTIATE_STRUCT(Name)                                            \
    template struct MTS_EXPORT Name<float, Color<float, 3>>;                    \
    template struct MTS_EXPORT Name<float, Spectrum<float, 4>>;                 \

/// Explicitly instantiate all variants of a "class" template
#define MTS_INSTANTIATE_CLASS(Name)                                             \
    template class MTS_EXPORT Name<float, Color<float, 3>>;                     \
    template class MTS_EXPORT Name<float, Spectrum<float, 4>>;                  \

/// Call the variant function "func" for a specific variant "variant"
#define MTS_INVOKE_VARIANT(variant, func, ...)                                  \
    [&]() {                                                                     \
        if (variant == "scalar_rgb")                                            \
            return func<float, Color<float, 3>>(__VA_ARGS__);                   \
        else if (variant == "scalar_spectral")                                  \
            return func<float, Spectrum<float, 4>>(__VA_ARGS__);                \
        else                                                                    \
            Throw("Unsupported variant: %s", variant);                          \
    }()                                                                         \

NAMESPACE_BEGIN(mitsuba)
NAMESPACE_BEGIN(detail)
/// Convert a <Float, Spectrum> type pair into one of the strings in MTS_VARIANT
template <typename Float_, typename Spectrum_> constexpr const char *get_variant() {
    if constexpr (std::is_same_v<Float_, float> &&
                  std::is_same_v<Spectrum_, Color<float, 3>>)
        return "scalar_rgb";
    else if constexpr (std::is_same_v<Float_, float> &&
                       std::is_same_v<Spectrum_, Spectrum<float, 4>>)
        return "scalar_spectral";
    else
        return "";
}
NAMESPACE_END(detail)
NAMESPACE_END(mitsuba)
