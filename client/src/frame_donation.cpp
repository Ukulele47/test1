// This file is part of Mtp Target.
// Copyright (C) 2008 Vialek
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Vianney Lecroart - gpl@vialek.com


//
// Includes
//

#include "stdpch.h"

#include <nel/misc/md5.h>

#include <nel/net/callback_client.h>

//#include "web.h"
#include "3d_task.h"
#include "gui_task.h"
#include "time_task.h"
#include "game_task.h"
#include "gui_check.h"
#include "intro_task.h"
#include "mtp_target.h"
#include "login_client.h"
#include "font_manager.h"
#include "network_task.h"
#include "task_manager.h"
#include "background_task.h"
#include "config_file_task.h"
#include "../../common/async_job.h"


//
// Namespaces
//

using namespace NL3D;
using namespace NLMISC;
using namespace NLNET;


//
// Variables
//

static guiSPG<CGuiButton>		DonationDonateButton;


//
// Functions
//

void loadFrameDonation()
{
	guiSPG<CGuiXml> xml = CGuiObjectManager::instance().loadFrame("donation");

	if(FundGoal.empty())
	{
		((CGuiText*)xml->get("donationGoal"))->text(ucstring(""));
		((CGuiProgressBar*)xml->get("FundRaisedProgressBar"))->visible(false);
	}
	else
	{
		guiSPG<CGuiProgressBar> FundRaisedProgressBar = (CGuiProgressBar*)xml->get("FundRaisedProgressBar");
		FundRaisedProgressBar->percent(float(FundRaised)/100.0f);

		guiSPG<CGuiText> GuiDonationGoal = (CGuiText*)xml->get("donationGoalText");
		GuiDonationGoal->text(FundGoal);
	}

	string url("http://www.mtp-target.org/mt/mt_payment.php?language="+CI18N::getCurrentLanguageCode());
	((CGuiButton *)xml->get("bDonate"))->eventBehaviour = new CGuiOpenUrlButtonEventBehaviour(url);
}
