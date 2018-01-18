#ifndef CUTEHMI_CUTEHMI__APP__1__LIB_INCLUDE_APP_INTERNAL_MACROS_HPP
#define CUTEHMI_CUTEHMI__APP__1__LIB_INCLUDE_APP_INTERNAL_MACROS_HPP

#include <utils/macros.hpp>

#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(cutehmi_app_1_lib_loggingCategory)

namespace cutehmi {
namespace app {

inline
const QLoggingCategory & loggingCategory()
{
	return cutehmi_app_1_lib_loggingCategory();
}

}
}

#endif

//(c)MP: Copyright © 2017, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
