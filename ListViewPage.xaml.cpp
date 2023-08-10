// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "ListViewPage.xaml.h"
#if __has_include("ListViewPage.g.cpp")
#include "ListViewPage.g.cpp"
#endif
#if __has_include("GroupSection.g.cpp")
#include "GroupSection.g.cpp"
#endif
#if __has_include("ListItem.g.cpp")
#include "ListItem.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ListViewGroups::implementation
{
    ListViewPage::ListViewPage()
    {
        InitializeComponent();

        std::vector<winrt::ListViewGroups::ListItem> Group1;
        Group1.push_back(make<ListItem>(L"Item 1"));
        Group1.push_back(make<ListItem>(L"Item 2"));
        GroupSectionList.Append(make<GroupSection>(L"Group 1", std::move(Group1)));

        std::vector<winrt::ListViewGroups::ListItem> Group2;
        Group2.push_back(make<ListItem>(L"Item 3"));
        Group2.push_back(make<ListItem>(L"Item 4"));
        GroupSectionList.Append(make<GroupSection>(L"Group 2", std::move(Group2)));

        std::vector<winrt::ListViewGroups::ListItem> Group3;
        Group3.push_back(make<ListItem>(L"Item 5"));
        Group3.push_back(make<ListItem>(L"Item 6"));
        GroupSectionList.Append(make<GroupSection>(L"Group 3", std::move(Group3)));
    }

}
