#pragma once

#include <WinUser.h>

enum class AppMessages {
	WM_BARCODE_DATA_CHANGED = WM_APP + 1,
	WM_APP_LAST,
};
