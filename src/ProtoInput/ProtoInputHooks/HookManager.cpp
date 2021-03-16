#include "HookManager.h"
#include "RegisterRawInputHook.h"
#include "GetRawInputDataHook.h"
#include "MessageFilterHook.h"
#include "FocusHook.h"

namespace Proto
{

HookManager HookManager::hookManagerInstance{};

HookManager::HookManager()
{
	AddHook<MessageBoxHook>(ProtoHookIDs::MessageBoxHookID);
	AddHook<RegisterRawInputHook>(ProtoHookIDs::RegisterRawInputHookID);
	AddHook<GetRawInputDataHook>(ProtoHookIDs::GetRawInputDataHookID);
	AddHook<MessageFilterHook>(ProtoHookIDs::MessageFilterHookID);
	AddHook<FocusHook>(ProtoHookIDs::FocusHooksHookID);
}

void HookManager::InstallHook(ProtoHookIDs hookID)
{
	if (hookID < 0 || hookID >= hookManagerInstance.hooks.size())
		std::cerr << "Trying to install hook ID " << hookID << " which is out of range" << std::endl;
	else
	{
		hookManagerInstance.hooks[hookID]->Install();
	}
}

void HookManager::UninstallHook(ProtoHookIDs hookID)
{
	if (hookID < 0 || hookID >= hookManagerInstance.hooks.size())
		std::cerr << "Trying to uninstall hook ID " << hookID << " which is out of range" << std::endl;
	else
	{
		hookManagerInstance.hooks[hookID]->Uninstall();
	}
}

bool HookManager::IsInstalled(ProtoHookIDs hookID)
{
	if (hookID < 0 || hookID >= hookManagerInstance.hooks.size())
	{
		std::cerr << "Trying to check hook ID " << hookID << " which is out of range" << std::endl;
		return false;
	}
	else
	{
		return hookManagerInstance.hooks[hookID]->IsInstalled();
	}
}

}
