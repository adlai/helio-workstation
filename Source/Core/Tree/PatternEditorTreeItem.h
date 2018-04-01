/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "TreeItem.h"

class PatternEditorTreeItem final : public TreeItem
{
public:

    PatternEditorTreeItem();

    String getName() const noexcept override;
    Colour getColour() const noexcept override;
    Image getIcon() const noexcept override;

    void showPage() override;
    void recreatePage() override;

    String getStatsString() const;

    //===------------------------------------------------------------------===//
    // Dragging
    //===------------------------------------------------------------------===//

    void onItemParentChanged() override {}
    var getDragSourceDescription() override { return var::null; }
    bool isInterestedInDragSource(const DragAndDropTarget::SourceDetails &dragSourceDetails) override
    { return false; }

    //===------------------------------------------------------------------===//
    // Menu
    //===------------------------------------------------------------------===//

    bool hasMenu() const noexcept override;
    ScopedPointer<Component> createMenu() override;

};
