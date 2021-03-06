/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SYSTEM_INFO_HPP
#define SYSTEM_INFO_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <sys/utsname.h>
#include <chrono>

#ifndef __FreeBSD__
	#include <sys/sysinfo.h>
#endif

// Libraries 
#include "Colorized.hpp"
#include "FileSystemPlusPlus.h"

#define FETCHEYA_VERSION "0.2"
#define FETCHEYA_STATUS "beta-1"

using namespace std; // Sorry...

static std::string ftime(__TIME__); // Convert

class systemInfo {
public:
	string EraseAllSubString(string & mainString, const string & erase) {
   	 size_t pos = string::npos;
   	 while((pos = mainString.find(erase)) != string::npos) {
   	     	mainString.erase(pos, erase.length());
   	 }
   		return mainString;
    	}

	static void getOS() {
		fsplusplus::ReadFilePath("/etc/os-release"); 
	}
	
	static void getCPU() {
		fsplusplus::ReadCPU();
	}

	static void Test16bitColours() {
		colorized::PrintWith(colorized::Colorize(BOLD, BLACK).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, GREEN).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, YELLOW).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, MAGENTA).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, CYAN).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GRAY).c_str(), "███\n");
		colorized::PrintWith(colorized::Colorize(BOLD, DARK_GRAY).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "███");
		colorized::PrintWith(colorized::Colorize(BOLD, WHITE).c_str(), "███");	
	}

	static string getSystem() {
		struct utsname buf;
		if(!uname(&buf)) { //Get name and information about current kernel.
			//printf("%s\n",buf.sysname);//Display the system name.
			return buf.sysname;
		} else {
			perror("uname");
			return "?";
		}
	}
	
	static string getHostname() {
		struct utsname sysinfo;
		uname(&sysinfo);
		return sysinfo.nodename;
	}
	static string getUsername() {
		string username = getenv("USER");
		return username;
	}
	int getUserHostLength() {
		hostnameLength = getHostname().length();
		usernameLength = getUsername().length();
		UserHostLength = usernameLength + hostnameLength;
		return UserHostLength;
	}
	string getDevice() {
		ifstream device;
		filename = "/sys/devices/virtual/dmi/id/product_family";
		device.open(filename);
		if(device.good()){
			getline(device, deviceName);
		}
		device.close();
		return deviceName;
	}
	string getUptime() {
		#ifdef __FreeBSD__ 
		return "null";
		#else
		struct sysinfo info;
		sysinfo(&info);
		uptime = info.uptime;
		if(uptime/60 >= 60) {
			uptimeHour = (uptime/60)/60;
			uptimeHourWhole = uptimeHour;
			uptimeMinutes = uptimeHour - uptimeHourWhole;
			uptimeMinutesWhole = uptimeMinutes * 60;
			if(uptimeHour >= 24) {
				uptimeDay = uptimeHour/24;
				uptimeDayWhole = uptimeDay;
				uptimeHour = uptimeDay - uptimeDayWhole;
				uptimeHour = uptimeHour * 24;
				uptimeHourWhole = uptimeHour;
				uptimeStream << uptimeDayWhole << "d " << uptimeHourWhole << "h " << uptimeMinutesWhole << "m";
			}
			else {
				uptimeStream << uptimeHourWhole << "h " << uptimeMinutesWhole << "m";
			}
		}
		else {
			uptimeMinutes = uptime/60;
			uptimeMinutesWhole = uptimeMinutes;
			uptimeStream << uptimeMinutesWhole << "m";
		}
		uptimeString = uptimeStream.str();
		return uptimeString;
		#endif
	}
	string getShell() {
		shell = getenv("SHELL");
		shell.erase(0,5);
		return shell;
	}
	string getTerm() {
		terminal = getenv("TERM");
		return terminal;
	}
	string getKernel() {
		struct utsname sysinfo;
		uname(&sysinfo);
		kernelVersion = sysinfo.release;
		return kernelVersion;
	}
	string getArch() {
		struct utsname sysinfo;
		uname(&sysinfo);
		architecture = sysinfo.machine;
		return architecture;
	}
	string getEditor() {
		editor = getenv("EDITOR");
		return editor;
	}
	string getVisual() {
		visual = getenv("VISUAL");
		return visual;
	}
private:
	string distroLine, filename, hostname, deviceName,
		uptimeString, shell, terminal, kernelVersion, architecture,
		editor, visual, lineOne;
	double uptime, uptimeMinutes, uptimeHour, uptimeDay;
	int initialUptime, uptimeMinutesWhole, uptimeHourWhole, uptimeDayWhole, usernameLength,
		hostnameLength, UserHostLength;
	stringstream uptimeStream;
};

#endif // SYSTEM_INFO_HPP
