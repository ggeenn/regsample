#pragma once
#include <vector>
#include <map>
#include <mutex>
#include <memory>
#include <future>
#include <iostream>
#include <iomanip>

#define CHECK_RET_ERR(var, func)       \
    auto var = func;                   \
    if(var)                            \
        throw std::runtime_error(std::string(__FUNCTION__) + " : "#func" fails, err=" + cmn::to_hex(var))

namespace cmn
{

template< typename T >
std::string to_hex(T i)
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(sizeof(T) * 2) << std::hex << (uint64_t)i;
    return stream.str();
}

template<class F>
class ScopedAction
{
    bool active_ = true;
    F f_;
public:
    ScopedAction(F f) : f_(f) {}
    void release() { active_ = false; }
    ~ScopedAction() { if (active_)f_(); }
};

template<class F>
ScopedAction<F> scopedAction(F f) { return ScopedAction<F>(f); }

std::vector<char> GetBinaryKey(const std::wstring& key, const std::wstring& name);
}