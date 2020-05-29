#include "pch.h"
#include "imageinfo.h"

ImageInfo::ImageInfo() {}

ImageInfo::ImageInfo(const ProtoImageInfo &pinfo):
    file_name_(pinfo.filename())  {

        for (int i = 0; i < pinfo.tag_size(); ++i) {
            tags_.insert(pinfo.tag(i));
        }
    }

ProtoImageInfo ImageInfo::serialize() const {
    ProtoImageInfo imginfo;
    imginfo.set_filename(file_name_);
    *imginfo.mutable_tag() = {tags_.cbegin(), tags_.cend()};

    return imginfo;
}

ImageInfo::ImageInfo(std::string file_name): file_name_(file_name) {
}
