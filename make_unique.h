#if __cplusplus >= 201402L
    #include <memory>
#else
    #ifndef MAKE_UNIQUE
    #define MAKE_UNIQUE
    namespace std{
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
    }

    #endif
#endif
