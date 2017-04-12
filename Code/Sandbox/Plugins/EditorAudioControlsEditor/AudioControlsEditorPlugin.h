// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IEditor.h>
#include <IPlugin.h>
#include "AudioAssetsManager.h"
#include "AudioAssetsExplorerModel.h"
#include <IAudioSystemEditor.h>
#include <CryAudio/IAudioInterfacesCommonData.h>
#include <CrySandbox/CrySignal.h>

namespace CryAudio
{
struct IObject;
}

class CImplementationManager;

//------------------------------------------------------------------
class CAudioControlsEditorPlugin : public IPlugin, public ISystemEventListener
{
public:
	explicit CAudioControlsEditorPlugin();
	~CAudioControlsEditorPlugin();

	int32                            GetPluginVersion() override     { return 1; }
	const char*                      GetPluginName() override        { return "Audio Controls Editor"; }
	const char*                      GetPluginDescription() override { return "The Audio Controls Editor enables browsing and configuring audio events exposed from the audio middleware"; }

	static void                      SaveModels();
	static void                      ReloadModels(bool bReloadImplementation);
	static void                      ReloadScopes();
	static ACE::CAudioAssetsManager* GetAssetsManager();
	static CImplementationManager*   GetImplementationManger();
	static ACE::IAudioSystemEditor*  GetAudioSystemEditorImpl();
	static void                      ExecuteTrigger(const string& sTriggerName);
	static void                      StopTriggerExecution();
	static uint                      GetLoadingErrorMask() { return s_loadingErrorMask; }

	static CCrySignal<void()> signalAboutToLoad;
	static CCrySignal<void()> signalLoaded;

private:
	///////////////////////////////////////////////////////////////////////////
	// ISystemEventListener
	virtual void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam);
	///////////////////////////////////////////////////////////////////////////

	static ACE::CAudioAssetsManager s_pAssetsManager;
	static std::set<string>         s_currentFilenames;
	static CryAudio::IObject*       s_pIAudioObject;
	static CryAudio::ControlId      s_audioTriggerId;

	static CImplementationManager   s_implementationManager;
	static uint                     s_loadingErrorMask;
};
