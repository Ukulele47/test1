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

#ifndef MT_WATER_TASK_H
#define MT_WATER_TASK_H


//
// Externs
//

namespace NL3D
{
	class UScene;
	class UInstance;
	class UCloudScape;
	class CWaterShape;
	class CWaterModel;
}


//
// Classes
//

class CWaterTask : public NLMISC::CSingleton<CWaterTask>, public ITask
{
public:

	virtual void init();
	virtual void update();
	virtual void render();
	virtual void release();

	virtual string name() const { return "CWaterTask"; }

	void setWater(const string &name);	// sun or snow

private:

	CWaterTask();

	NL3D::CWaterShape		*WaterShape;
	NL3D::CWaterModel		*WaterModel;
	NL3D::UInstance			WaterMesh;	
	NL3D::CTransformShape   *WaterInstance;

	friend void cbVar (NLMISC::CConfigFile::CVar &var);
	friend class NLMISC::CSingleton<CWaterTask>;
};

#endif
