/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once
#include <cstdint>
#include <CryptoNoteCore/Currency.h>

namespace CryptoNote {

class IUpgradeDetector {
public:
  enum : uint32_t {
    UNDEF_HEIGHT = static_cast<uint32_t>(-1)
  };

  virtual uint8_t targetVersion() const = 0;
  virtual uint32_t upgradeIndex() const = 0;
  virtual ~IUpgradeDetector() { }
};

std::unique_ptr<IUpgradeDetector> makeUpgradeDetector(uint8_t targetVersion, uint32_t upgradeIndex);

}
