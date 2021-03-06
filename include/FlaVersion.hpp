/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef FLA_VERSION_HPP
#define FLA_VERSION_HPP

#include <iostream>

#define FLASCRIPT_VERSION "0.3"
#define FLASCRIPT_STATE "beta-4"

#define Hyphen "-"

class FlaVersion {
public:
	static std::string Time();
	static std::string VersionAlgorithm();
};

#endif // FLA_VERSION_HPP
