#pragma once
#include <cstddef>
#include <string>

class Resource {
public:
    Resource(const char* start, const size_t len) : resource_data(start), data_len(len) {}

    const char* const& data() const { return resource_data; }
    const size_t& size() const { return data_len; }

    const char* begin() const { return resource_data; }
    const char* end() const { return resource_data + data_len; }

    std::string toString() const { return std::string(data(), size()); }

private:
    const char* resource_data;
    const size_t data_len;

};

#define DEFINE_RESOURCE(RESOURCE) extern const char _resource_##RESOURCE[]; extern const size_t _resource_##RESOURCE##_len
#define LOAD_RESOURCE(RESOURCE) ([]() { \
        /*DEFINE_RESOURCE(RESOURCE);*/  \
        return Resource(_resource_##RESOURCE, _resource_##RESOURCE##_len); \
    })()

DEFINE_RESOURCE(Resources_glsl_1D_frag_glsl);
DEFINE_RESOURCE(Resources_glsl_1D_vert_glsl);
DEFINE_RESOURCE(Resources_glsl_1D_white_vert_glsl);