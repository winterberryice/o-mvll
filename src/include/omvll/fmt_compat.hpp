#pragma once

#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Triple.h"
#include "spdlog/fmt/fmt.h"

template <>
struct fmt::formatter<llvm::StringRef> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const llvm::StringRef& p, FormatContext& ctx) {
    return fmt::format_to(ctx.out(), "{}", p.str());
  }
};

template <>
struct fmt::formatter<llvm::Triple::ArchType> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const llvm::Triple::ArchType& arch, FormatContext& ctx) {
    return fmt::format_to(ctx.out(), "{}", llvm::Triple::getArchTypeName(arch).str());
  }
};