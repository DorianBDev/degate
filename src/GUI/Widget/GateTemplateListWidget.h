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

#ifndef __GATETEMPLATELISTWIDGET_H__
#define __GATETEMPLATELISTWIDGET_H__

#include "Core/Project/Project.h"

#include <QTableWidget>
#include <vector>

namespace degate
{
	/**
	 * @class GateTemplateListWidget
	 * @brief List all gates template of the logic model.
	 *
	 * @see QTableWidget
	 */
	class GateTemplateListWidget : public QTableWidget
	{
		Q_OBJECT
		
	public:

		/**
		 * Create a gate template list widget.
		 *
		 * @param project : the current active project.
		 * @param parent : the parent of the widget.
		 * @param unique_selection : if true allow only one selection at a time.
		 */
		GateTemplateListWidget(Project_shptr project, QWidget* parent, bool unique_selection = true);
		~GateTemplateListWidget();

		/**
		 * Get a vector of the selected gates template.
		 *
		 * @return Returns a vector of selected gates template (can return an empty vector).
		 */
		std::vector<GateTemplate_shptr> get_selected_gates();

		/**
		 * Get the first selected gate template.
		 *
		 * @return Returns the first selected gate template.
		 */
		GateTemplate_shptr get_selected_gate();

		/**
		 * Know if there an active selection.
		 *
		 * @return Returns true if at least one gate is selected.
		 */
		bool has_selection();

	public slots:
		/**
		 * Update the gate template list.
		 */
		void update_list();

	private:
		Project_shptr project;
		
	};
}

#endif