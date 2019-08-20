#ifndef H_EXTENSIONS_CUTEHMI_SERVICES_2_INCLUDE_CUTEHMI_SERVICES_INTERNAL_PLATFORM_HPP
#define H_EXTENSIONS_CUTEHMI_SERVICES_2_INCLUDE_CUTEHMI_SERVICES_INTERNAL_PLATFORM_HPP

// This file has been autogenerated by 'ExtensionSkeleton.qbs'.

#include <QtGlobal>

#ifdef CUTEHMI_SERVICES_DYNAMIC
	#ifdef CUTEHMI_SERVICES_BUILD
		// Export symbols to dynamic library.
		#define CUTEHMI_SERVICES_API Q_DECL_EXPORT
		#ifdef CUTEHMI_SERVICES_TESTS
			// Export symbols to dynamic library.
			#define CUTEHMI_SERVICES_PRIVATE Q_DECL_EXPORT
		#else
			#define CUTEHMI_SERVICES_PRIVATE
		#endif
	#else
		// Using symbols from dynamic library.
		#define CUTEHMI_SERVICES_API Q_DECL_IMPORT
		#ifdef CUTEHMI_SERVICES_TESTS
			// Using symbols from dynamic library.
			#define CUTEHMI_SERVICES_PRIVATE Q_DECL_IMPORT
		#else
			#define CUTEHMI_SERVICES_PRIVATE
		#endif
	#endif
#else
	#define CUTEHMI_SERVICES_API
	#define CUTEHMI_SERVICES_PRIVATE
#endif

#endif