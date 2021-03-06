#include "pch.h"
#include "imageinfo.h"
#include "utility.h"

ImageInfo::ImageInfo() {}

ImageInfo::ImageInfo(const ProtoImageInfo& pinfo):
    file_name_(lm::utility::strings::bytes_to_wstr(pinfo.filename()))  {

        for (int i = 0; i < pinfo.tags_size(); ++i) {
            const ProtoTag& tag = pinfo.tags(i);
            tags_.insert(tag.tag_name());
        }
    }

//ProtoImageInfo ImageInfo::serialize() const {
//    ProtoImageInfo imginfo;
//    imginfo.set_filename(file_name_);
//    *imginfo.mutable_tag() = {tags_.cbegin(), tags_.cend()};
//
//    return imginfo;
//}

ImageInfo::ImageInfo(std::wstring file_name): file_name_(file_name) {
}

