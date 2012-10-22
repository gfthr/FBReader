/*
 * Copyright (C) 2009-2010 Geometer Plus <contact@geometerplus.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __OPDSCATALOGITEM_H__
#define __OPDSCATALOGITEM_H__

#include <ZLExecutionUtil.h>

#include "../NetworkItems.h"
#include "../NetworkOperationData.h"

class OPDSLink;

class OPDSCatalogItem : public NetworkCatalogItem {

public:
	OPDSCatalogItem(
		const OPDSLink &link,
		const std::string &title,
		const std::string &summary,
		const UrlInfoCollection &urlByType,
		AccessibilityType accessibility = AlWAYS,
		int flags = FLAGS_DEFAULT
	);

public:
	std::string loadChildren(NetworkItem::List &children, shared_ptr<ZLNetworkRequest::Listener> listener);
	void onLoadedChildren(ZLExecutionScope &scope, std::string error);

private:
	NetworkOperationData myData;
};

#endif /* __OPDSCATALOGITEM_H__ */
