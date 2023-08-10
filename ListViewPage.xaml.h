// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "ListViewPage.g.h"
#include "GroupSection.g.h"
#include "ListItem.g.h"

namespace winrt::ListViewGroups::implementation
{
    struct ListViewPage : ListViewPageT<ListViewPage>
    {
        ListViewPage();

        Windows::Foundation::Collections::IObservableVector<winrt::ListViewGroups::GroupSection> MyGroups()
        {
            return GroupSectionList;
        }
    private:
        Windows::Foundation::Collections::IObservableVector<winrt::ListViewGroups::GroupSection> GroupSectionList{ winrt::single_threaded_observable_vector<winrt::ListViewGroups::GroupSection>() };
    };

    struct GroupSection
        : GroupSectionT<GroupSection>
    {
        GroupSection() = default;
        GroupSection(hstring key, std::vector<winrt::ListViewGroups::ListItem>&& items)
        {
            InternalKey = key;
            ListItemList = winrt::single_threaded_observable_vector<winrt::ListViewGroups::ListItem>(std::move(items));
        }

        hstring Key()
        {
            return InternalKey;
        }

        Windows::Foundation::Collections::IObservableVector<winrt::ListViewGroups::ListItem> MyItems()
        {
            return ListItemList;
        }

    private:
        hstring InternalKey;
        Windows::Foundation::Collections::IObservableVector<winrt::ListViewGroups::ListItem> ListItemList{nullptr};
    };

    struct ListItem : ListItemT<ListItem>
    {
        ListItem() = default;
        ListItem(hstring name)
        {
            InternalName = name;
        }

        hstring Name()
        {
            return InternalName;
        }

    private:
        hstring InternalName;
    };
}

namespace winrt::ListViewGroups::factory_implementation
{
    struct ListViewPage : ListViewPageT<ListViewPage, implementation::ListViewPage>
    {
    };

    struct GroupSection : GroupSectionT<GroupSection, implementation::GroupSection>
    {
    };

    struct ListItem : ListItemT<ListItem, implementation::ListItem>
    {
    };

}
