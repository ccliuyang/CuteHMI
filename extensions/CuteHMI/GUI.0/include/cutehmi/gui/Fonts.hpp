#ifndef FONTS_HPP
#define FONTS_HPP

#include "internal/common.hpp"

#include <QObject>
#include <QFont>

namespace cutehmi {
namespace gui {

class CUTEHMI_GUI_API Fonts:
	public QObject
{
		Q_OBJECT

	public:
		Q_PROPERTY(QFont monospace READ monospace WRITE setMonospace NOTIFY monospaceChanged)

		Fonts(QObject * parent = nullptr);

		QFont monospace() const;

		void setMonospace(QFont monospace);

	signals:
		void monospaceChanged();

	private:
		struct Members {
			QFont monospace;
		};

		MPtr<Members> m;

};

}
}

#endif // FONTSET_HPP
