#ifndef APYI_NONCOPYABLE_H
#define APYI_NONCOPYABLE_H

class UErNonCopyable {
public:
    UErNonCopyable() = default;
    ~UErNonCopyable() = default;
private:
    UErNonCopyable(const UErNonCopyable&) = delete;
    UErNonCopyable& operator=(const UErNonCopyable&) = delete;
};

#endif /* APYI_NONCOPYABLE_H */