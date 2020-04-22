#pragma once

#include <exception>

class nonTriunghiulara : public std::exception
{
public:
    nonTriunghiulara() noexcept {}
    nonTriunghiulara(const nonTriunghiulara&) noexcept = default;
    nonTriunghiulara& operator= (const nonTriunghiulara&) noexcept = default;
    virtual ~nonTriunghiulara() noexcept = default;
    virtual const char* what() const noexcept {
        return "nonTriunghiulara";
    }
};

class dimensiuniDiferite : public std::exception
{
public:
    dimensiuniDiferite() noexcept {}
    dimensiuniDiferite(const dimensiuniDiferite&) noexcept = default;
    dimensiuniDiferite& operator= (const dimensiuniDiferite&) noexcept = default;
    virtual ~dimensiuniDiferite() noexcept = default;
    virtual const char* what() const noexcept {
        return "dimensiuniDiferite";
    }
};