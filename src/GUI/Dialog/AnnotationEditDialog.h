/* -*-c++-*-

  This file is part of the IC reverse engineering tool degate.

  Copyright 2008, 2009, 2010 by Martin Schobert

  Degate is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  any later version.

  Degate is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with degate. If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __ANNOTATIONEDITDIALOG__
#define __ANNOTATIONEDITDIALOG__

#include "Core/Project/Project.h"
#include "ColorPickerDialog.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

namespace degate
{

	/**
	 * @class AnnotationEditDialog
	 * @brief Dialog to edit an annotation.
	 *
	 * @see QDialog
	 */
	class AnnotationEditDialog : public QDialog
	{
		Q_OBJECT
		
	public:

		/**
		 * Create the dialog, to show it call the exec function.
		 *
		 * @param annotation : the annotation to edit.
		 * @param parent : the parent of the dialog.
		 *
		 * @see QDialog
		 */
		AnnotationEditDialog(Annotation_shptr annotation, QWidget* parent);
		~AnnotationEditDialog();

	public slots:

		/**
		 * Save all changes and close the dialog.
		 */
		void validate();

	private:
		QGridLayout layout;
		Annotation_shptr annotation;
		
		QLabel text_label;
		QLineEdit text;
		QLabel fill_color_label;
		ColorSelectionButton fill_color;
		QLabel frame_color_label;
		ColorSelectionButton frame_color;
		QPushButton validate_button;
		QPushButton cancel_button;
		
	};
}

#endif