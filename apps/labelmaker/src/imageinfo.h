#pragma once
#ifndef _IMAGEINFO_H_889238
#define _IMAGEINFO_H_889238

class ImageInfo {
public:
    std::wstring file_name_;
    std::set<std::string> tags_;

public:
    ImageInfo();
    explicit ImageInfo(std::wstring file_name);
    explicit ImageInfo(const ProtoImageInfo& pinfo);

//    ProtoImageInfo serialize() const;
};

inline bool operator==(const ImageInfo& lhs, const ImageInfo& rhs) {
//    return std::tie(lhs.file_name_, lhs.tags_) == std::tie(rhs.file_name_, rhs.tags_);
    return lhs.file_name_ == rhs.file_name_;
}

inline bool operator<(const ImageInfo& lhs, const ImageInfo& rhs) {
    return lhs.file_name_ < rhs.file_name_;
}

inline bool operator>(const ImageInfo& lhs, const ImageInfo& rhs) {
    return rhs < lhs;
}

inline bool operator<=(const ImageInfo& lhs, const ImageInfo& rhs) {
    return !(lhs > rhs);
}

inline bool operator>=(const ImageInfo& lhs, const ImageInfo& rhs) {
    return !(lhs < rhs);
}

#endif
