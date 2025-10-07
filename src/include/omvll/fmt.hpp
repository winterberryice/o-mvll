#pragma once

#include "llvm/ADT/StringRef.h"
#include "omvll/llvm-compat.hpp"
#include <spdlog/fmt/fmt.h>

template <> struct fmt::formatter<llvm::StringRef> {
  constexpr auto parse(format_parse_context &ctx) -> decltype(ctx.begin()) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const llvm::StringRef &Ref, FormatContext &ctx) const
      -> decltype(ctx.out()) {
    return fmt::format_to(ctx.out(), "{}", Ref.str());
  }
};

template <> struct fmt::formatter<llvm::Triple::ArchType> {
  constexpr auto parse(format_parse_context &ctx) -> decltype(ctx.begin()) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const llvm::Triple::ArchType &Arch, FormatContext &ctx) const
      -> decltype(ctx.out()) {
    return fmt::format_to(ctx.out(), "{}", llvm::Triple::getArchTypeName(Arch).str());
  }
};