class UErNonCopyable {
public:
    UErNonCopyable() = default;
    ~UErNonCopyable() = default;
private:
    UErNonCopyable(const UErNonCopyable&) = delete;
    UErNonCopyable& operator=(const UErNonCopyable&) = delete;
};