#include "brainfuck-module.h"

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);
    auto& runtime = BrainfuckRuntime::Instance();
    core->RegisterScriptRuntime("bf", &runtime);
    Log::Colored << "Loaded Brainfuck module. Version ~y~v" BF_MODULE_VERSION << Log::Endl;

    return true;
}

EXPORT uint32_t GetSDKVersion()
{
	return alt::ICore::SDK_VERSION;
}
