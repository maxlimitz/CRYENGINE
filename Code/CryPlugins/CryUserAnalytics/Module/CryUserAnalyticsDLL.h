// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <CrySystem/UserAnalytics/ICryUserAnalyticsPlugin.h>

class CUserAnalytics;

class CPlugin_CryUserAnalytics : public ICryUserAnalyticsPlugin
{
	CRYINTERFACE_BEGIN()
	CRYINTERFACE_ADD(ICryUserAnalyticsPlugin)
	CRYINTERFACE_ADD(ICryPlugin)
	CRYINTERFACE_END()

	CRYGENERATE_SINGLETONCLASS(CPlugin_CryUserAnalytics, "Plugin_CryUserAnalytics", 0x2284d2bf677c4e72, 0x8ace10f924bdd068)

	CPlugin_CryUserAnalytics();
	virtual ~CPlugin_CryUserAnalytics();

	//! Retrieve name of plugin.
	virtual const char* GetName() const override { return "CryUserAnalytics"; }

	//! Retrieve category for the plugin.
	virtual const char* GetCategory() const override { return "Plugin"; }

	//! This is called to initialize the new plugin.
	virtual bool Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams) override;

public:
	virtual IUserAnalytics* GetIUserAnalytics() const override;

protected:
	virtual void OnPluginUpdate(EPluginUpdateType updateType) override {}

private:
	CUserAnalytics* m_pUserAnalytics;
};
