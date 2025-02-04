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

#include "ConfigurationResource.h"

class Translation final : public ConfigurationResource
{
public:

    using Ptr = ReferenceCountedObjectPtr<Translation>;

    String getId() const noexcept;
    String getName() const noexcept;

    //===------------------------------------------------------------------===//
    // Serializable
    //===------------------------------------------------------------------===//

    SerializedData serialize() const override;
    void deserialize(const SerializedData &data) override;
    void reset() override;

    //===------------------------------------------------------------------===//
    // BaseResource
    //===------------------------------------------------------------------===//

    String getResourceId() const noexcept override;
    Identifier getResourceType() const noexcept override;

private:

    String id;
    String name;
    String pluralEquation;

    using SingularsMap = FlatHashMap<I18n::Key, String>;
    SingularsMap singulars;

    using Plurals = FlatHashMap<String, String, StringHash>;
    using PluralsMap = FlatHashMap<I18n::Key, UniquePointer<Plurals>>;
    PluralsMap plurals;

    friend class TranslationsCollection;

    JUCE_LEAK_DETECTOR(Translation)
};
