#pragma once

// This file needs to be used in both ProtoInputHooks and ProtoInputLoader for pipe communication

namespace ProtoPipe
{

enum class PipeMessageType
{
	SetupHook,
	WakeUpProcess,
	SetupMessageFilter
};

struct PipeMessageHeader
{
	PipeMessageType messageType;
	unsigned int messageSize;
};

struct PipeMessageSetupHook
{
	ProtoHookIDs hookID;
	bool install;
};

struct PipeMessageSetupMessageFilter
{
	ProtoMessageFilterIDs filterID;
	bool enable;
};

struct PipeMessageWakeUpProcess
{
};

}
